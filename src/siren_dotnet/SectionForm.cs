using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace siren
{

  public partial class SectionForm : Form
  {
    double x_min, x_max;
    double y_min, y_max;
    double z_min, z_max;

    double thickness = 0.5; // m

    protected term t;

    public SectionForm(term Terminal)
    {
      InitializeComponent();
      t = Terminal;

      x_min = -6.5;
      x_max = 324.5;
      y_min = -31;
      y_max = 31;
      z_min = -1;
      z_max = 31;

      trackBar1.Minimum = (int)x_min;
      trackBar1.Maximum = (int)x_max;
      trackBar1.Value = (int)((trackBar1.Maximum - trackBar1.Minimum) / 2);

      trackBar2.Minimum = (int)y_min;
      trackBar2.Maximum = (int)y_max;
      trackBar2.Value = 0;

      trackBar3.Minimum = (int)z_min;
      trackBar3.Maximum = (int)z_max;
      trackBar3.Value = (int)((trackBar3.Maximum - trackBar3.Minimum) / 2);
    }

    private void SectionForm_FormClosed(object sender, FormClosedEventArgs e)
    {
      t.execute("[111, 210, 211, 310, 311].each { |i| clipoff i }");
      t.execute("clipon 110, [-10, 0, 0], [-1, 0, 0], false, __sec_id");
      t.execute("update;");
    }

    private void SectionForm_Shown(object sender, EventArgs e)
    {
      t.execute("__sec_id = comp", null, true, false);
      trackBar1_Scroll(null, null);
    }

    private void update_x(double val)
    {
      t.execute(
        "__bu_drw = $DRAW; $DRAW = false;" +
        "clipon 110, [" + (val - thickness / 2).ToString() + ", 0, 0], [1, 0, 0], false, __sec_id;" +
        "clipon 111, [" + (val + thickness / 2).ToString() + ", 0, 0], [-1, 0, 0], false, __sec_id;" +
        "$DRAW = __bu_drw;" +
        "update",
        null, false, false);
    }

    private void trackBar1_MouseUp(object sender, MouseEventArgs e)
    {
      double xpos = (double)trackBar1.Value;
      t.execute("[pdf1[0], pdf2[0], pdf3[0]]", null, false, false);
      Regex re = new System.Text.RegularExpressions.Regex(@"[\d\.\-]+");
      MatchCollection ma = re.Matches(t.result_string);

      int fit = 0;

      double pdfpos = double.Parse(ma[0].Value);
      if (Math.Abs(pdfpos - xpos) < 6) {
        trackBar1.Value = (int)pdfpos;
        fit = 6;
      }

      pdfpos = double.Parse(ma[1].Value);
      if (Math.Abs(pdfpos - xpos) < 6) {
        trackBar1.Value = (int)pdfpos;
        fit = 7;
      }

      pdfpos = double.Parse(ma[2].Value);
      if (Math.Abs(pdfpos - xpos) < 6) {
        trackBar1.Value = (int)pdfpos;
        fit = 9;
      }

      update_x((double)trackBar1.Value);

      if (fit > 0) {
        DialogResult dr = MessageBox.Show("関連付けされたドキュメントを開きますか？", "確認", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
        if (dr == DialogResult.Yes)
          System.Diagnostics.Process.Start("C:/tmp/" + fit.ToString() + ".pdf");
      }
    }

    private void trackBar1_Scroll(object sender, EventArgs e)
    {
      update_x((double)trackBar1.Value);
    }

    private void trackBar2_Scroll(object sender, EventArgs e)
    {
      double val = (double)trackBar2.Value;
      t.execute(
        "__bu_drw = $DRAW; $DRAW = false;" +
        "clipon 210, [0, " + (val - thickness / 2).ToString() + ", 0], [0, 1, 0], false, __sec_id;" +
        "clipon 211, [0, " + (val + thickness / 2).ToString() + ", 0], [0, -1, 0], false, __sec_id;" +
        "$DRAW = __bu_drw;" +
        "update",
        null, false, false);
    }

    private void trackBar3_Scroll(object sender, EventArgs e)
    {
      double val = (double)trackBar3.Value;
      t.execute(
        "__bu_drw = $DRAW; $DRAW = false;" +
        "clipon 310, [0, 0, " + (val - thickness / 2).ToString() + "], [0, 0, 1], false, __sec_id;" +
        "clipon 311, [0, 0, " + (val + thickness / 2).ToString() + "], [0, 0, -1], false, __sec_id;" +
        "$DRAW = __bu_drw;" +
        "update",
        null, false, false);
    }

    private void radioButton1_CheckedChanged(object sender, EventArgs e)
    {
      trackBar1.Enabled = true;
      trackBar2.Enabled = false;
      trackBar3.Enabled = false;
      t.execute("[210, 211, 310, 311].each { |i| clipoff i }");
      trackBar1_Scroll(null, null);
    }

    private void radioButton2_CheckedChanged(object sender, EventArgs e)
    {
      trackBar1.Enabled = false;
      trackBar2.Enabled = true;
      trackBar3.Enabled = false;
      t.execute("[110, 111, 310, 311].each { |i| clipoff i }");
      trackBar2_Scroll(null, null);
    }

    private void radioButton3_CheckedChanged(object sender, EventArgs e)
    {
      trackBar1.Enabled = false;
      trackBar2.Enabled = false;
      trackBar3.Enabled = true;
      t.execute("[110, 111, 210, 211].each { |i| clipoff i }");
      trackBar3_Scroll(null, null);
    }


  }

}
