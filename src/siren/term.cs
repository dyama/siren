using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Text.RegularExpressions;
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
            Scroll2Last(rtb);
            tb.Focus();
        }

        public void setFocus()
        {
            tb.Focus();
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

        public void execute(string cmd)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(cmd, @"^\s*$"))
                return;
            int err = 0;
            string errmsg;
            err = myViewer.mruby_exec(cmd, out errmsg);
            string result = "";
            string prompt = "$ ";
            if (!myViewer.mruby_isCodeBlockOpen()) {
                if (err == 0) {
                    result += myViewer.mruby_p();
                }
                else {
                    result += errmsg + "\n";
                }
            }
            else {
                prompt = "* ";
            }
            rtb.Text += prompt + cmd + "\n" + result;
            this.Scroll2Last(rtb);
            tb.Focus();
        }

        private void tb_KeyDown(object sender, KeyEventArgs e)
        {
            // rtb
            if (sender.Equals(rtb)) {
                if (e.KeyCode == Keys.Escape) {
                    this.Visible = false;
                    this.Parent.Parent.Focus();
                }
            }
            // tb
            switch (e.KeyCode) {
            case Keys.Enter:
                foreach (string line in Regex.Split(tb.Text, @"\n", RegexOptions.Multiline))
                    this.execute(line);
                tb.Text = "";
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
            default:
                break;
            }
        }

    }
}
