using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using sirenenv;

namespace siren
{
	public class TransparencyDialog : System.Windows.Forms.Form
	{
		private System.Windows.Forms.NumericUpDown MyTransparency;
		private System.ComponentModel.Container components = null;
        private Viewer myViewer;
        
		public TransparencyDialog()
		{
			InitializeComponent();
			myViewer = null;
		}

		protected override void Dispose( bool disposing )
		{
			if( disposing ) {
				if(components != null) {
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TransparencyDialog));
            this.MyTransparency = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.MyTransparency)).BeginInit();
            this.SuspendLayout();
            // 
            // MyTransparency
            // 
            this.MyTransparency.Location = new System.Drawing.Point(16, 15);
            this.MyTransparency.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.MyTransparency.Name = "MyTransparency";
            this.MyTransparency.Size = new System.Drawing.Size(96, 19);
            this.MyTransparency.TabIndex = 0;
            this.MyTransparency.ValueChanged += new System.EventHandler(this.MyTransparency_ValueChanged);
            // 
            // TransparencyDialog
            // 
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
            this.ClientSize = new System.Drawing.Size(128, 53);
            this.Controls.Add(this.MyTransparency);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "TransparencyDialog";
            this.Text = "“§–¾“x";
            ((System.ComponentModel.ISupportInitialize)(this.MyTransparency)).EndInit();
            this.ResumeLayout(false);

		}
		#endregion

		private void MyTransparency_ValueChanged(object sender, System.EventArgs e)
		{
			if (this.myViewer==null)
				return;
			int transp = (int)this.MyTransparency.Value;
			this.myViewer.SetTransparency(transp);
		}

		public Viewer Viewer
		{
			set { this.myViewer=value; }
		}

	}
}
