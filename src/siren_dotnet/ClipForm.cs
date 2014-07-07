using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace siren
{
  public partial class ClipForm : Form
  {
    double x_min, x_max;
    double y_min, y_max;
    double z_min, z_max;
    term t;

    public ClipForm(term aterm)
    {
      this.StartPosition = FormStartPosition.CenterParent;

      InitializeComponent();

      t = aterm;

      x_min = -10 * 10;
      x_max = 32 * 10;
      y_min = -10 * 10;
      y_max = 10 * 10;
      z_min = -10 * 10;
      z_max = 10 * 10;

      return;
    }

    private void ClipForm_Load(object sender, EventArgs e)
    {
      InitBars();
    }

    public void InitBars()
    {
      tb_xmin.Minimum = (int)x_min;
      tb_xmin.Maximum = (int)x_max;
      tb_xmin.Value = tb_xmin.Minimum;
      tb_xmax.Minimum = (int)x_min;
      tb_xmax.Maximum = (int)x_max;
      tb_xmax.Value = tb_xmax.Maximum;

      tb_ymin.Minimum = (int)y_min;
      tb_ymin.Maximum = (int)y_max;
      tb_ymin.Value = tb_ymin.Minimum;
      tb_ymax.Minimum = (int)y_min;
      tb_ymax.Maximum = (int)y_max;
      tb_ymax.Value = tb_ymax.Maximum;

      tb_zmin.Minimum = (int)z_min;
      tb_zmin.Maximum = (int)z_max;
      tb_zmin.Value = tb_zmin.Minimum;
      tb_zmax.Minimum = (int)z_min;
      tb_zmax.Maximum = (int)z_max;
      tb_zmax.Value = tb_zmax.Maximum;

      return;
    }

    private void tb_xmin_Scroll(object sender, EventArgs e)
    {
      double val = (double)((TrackBar)sender).Value;
      string cap = cb_usecap.Checked ? "true" : "false";
      t.execute("clipon 100, [" + val.ToString() + ", 0, 0], [1, 0, 0], " + cap);
    }

    private void tb_xmax_Scroll(object sender, EventArgs e)
    {
      double val = (double)((TrackBar)sender).Value;
      string cap = cb_usecap.Checked ? "true" : "false";
      t.execute("clipon 101, [" + val.ToString() + ", 0, 0], [-1, 0, 0], " + cap);
    }

    private void tb_ymin_Scroll(object sender, EventArgs e)
    {
      double val = (double)((TrackBar)sender).Value;
      string cap = cb_usecap.Checked ? "true" : "false";
      t.execute("clipon 200, [0, " + val.ToString() + ", 0], [0, 1, 0], " + cap);
    }

    private void tb_ymax_Scroll(object sender, EventArgs e)
    {
      double val = (double)((TrackBar)sender).Value;
      string cap = cb_usecap.Checked ? "true" : "false";
      t.execute("clipon 201, [0, " + val.ToString() + ", 0], [0, -1, 0], " + cap);
    }

    private void tb_zmin_Scroll(object sender, EventArgs e)
    {
      double val = (double)((TrackBar)sender).Value;
      string cap = cb_usecap.Checked ? "true" : "false";
      t.execute("clipon 300, [0, 0, " + val.ToString() + "], [0, 0, 1], " + cap);
    }

    private void tb_zmax_Scroll(object sender, EventArgs e)
    {
      double val = (double)((TrackBar)sender).Value;
      string cap = cb_usecap.Checked ? "true" : "false";
      t.execute("clipon 301, [0, 0, " + val.ToString() + "], [0, 0, -1], " + cap);
    }

    private void ClipForm_FormClosed(object sender, FormClosedEventArgs e)
    {
      t.execute("[100, 101, 200, 201, 300, 301].each { |i| clipoff i }");
    }

    private void btOk_Click(object sender, EventArgs e)
    {
      Close();
    }


  }
}
