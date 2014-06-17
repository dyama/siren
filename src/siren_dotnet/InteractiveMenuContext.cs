using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Drawing;

namespace siren
{
    class InteractiveMenuContext
    {
        public Point Location { set; get; }

        protected bool _visible;
        public bool Visible {
            set
            {
                if (value)
                    initLocation(this.Location);
                else
                    this.Parent.Focus();

                foreach (KeyValuePair<string, Button> item in b) {
                    item.Value.Visible = value;
                    if (value)
                        item.Value.BringToFront();
                }
                _visible = value;
            }
            get
            {
                return _visible;
            }
        }
        public Control Parent { set; get; }

        private Dictionary<String, Button> b;

        public InteractiveMenuContext(Control parent)
        {
            this.Parent = parent;

            b = new Dictionary<string, Button>();

            b.Add("undo", new Button());
            b["undo"].Height = 20;
            b["undo"].Text = "元に戻す(&Z)";
            b["undo"].Click += new EventHandler(InteractiveMenuContext_Click);

            b.Add("redo", new Button());
            b["redo"].Height = 20;
            b["redo"].Text = "やり直す(&Y)";
            b["redo"].Click += new EventHandler(InteractiveMenuContext_Click);

            b.Add("delete", new Button());
            b["delete"].Height = 20;
            b["delete"].Text = "削除(&D)";
            b["delete"].Click += new EventHandler(InteractiveMenuContext_Click);

            b.Add("rotate", new Button());
            b["rotate"].Height = 20;
            b["rotate"].Text = "回転(&R)";
            b["rotate"].Click += new EventHandler(InteractiveMenuContext_Click);

            b.Add("scale", new Button());
            b["scale"].Height = 20;
            b["scale"].Text = "スケール(&S)";
            b["scale"].Click += new EventHandler(InteractiveMenuContext_Click);

            b.Add("translate", new Button());
            b["translate"].Height = 20;
            b["translate"].Text = "移動(&T)";
            b["translate"].Click += new EventHandler(InteractiveMenuContext_Click);

            foreach (KeyValuePair<string, Button> item in b) {
                item.Value.Visible = false;
                this.Parent.Controls.Add(item.Value);
            }
        }

        void InteractiveMenuContext_Click(object sender, EventArgs e)
        {
            this.Visible = false;
        }

        public void initLocation(Point loc)
        {
            b["undo"].Location = new Point(Location.X - b["undo"].Width / 2 - 60, Location.Y + 0);
            b["redo"].Location = new Point(Location.X - b["redo"].Width / 2 + 60, Location.Y + 0);
            b["delete"].Location = new Point(Location.X - b["delete"].Width / 2, Location.Y + 25);

            b["rotate"].Location    = new Point(Location.X - b["rotate"].Width / 2 - 60, Location.Y - 25);
            b["scale"].Location     = new Point(Location.X - b["scale"].Width / 2 + 60, Location.Y - 25);
            b["translate"].Location = new Point(Location.X - b["translate"].Width / 2, Location.Y - 25 - 25);
        }

    }
}
