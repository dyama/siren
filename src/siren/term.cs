﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace siren
{
    public delegate void change_state_func();

    public partial class term : UserControl
    {
        protected sirenenv.Viewer myViewer;
        protected change_state_func _func;

        public string result_string;

        public term(sirenenv.Viewer Viewer)
        {
            InitializeComponent();
            result_string = string.Empty;
            _func = null;
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

        /// <summary>
        /// 
        /// </summary>
        /// <param name="cmd"></param>
        public int execute(string cmd)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(cmd, @"^\s*$"))
                return -1;

            string errmsg;
            string result = "";
            string prompt = "$ ";

            // Selected object(s)
            cmd = cmd.Replace("??", "selected");
            cmd = cmd.Replace("?", "selected[0]");

            int err = myViewer.mruby_exec(cmd, out errmsg);

            if (!myViewer.mruby_isCodeBlockOpen())
                result += (err == 0) ? myViewer.mruby_p() : errmsg;
            else
                prompt = "* ";

            result_string = result;

            rtb.Text += prompt + cmd + "\n" + result;
            this.Scroll2Last(rtb);
            tb.Focus();

            if (_func != null)
                _func();

            return err;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="cmd"></param>
        /// <param name="dialog_message"></param>
        /// <returns></returns>
        public int execute(string cmd, string dialog_message)
        {
            int err = execute(cmd);
            if (err == 0)
                MessageBox.Show(dialog_message + result_string, "成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            else
                MessageBox.Show(dialog_message + result_string, "失敗", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            return err;
        }

        /// <summary>
        /// 状態変更用コールバック関数を定義
        /// </summary>
        /// <param name="func"></param>
        public void setChangeStateFunc(change_state_func func)
        {
            this._func = func;
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
                if (e.Modifiers != Keys.Shift) {
                    foreach (string line in Regex.Split(tb.Text, @"\n", RegexOptions.Multiline))
                        this.execute(line);
                    tb.Text = "";
                    e.SuppressKeyPress = true;
                }
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
