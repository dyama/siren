namespace siren
{
    partial class term
    {
        /// <summary> 
        /// 必要なデザイナ変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region コンポーネント デザイナで生成されたコード

        /// <summary> 
        /// デザイナ サポートに必要なメソッドです。このメソッドの内容を 
        /// コード エディタで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.rtb = new System.Windows.Forms.RichTextBox();
            this.sc = new System.Windows.Forms.SplitContainer();
            this.sc.Panel2.SuspendLayout();
            this.sc.SuspendLayout();
            this.SuspendLayout();
            // 
            // rtb
            // 
            this.rtb.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.rtb.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.rtb.DetectUrls = false;
            this.rtb.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rtb.Font = new System.Drawing.Font("ＭＳ ゴシック", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.rtb.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.rtb.ImeMode = System.Windows.Forms.ImeMode.Disable;
            this.rtb.Location = new System.Drawing.Point(0, 0);
            this.rtb.Name = "rtb";
            this.rtb.ShortcutsEnabled = false;
            this.rtb.Size = new System.Drawing.Size(237, 50);
            this.rtb.TabIndex = 0;
            this.rtb.Text = "";
            this.rtb.KeyDown += new System.Windows.Forms.KeyEventHandler(this.rtb_KeyDown);
            // 
            // sc
            // 
            this.sc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.sc.FixedPanel = System.Windows.Forms.FixedPanel.Panel1;
            this.sc.IsSplitterFixed = true;
            this.sc.Location = new System.Drawing.Point(1, 1);
            this.sc.Name = "sc";
            this.sc.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // sc.Panel1
            // 
            this.sc.Panel1.BackColor = System.Drawing.Color.Silver;
            this.sc.Panel1MinSize = 10;
            // 
            // sc.Panel2
            // 
            this.sc.Panel2.Controls.Add(this.rtb);
            this.sc.Size = new System.Drawing.Size(237, 61);
            this.sc.SplitterDistance = 10;
            this.sc.SplitterWidth = 1;
            this.sc.TabIndex = 1;
            // 
            // term
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.Controls.Add(this.sc);
            this.Name = "term";
            this.Padding = new System.Windows.Forms.Padding(1, 1, 2, 2);
            this.Size = new System.Drawing.Size(240, 64);
            this.sc.Panel2.ResumeLayout(false);
            this.sc.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RichTextBox rtb;
        private System.Windows.Forms.SplitContainer sc;
    }
}
