using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace siren
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("siren version 0.0.0");
            Console.Write("$DRAW = ");

            sirenenv.Viewer v = new sirenenv.Viewer();
            v.InitOCCViewer();

            string msg;

            v.mruby_exec("$DRAW = false", out msg);

            if (args.Length > 0) {
                foreach (string arg in args) {
                    System.IO.StreamReader r = ( new System.IO.StreamReader(arg, System.Text.Encoding.Default) );
                    while (r.Peek() >= 0) {
                        string buf = r.ReadLine();
                        if (v.mruby_exec(buf, out msg) != 0) {
                            Console.WriteLine(msg);
                        }
                    }
                    r.Close();
                }
            }
            else {
                for (; ; ) {
                    Console.Write("> ");
                    string buf = Console.ReadLine();
                    if (buf == null || buf.Length == 0)
                        break;
                    if (v.mruby_exec(buf, out msg) != 0) {
                        Console.WriteLine(msg);
                    }
                }
            }

            return;
        }
    }
}
