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
    public partial class ViewForm : System.Windows.Forms.UserControl
    {
		//private System.ComponentModel.IContainer components;

		#region Windows Form Designer generated code
		private void InitializeComponent()
		{
            this.SuspendLayout();
            // 
            // ViewForm
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Window;
            this.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.DoubleBuffered = true;
            this.Name = "ViewForm";
            this.Size = new System.Drawing.Size(462, 320);
            this.MouseWheel += new System.Windows.Forms.MouseEventHandler(this.onMouseWheel);
            this.MouseLeave += new System.EventHandler(this.onMouseLeave);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.ViewForm_Paint);
            this.Click += new System.EventHandler(this.ViewForm_Click);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.onMouseMove);
            this.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.onMouseDoubleClick);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.onKeyUp);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.onMouseDown);
            this.MouseHover += new System.EventHandler(this.onMouseHover);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.onMouseUp);
            this.SizeChanged += new System.EventHandler(this.ViewForm_SizeChanged);
            this.MouseEnter += new System.EventHandler(this.onMouseEnter);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.onKeyDown);
            this.ResumeLayout(false);

		}

		#endregion


    }
}
