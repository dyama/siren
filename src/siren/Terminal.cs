using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace siren
{
    public partial class Terminal : Form
    {
        protected sirenenv.Viewer myViewer;

        public string prompt_string = "$ ";
        public string subprompt_string = "* ";

        public Terminal(sirenenv.Viewer Viewer)
        {
            InitializeComponent();

            myViewer = Viewer;
            rtb.Text = prompt_string;
            Scroll2Last(rtb);
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
            case Keys.Up:
                e.SuppressKeyPress = true;
                break;
            case Keys.Down:
                e.SuppressKeyPress = true;
                break;
            case Keys.Left:

            case Keys.Right:
            default:

                break;
            }
        }

        private string getCurLine(RichTextBox rtb)
        {
            int line = rtb.GetLineFromCharIndex(rtb.SelectionStart);
            string cmd = rtb.Lines[line];
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
            //try {
                err = myViewer.mruby_exec(cmd);
                string result = "";
                if (!myViewer.mruby_isCodeBlockOpen()) {
                    if (err == 0) {
                        result = myViewer.mruby_p();
                    }
                    else {
                        result = "Error:" + err.ToString("X") + "\n";
                    }
                }
                rtb.Text += "\n" + result + getPrompt();
                rtb.Select(rtb.TextLength - getPrompt().Length, getPrompt().Length);
                rtb.SelectionColor = Color.LightGreen;
            //}
            //catch (Exception exp) {
            //    MessageBox.Show(exp.Message);
            //    err = -1;
            //}
        }

    }
}
