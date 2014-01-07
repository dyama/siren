/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

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
		//private System.ComponentModel.IContainer components;

		#region Windows Form Designer generated code
		private void InitializeComponent()
		{
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ViewForm));
            this.SuspendLayout();
            // 
            // ViewForm
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
            this.ClientSize = new System.Drawing.Size(464, 322);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ViewForm";
            this.Text = "ビューア";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.onMouseWheel);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.onMouseUp);
            this.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.onMouseDoubleClick);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.ViewForm_Paint);
            this.SizeChanged += new System.EventHandler(this.ViewForm_SizeChanged);
            this.Closed += new System.EventHandler(this.onClosed);
            this.MouseEnter += new System.EventHandler(this.onMouseEnter);
            this.Click += new System.EventHandler(this.ViewForm_Click);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.onMouseDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.onKeyUp);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.onMouseMove);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.onKeyDown);
            this.ResumeLayout(false);

		}

		#endregion

    }
}
