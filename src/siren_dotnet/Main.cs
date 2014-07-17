using System;
using System.Windows.Forms;
using siren;

public class Program
{

  [STAThread]
  static void Main()
  {
    MainForm mf = new MainForm();
#if DEBUG
    SplashForm.ShowSplash(mf);
#endif
    Application.Run(mf);
  }

}
