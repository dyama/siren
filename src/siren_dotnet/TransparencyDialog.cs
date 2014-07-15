/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
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
  public class TransparencyDialog : System.Windows.Forms.Form
  {
    private System.Windows.Forms.NumericUpDown MyTransparency;
    private System.ComponentModel.Container components = null;
    public term t;

    public TransparencyDialog()
    {
      InitializeComponent();
    }

    protected override void Dispose(bool disposing)
    {
      if (disposing) {
        if (components != null) {
          components.Dispose();
        }
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
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
      this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "TransparencyDialog";
      this.ShowIcon = false;
      this.ShowInTaskbar = false;
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
      this.Text = "“§–¾“x";
      ((System.ComponentModel.ISupportInitialize)(this.MyTransparency)).EndInit();
      this.ResumeLayout(false);

    }
    #endregion

    private void MyTransparency_ValueChanged(object sender, System.EventArgs e)
    {
      double transp = ((double)this.MyTransparency.Value) / 10;
      t.execute("selected.each { do |id| transparency id, " + transp.ToString() + " }");
    }

  }
}
