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
  public partial class SplashForm : Form
  {
    public SplashForm()
    {
      InitializeComponent();
    }

    private static SplashForm _form = null;
    private static Form _mainForm = null;
    private static System.Threading.Thread _thread = null;
    private static readonly object syncObject = new object();
    private static System.Threading.ManualResetEvent splashShownEvent = null;

    public static SplashForm Form
    {
      get { return _form; }
    }

    public static void ShowSplash(Form mainForm)
    {
      lock (syncObject) {
        if (_form != null || _thread != null) {
          return;
        }

        _mainForm = mainForm;
        if (_mainForm != null) {
          _mainForm.Activated += new EventHandler(_mainForm_Activated);
        }

        splashShownEvent = new System.Threading.ManualResetEvent(false);

        _thread = new System.Threading.Thread(
            new System.Threading.ThreadStart(StartThread));
        _thread.Name = "SplashForm";
        _thread.IsBackground = true;
        _thread.SetApartmentState(System.Threading.ApartmentState.STA);

        _thread.Start();
      }
    }

    public static void ShowSplash()
    {
      ShowSplash(null);
    }

    public static void CloseSplash()
    {
      lock (syncObject) {
        if (_thread == null) {
          return;
        }

        if (_mainForm != null) {
          _mainForm.Activated -= new EventHandler(_mainForm_Activated);
        }

        if (splashShownEvent != null) {
          splashShownEvent.WaitOne();
          splashShownEvent.Close();
          splashShownEvent = null;
        }

        if (_form != null) {
          if (_form.InvokeRequired) {
            _form.Invoke(new MethodInvoker(CloseSplashForm));
          }
          else {
            CloseSplashForm();
          }
        }

        if (_mainForm != null) {
          if (_mainForm.InvokeRequired) {
            _mainForm.Invoke(new MethodInvoker(ActivateMainForm));
          }
          else {
            ActivateMainForm();
          }
        }

        _form = null;
        _thread = null;
        _mainForm = null;
      }
    }

    private static void StartThread()
    {
      _form = new SplashForm();
      _form.Click += new EventHandler(_form_Click);
      _form.Activated += new EventHandler(_form_Activated);
      Application.Run(_form);
    }

    private static void CloseSplashForm()
    {
      if (!_form.IsDisposed) {
        _form.Close();
      }
    }

    private static void ActivateMainForm()
    {
      if (!_mainForm.IsDisposed) {
        _mainForm.Activate();
      }
    }

    private static void _form_Click(object sender, EventArgs e)
    {
      CloseSplash();
    }

    private static void _mainForm_Activated(object sender, EventArgs e)
    {
      CloseSplash();
    }

    private static void _form_Activated(object sender, EventArgs e)
    {
      _form.Activated -= new EventHandler(_form_Activated);
      if (splashShownEvent != null) {
        splashShownEvent.Set();
      }
    }
  }
}
