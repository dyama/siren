using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

using System.Diagnostics;

namespace siren
{
    public delegate void change_state_func();

    public partial class term : UserControl
    {
        protected sirenenv.Viewer myViewer;
        protected change_state_func _func;
        protected MainForm mf;

        protected string previous_path = "";

        public string result_string;

        public bool use_p = true;

        private System.Collections.Generic.Queue<string> history;

        public term()
        {
            InitializeComponent();
            result_string = string.Empty;
            this.history = new Queue<string>();
            _func = null;
            Scroll2Last(rtb);
            tb.Focus();
        }

        public void set(sirenenv.Viewer Viewer, MainForm mainform)
        {
            myViewer = Viewer;
            mf = mainform;
            return;
        }

        public void setFocus()
        {
            tb.Focus();
        }

        /// <summary>
        /// Scroll RichTextBox to last line
        /// </summary>
        /// <param name="rtb"></param>
        private void Scroll2Last(TextBox rtb)
        {
            rtb.SelectionStart = rtb.TextLength;
            rtb.Focus();
            rtb.ScrollToCaret();
        }

        public int execute(string cmd)
        {
            return execute(cmd, null, true, true);
        }

        public int execute(string cmd, Control focus)
        {
            return execute(cmd, focus, true, true);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="cmd"></param>
        public int execute(string cmd, Control focus, bool echo, bool use_func)
        {
            if (System.Text.RegularExpressions.Regex.IsMatch(cmd, @"^\s*$"))
                return -1;

            string errmsg;
            string result = "";
            string prompt = "$ ";

            // Selected object(s)
            cmd = cmd.Replace("??", "selected");
            cmd = cmd.Replace("?", "selected[0]");

            string cmd2 = Regex.Replace(cmd, @"^\s+|\s+$", "");
            if (Regex.IsMatch(cmd2, @"sleep\s+\d+")) {
                string cmd3 = Regex.Replace(cmd2, @"sleep\s+", "");
                int foo;
                if (!int.TryParse(cmd3, out foo)) {
                    throw new Exception();
                }
                System.Threading.Thread.Sleep(foo);
                Application.DoEvents();
                return 0;
            }

            //double sec;
            //Stopwatch sw = new Stopwatch();
            //sw.Start();
            int err = myViewer.mruby_exec(cmd, out errmsg);
            //sw.Stop();
            //sec = (double)sw.ElapsedTicks / (double)Stopwatch.Frequency;
            //Console.WriteLine(sec);

            if (!myViewer.mruby_isCodeBlockOpen())
                result += (err == 0) ? p() : errmsg;
            else
                prompt = "* ";

            result_string = result;

            if (echo) {
                rtb.Text += prompt + cmd + "\r\n" + result.Replace("\n", "\r\n");
                this.Scroll2Last(rtb);
                if (focus == null)
                    tb.Focus();
                else
                    focus.Focus();
            }

            if (use_func && _func != null)
                _func();

            return err;
        }

        public string p()
        {
            if (use_p)
                return myViewer.mruby_p();
            else
                return "";
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="cmd"></param>
        /// <param name="dialog_message"></param>
        /// <returns></returns>
        public int execute(string cmd, string dialog_message)
        {
            int err = execute(cmd, null, true, false);
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

        /// <summary>
        /// コマンドの実行処理
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void run()
        {
            List<string> cmdlines = new List<string>(Regex.Split(tb.Text, @"\n", RegexOptions.Multiline));

            while (cmdlines.Count > 0) {
                string line = cmdlines[0];
                if (!Regex.IsMatch(line, @"^\s*$")) {
                    if (this.execute(line, tb, true, false) != 0) {
                        break;
                    }
                }
                cmdlines.RemoveAt(0);

                tb.Text = string.Join("\n", cmdlines.ToArray());
                Application.DoEvents();
            }

            if (_func != null)
                _func();

            if (cmdlines.Count == 0)
                tb.Text = string.Empty;

            return;
        }

        private void tb_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode) {
            case Keys.Enter:
                if (e.Modifiers != Keys.Shift) {
                    run();
                    e.SuppressKeyPress = true;
                }
                break;
            case Keys.Up:
                e.SuppressKeyPress = true;
                break;
            case Keys.Down:
                e.SuppressKeyPress = true;
                break;
            case Keys.Escape:
                mf.focusViewer();
                break;
            default:
                break;
            }
        }

        private void tsbClear_Click(object sender, EventArgs e)
        {
            tb.Clear();
        }

        private void tsbRun_Click(object sender, EventArgs e)
        {
            run();
        }

        private void tsbOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog d = new OpenFileDialog();
            d.Filter = "siren スクリプトファイル(*.rb)|*.rb|すべてのファイル(*.*)|*.*";
            d.RestoreDirectory = true;
            d.Multiselect = false;
            if (d.ShowDialog() != DialogResult.OK) {
                return;
            }
            this.previous_path = d.FileName;

            StreamReader sr = new StreamReader(this.previous_path, Encoding.UTF8);
            tb.Text = sr.ReadToEnd();
            sr.Close();
        }

        private void tsbRelaod_Click(object sender, EventArgs e)
        {
            if (File.Exists(this.previous_path)) {
                StreamReader sr = new StreamReader(this.previous_path, Encoding.UTF8);
                tb.Text = sr.ReadToEnd();
                sr.Close();
            }
        }


    }
}
