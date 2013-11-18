using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace siren
{
    public partial class term : UserControl
    {
        protected sirenenv.Viewer myViewer;

        public string prompt_string = "$ ";
        public string subprompt_string = "* ";

        public term(sirenenv.Viewer Viewer)
        {
            InitializeComponent();

            myViewer = Viewer;
            rtb.Text = prompt_string;
            Scroll2Last(rtb);
            rtb.Focus();
        }

        public void setFocus()
        {
            rtb.Focus();
        }

        private void rtb_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode) {
            case Keys.Enter:
                KeyDown_Enter((RichTextBox)sender);
                e.SuppressKeyPress = true;
                Scroll2Last(rtb);
                break;
            case Keys.Back:
                if (getCurLine(rtb).Length == 0)
                    e.SuppressKeyPress = true;
                break;
            case Keys.Escape:
                this.Visible = false;
                this.Parent.Parent.Focus();
                break;
            case Keys.F5:
                source("E:/test.rb");
                break;
            case Keys.Up:
                e.SuppressKeyPress = true;
                break;
            case Keys.Down:
                e.SuppressKeyPress = true;
                break;
            case Keys.Left:
                break;
            case Keys.Right:
                break;
            default:

                break;
            }
        }

        private string getCurLine(RichTextBox rtb)
        {
#if false
            int line = rtb.GetLineFromCharIndex(rtb.SelectionStart);
            string cmd = rtb.Lines[line];
#else
            string cmd = rtb.Lines[rtb.Lines.ToArray().Length - 1];
#endif
            if (cmd.IndexOf(this.prompt_string, 0) == 0) {
                cmd = cmd.Replace(this.prompt_string, "");
            }
            if (cmd.IndexOf(this.subprompt_string, 0) == 0) {
                cmd = cmd.Replace(this.subprompt_string, "");
            }
            return cmd;
        }

        private void Scroll2Last(RichTextBox rtb)
        {
            rtb.SelectionStart = rtb.TextLength;
            rtb.Focus();
            rtb.ScrollToCaret();
        }

        private string getPrompt()
        {
            return myViewer.mruby_isCodeBlockOpen() ? this.subprompt_string : this.prompt_string;
        }

        private void KeyDown_Enter(RichTextBox rtb)
        {
            string cmd = getCurLine(rtb);
            if (cmd.Length == 0 || cmd == "\n") {
                rtb.Text += "\n" + getPrompt();
                Scroll2Last(rtb);
                return;
            }
            int err = 0;
#if false
            System.Diagnostics.Stopwatch sw = new System.Diagnostics.Stopwatch();
            sw.Reset(); sw.Start();
#endif
            err = myViewer.mruby_exec(cmd);
#if false
            sw.Stop();
            string result = "Time:" + sw.Elapsed.ToString() + "\n";
#else
            string result = "";
#endif
            if (!myViewer.mruby_isCodeBlockOpen()) {
                if (err == 0) {
                    result += myViewer.mruby_p();
                }
                else {
                    result += "Error:" + err.ToString("X") + "\n";
                }
            }
            rtb.Text += "\n" + result + getPrompt();
            rtb.Select(rtb.TextLength - getPrompt().Length, getPrompt().Length);
            rtb.SelectionColor = Color.LightGreen;
        }

        /// <summary>
        /// sourceコマンド(デバッグのための実装)
        /// </summary>
        /// <param name="path"></param>
        private void source(string path)
        {
            System.IO.StreamReader cReader = ( new System.IO.StreamReader(path, System.Text.Encoding.Default) );
            string stResult = string.Empty;
            while (cReader.Peek() >= 0) {
                rtb.Text += cReader.ReadLine();
                KeyDown_Enter(rtb);
            }
            cReader.Close();
        }

    }
}
