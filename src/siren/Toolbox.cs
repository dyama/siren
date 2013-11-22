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
    public partial class Toolbox : Form
    {

        siren.MainForm main;

        public Toolbox(siren.MainForm mainform)
        {
            InitializeComponent();
            this.main = mainform;
        }

        public ViewForm current
        {
            get { return (siren.ViewForm)this.main.ActiveMdiChild; }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (current != null)
                current.getterm().execute("a=box tri10");
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (current != null)
                current.getterm().execute("a=sphere 10");
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            if (current != null)
                current.getterm().execute("a=cylinder op, [0, 0, 1], 10, 20, " + deg2rad(360).ToString() );
        }

        private void checkBox6_CheckedChanged(object sender, EventArgs e)
        {
            if (current != null)
                current.getterm().execute("a=cone op, [0, 0, 1], 10, 0, 20, " + deg2rad(360).ToString() );
        }

        private void checkBox11_CheckedChanged(object sender, EventArgs e)
        {
            if (current != null)
                current.getterm().execute("a=torus op, [0, 0, 1], 20, 5, "
                    + deg2rad(0).ToString() + ", "
                    + deg2rad(360).ToString() + ", "
                    + deg2rad(360).ToString() );
        }

        private double deg2rad(double deg)
        {
            return (Math.PI / 180.0 * deg);
        }
    }
}
