using System;
using System.Windows.Forms;
using siren;

public class Program
{

  [STAThread]
  static void Main()
  {
    MainForm mf = new MainForm();
    SplashForm.ShowSplash(mf);
    Application.Run(mf);
  }

}
