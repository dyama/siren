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
            string cmd = rtb.Lines[rtb.Lines.ToArray().Length - 1];

            if (cmd.IndexOf(this.prompt_string, 0) == 0) {
                cmd = cmd.Replace(this.prompt_string, "");
            }
            if (cmd.IndexOf(this.subprompt_string, 0) == 0) {
                cmd = cmd.Replace(this.subprompt_string, "");
            }
            return cmd;
        }

        /// <summary>
        /// Scroll RichTextBox to last line
        /// </summary>
        /// <param name="rtb"></param>
        private void Scroll2Last(RichTextBox rtb)
        {
            rtb.SelectionStart = rtb.TextLength;
            rtb.Focus();
            rtb.ScrollToCaret();
        }

        /// <summary>
        /// Return prompt string
        /// </summary>
        /// <returns></returns>
        private string getPrompt()
        {
            return myViewer.mruby_isCodeBlockOpen() ? this.subprompt_string : this.prompt_string;
        }

        /// <summary>
        /// Execute command interface for another instance
        /// </summary>
        /// <param name="cmd"></param>
        /// <returns></returns>
        public int execute(string cmd)
        {
            rtb.Text += cmd;
            KeyDown_Enter(rtb);
            return 0;
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
            string errmsg;
            err = myViewer.mruby_exec(cmd, out errmsg);

            string result = "";
            if (!myViewer.mruby_isCodeBlockOpen()) {
                if (err == 0) {
                    result += myViewer.mruby_p();
                }
                else {
                    result += errmsg + "\n";
                }
            }
            rtb.Text += "\n" + result + getPrompt();
            this.Scroll2Last(rtb);
        }

    }
}
