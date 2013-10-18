using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using sirenenv;

namespace siren
{
    public partial class ViewForm : System.Windows.Forms.Form
    {
		private System.ComponentModel.IContainer components;


		#region Windows Form Designer generated code
		private void InitializeComponent()
		{
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ViewForm));
            this.cont = new System.Windows.Forms.ToolStripContainer();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.tsbFit = new System.Windows.Forms.ToolStripButton();
            this.tsbBookmark = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbAxoView = new System.Windows.Forms.ToolStripButton();
            this.tsbFrontView = new System.Windows.Forms.ToolStripButton();
            this.tsbBackView = new System.Windows.Forms.ToolStripButton();
            this.tsbLeftView = new System.Windows.Forms.ToolStripButton();
            this.tsbRightView = new System.Windows.Forms.ToolStripButton();
            this.tsbTopView = new System.Windows.Forms.ToolStripButton();
            this.tsbBottomView = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbResetView = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbShading = new System.Windows.Forms.ToolStripButton();
            this.tsbHlr = new System.Windows.Forms.ToolStripButton();
            this.cont.TopToolStripPanel.SuspendLayout();
            this.cont.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // cont
            // 
            // 
            // cont.ContentPanel
            // 
            this.cont.ContentPanel.Size = new System.Drawing.Size(464, 297);
            this.cont.ContentPanel.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.onMouseWheel);
            this.cont.ContentPanel.Paint += new System.Windows.Forms.PaintEventHandler(this.ViewForm_Paint);
            this.cont.ContentPanel.MouseMove += new System.Windows.Forms.MouseEventHandler(this.onMouseMove);
            this.cont.ContentPanel.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.onMouseDoubleClick);
            this.cont.ContentPanel.MouseDown += new System.Windows.Forms.MouseEventHandler(this.onMouseDown);
            this.cont.ContentPanel.MouseUp += new System.Windows.Forms.MouseEventHandler(this.onMouseUp);
            this.cont.ContentPanel.SizeChanged += new System.EventHandler(this.ViewForm_SizeChanged);
            this.cont.ContentPanel.MouseEnter += new System.EventHandler(this.onMouseEnter);
            this.cont.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cont.Location = new System.Drawing.Point(0, 0);
            this.cont.Name = "cont";
            this.cont.Size = new System.Drawing.Size(464, 322);
            this.cont.TabIndex = 0;
            this.cont.Text = "toolStripContainer1";
            // 
            // cont.TopToolStripPanel
            // 
            this.cont.TopToolStripPanel.Controls.Add(this.toolStrip1);
            this.cont.KeyUp += new System.Windows.Forms.KeyEventHandler(this.onKeyUp);
            this.cont.KeyDown += new System.Windows.Forms.KeyEventHandler(this.onKeyDown);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Dock = System.Windows.Forms.DockStyle.None;
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbFit,
            this.tsbBookmark,
            this.toolStripSeparator2,
            this.tsbAxoView,
            this.tsbFrontView,
            this.tsbBackView,
            this.tsbLeftView,
            this.tsbRightView,
            this.tsbTopView,
            this.tsbBottomView,
            this.toolStripSeparator3,
            this.tsbResetView,
            this.toolStripSeparator1,
            this.tsbShading,
            this.tsbHlr});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(464, 25);
            this.toolStrip1.Stretch = true;
            this.toolStrip1.TabIndex = 0;
            // 
            // tsbFit
            // 
            this.tsbFit.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbFit.Image = ((System.Drawing.Image)(resources.GetObject("tsbFit.Image")));
            this.tsbFit.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbFit.Name = "tsbFit";
            this.tsbFit.Size = new System.Drawing.Size(23, 22);
            this.tsbFit.Text = "フィット";
            this.tsbFit.Click += new System.EventHandler(this.tsbFit_Click);
            // 
            // tsbBookmark
            // 
            this.tsbBookmark.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBookmark.Enabled = false;
            this.tsbBookmark.Image = ((System.Drawing.Image)(resources.GetObject("tsbBookmark.Image")));
            this.tsbBookmark.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBookmark.Name = "tsbBookmark";
            this.tsbBookmark.Size = new System.Drawing.Size(32, 22);
            this.tsbBookmark.Text = "toolStripButton11";
            this.tsbBookmark.ToolTipText = "ブックマーク";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbAxoView
            // 
            this.tsbAxoView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbAxoView.Image = ((System.Drawing.Image)(resources.GetObject("tsbAxoView.Image")));
            this.tsbAxoView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbAxoView.Name = "tsbAxoView";
            this.tsbAxoView.Size = new System.Drawing.Size(23, 22);
            this.tsbAxoView.Text = "toolStripButton10";
            this.tsbAxoView.ToolTipText = "ふかん";
            this.tsbAxoView.Click += new System.EventHandler(this.tsbAxoView_Click);
            // 
            // tsbFrontView
            // 
            this.tsbFrontView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbFrontView.Image = ((System.Drawing.Image)(resources.GetObject("tsbFrontView.Image")));
            this.tsbFrontView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbFrontView.Name = "tsbFrontView";
            this.tsbFrontView.Size = new System.Drawing.Size(23, 22);
            this.tsbFrontView.Text = "toolStripButton9";
            this.tsbFrontView.ToolTipText = "正面";
            this.tsbFrontView.Click += new System.EventHandler(this.tsbFrontView_Click);
            // 
            // tsbBackView
            // 
            this.tsbBackView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBackView.Image = ((System.Drawing.Image)(resources.GetObject("tsbBackView.Image")));
            this.tsbBackView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBackView.Name = "tsbBackView";
            this.tsbBackView.Size = new System.Drawing.Size(23, 22);
            this.tsbBackView.Text = "toolStripButton8";
            this.tsbBackView.ToolTipText = "背面";
            this.tsbBackView.Click += new System.EventHandler(this.tsbBackView_Click);
            // 
            // tsbLeftView
            // 
            this.tsbLeftView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbLeftView.Image = ((System.Drawing.Image)(resources.GetObject("tsbLeftView.Image")));
            this.tsbLeftView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbLeftView.Name = "tsbLeftView";
            this.tsbLeftView.Size = new System.Drawing.Size(23, 22);
            this.tsbLeftView.Text = "toolStripButton4";
            this.tsbLeftView.ToolTipText = "左側面";
            this.tsbLeftView.Click += new System.EventHandler(this.tsbLeftView_Click);
            // 
            // tsbRightView
            // 
            this.tsbRightView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbRightView.Image = ((System.Drawing.Image)(resources.GetObject("tsbRightView.Image")));
            this.tsbRightView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbRightView.Name = "tsbRightView";
            this.tsbRightView.Size = new System.Drawing.Size(23, 22);
            this.tsbRightView.Text = "toolStripButton3";
            this.tsbRightView.ToolTipText = "右側面";
            this.tsbRightView.Click += new System.EventHandler(this.tsbRightView_Click);
            // 
            // tsbTopView
            // 
            this.tsbTopView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTopView.Image = ((System.Drawing.Image)(resources.GetObject("tsbTopView.Image")));
            this.tsbTopView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTopView.Name = "tsbTopView";
            this.tsbTopView.Size = new System.Drawing.Size(23, 22);
            this.tsbTopView.Text = "toolStripButton2";
            this.tsbTopView.ToolTipText = "上面";
            this.tsbTopView.Click += new System.EventHandler(this.tsbTopView_Click);
            // 
            // tsbBottomView
            // 
            this.tsbBottomView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBottomView.Image = ((System.Drawing.Image)(resources.GetObject("tsbBottomView.Image")));
            this.tsbBottomView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBottomView.Name = "tsbBottomView";
            this.tsbBottomView.Size = new System.Drawing.Size(23, 22);
            this.tsbBottomView.Text = "toolStripButton1";
            this.tsbBottomView.ToolTipText = "下面";
            this.tsbBottomView.Click += new System.EventHandler(this.tsbBottomView_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbResetView
            // 
            this.tsbResetView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbResetView.Image = ((System.Drawing.Image)(resources.GetObject("tsbResetView.Image")));
            this.tsbResetView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbResetView.Name = "tsbResetView";
            this.tsbResetView.Size = new System.Drawing.Size(23, 22);
            this.tsbResetView.Text = "ビューをリセット";
            this.tsbResetView.Click += new System.EventHandler(this.tsbResetView_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbShading
            // 
            this.tsbShading.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbShading.Image = ((System.Drawing.Image)(resources.GetObject("tsbShading.Image")));
            this.tsbShading.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbShading.Name = "tsbShading";
            this.tsbShading.Size = new System.Drawing.Size(23, 22);
            this.tsbShading.Text = "シェーディング";
            this.tsbShading.ToolTipText = "シェーディング";
            this.tsbShading.Click += new System.EventHandler(this.tsbShading_Click);
            // 
            // tsbHlr
            // 
            this.tsbHlr.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHlr.Image = ((System.Drawing.Image)(resources.GetObject("tsbHlr.Image")));
            this.tsbHlr.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHlr.Name = "tsbHlr";
            this.tsbHlr.Size = new System.Drawing.Size(23, 22);
            this.tsbHlr.Text = "隠面消去";
            this.tsbHlr.ToolTipText = "隠面消去";
            this.tsbHlr.Click += new System.EventHandler(this.tsbHlr_Click);
            // 
            // ViewForm
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
            this.ClientSize = new System.Drawing.Size(464, 322);
            this.Controls.Add(this.cont);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ViewForm";
            this.Text = "ビューア";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Closed += new System.EventHandler(this.onClosed);
            this.cont.TopToolStripPanel.ResumeLayout(false);
            this.cont.TopToolStripPanel.PerformLayout();
            this.cont.ResumeLayout(false);
            this.cont.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);

		}
		#endregion

        private ToolStrip toolStrip1;
        private ToolStripButton tsbShading;
        private ToolStripButton tsbFit;
        private ToolStripButton tsbAxoView;
        private ToolStripButton tsbFrontView;
        private ToolStripButton tsbBackView;
        private ToolStripButton tsbResetView;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripSplitButton tsbBookmark;
        private ToolStripSeparator toolStripSeparator2;
        private ToolStripSeparator toolStripSeparator3;
        public ToolStripContainer cont;
        private ToolStripButton tsbLeftView;
        private ToolStripButton tsbRightView;
        private ToolStripButton tsbTopView;
        private ToolStripButton tsbBottomView;
        private ToolStripButton tsbHlr;
    }
}
