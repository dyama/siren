using System;
using System.Collections.Generic;
using System.Text;

namespace siren
{
    public class Point3d
    {
        public double X;
        public double Y;
        public double Z;

        public Point3d()
        {
            X = 0;
            Y = 0;
            Z = 0;
        }

        public Point3d(double x, double y, double z)
        {
            X = x;
            Y = y;
            Z = z;
        }

        public string to_a()
        {
            return ("[" + X.ToString() + ", " + Y.ToString() + ", " + Z.ToString() + "]");
        }
    }
}
