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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(term));
            this.sc = new System.Windows.Forms.SplitContainer();
            this.rtb = new System.Windows.Forms.TextBox();
            this.tb = new System.Windows.Forms.TextBox();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.tsbClear = new System.Windows.Forms.ToolStripButton();
            this.tsbOpen = new System.Windows.Forms.ToolStripButton();
            this.tsbRelaod = new System.Windows.Forms.ToolStripButton();
            this.tsbRun = new System.Windows.Forms.ToolStripButton();
            this.sc.Panel1.SuspendLayout();
            this.sc.Panel2.SuspendLayout();
            this.sc.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // sc
            // 
            this.sc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.sc.Location = new System.Drawing.Point(33, 1);
            this.sc.Margin = new System.Windows.Forms.Padding(0);
            this.sc.Name = "sc";
            this.sc.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // sc.Panel1
            // 
            this.sc.Panel1.BackColor = System.Drawing.Color.Silver;
            this.sc.Panel1.Controls.Add(this.rtb);
            this.sc.Panel1MinSize = 10;
            // 
            // sc.Panel2
            // 
            this.sc.Panel2.Controls.Add(this.tb);
            this.sc.Panel2MinSize = 10;
            this.sc.Size = new System.Drawing.Size(585, 238);
            this.sc.SplitterDistance = 147;
            this.sc.TabIndex = 1;
            // 
            // rtb
            // 
            this.rtb.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rtb.Font = new System.Drawing.Font("ＭＳ ゴシック", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.rtb.Location = new System.Drawing.Point(0, 0);
            this.rtb.Multiline = true;
            this.rtb.Name = "rtb";
            this.rtb.ReadOnly = true;
            this.rtb.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.rtb.Size = new System.Drawing.Size(585, 147);
            this.rtb.TabIndex = 1;
            this.rtb.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tb_KeyDown);
            // 
            // tb
            // 
            this.tb.AcceptsTab = true;
            this.tb.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tb.Font = new System.Drawing.Font("ＭＳ ゴシック", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.tb.Location = new System.Drawing.Point(0, 0);
            this.tb.MaxLength = 327670;
            this.tb.Multiline = true;
            this.tb.Name = "tb";
            this.tb.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.tb.Size = new System.Drawing.Size(585, 87);
            this.tb.TabIndex = 0;
            this.tb.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tb_KeyDown);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Dock = System.Windows.Forms.DockStyle.Left;
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbClear,
            this.tsbOpen,
            this.tsbRelaod,
            this.tsbRun});
            this.toolStrip1.Location = new System.Drawing.Point(1, 1);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(32, 238);
            this.toolStrip1.TabIndex = 1;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // tsbClear
            // 
            this.tsbClear.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbClear.Image = ((System.Drawing.Image)(resources.GetObject("tsbClear.Image")));
            this.tsbClear.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbClear.Name = "tsbClear";
            this.tsbClear.Size = new System.Drawing.Size(29, 20);
            this.tsbClear.Text = "クリア";
            this.tsbClear.Click += new System.EventHandler(this.tsbClear_Click);
            // 
            // tsbOpen
            // 
            this.tsbOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbOpen.Image = ((System.Drawing.Image)(resources.GetObject("tsbOpen.Image")));
            this.tsbOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbOpen.Name = "tsbOpen";
            this.tsbOpen.Size = new System.Drawing.Size(29, 20);
            this.tsbOpen.Text = "スクリプトを開く";
            this.tsbOpen.Click += new System.EventHandler(this.tsbOpen_Click);
            // 
            // tsbRelaod
            // 
            this.tsbRelaod.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbRelaod.Image = ((System.Drawing.Image)(resources.GetObject("tsbRelaod.Image")));
            this.tsbRelaod.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbRelaod.Name = "tsbRelaod";
            this.tsbRelaod.Size = new System.Drawing.Size(29, 20);
            this.tsbRelaod.Text = "再読み込み";
            this.tsbRelaod.Click += new System.EventHandler(this.tsbRelaod_Click);
            // 
            // tsbRun
            // 
            this.tsbRun.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbRun.Image = ((System.Drawing.Image)(resources.GetObject("tsbRun.Image")));
            this.tsbRun.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbRun.Name = "tsbRun";
            this.tsbRun.Size = new System.Drawing.Size(29, 20);
            this.tsbRun.Text = "実行";
            this.tsbRun.Click += new System.EventHandler(this.tsbRun_Click);
            // 
            // term
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGray;
            this.Controls.Add(this.sc);
            this.Controls.Add(this.toolStrip1);
            this.Name = "term";
            this.Padding = new System.Windows.Forms.Padding(1, 1, 2, 2);
            this.Size = new System.Drawing.Size(620, 241);
            this.sc.Panel1.ResumeLayout(false);
            this.sc.Panel1.PerformLayout();
            this.sc.Panel2.ResumeLayout(false);
            this.sc.Panel2.PerformLayout();
            this.sc.ResumeLayout(false);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.SplitContainer sc;
        private System.Windows.Forms.TextBox rtb;
        private System.Windows.Forms.TextBox tb;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton tsbClear;
        private System.Windows.Forms.ToolStripButton tsbOpen;
        private System.Windows.Forms.ToolStripButton tsbRelaod;
        private System.Windows.Forms.ToolStripButton tsbRun;
    }
}
