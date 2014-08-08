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
  public enum DisplayMode : int { WIREFRAME = 0, SHADING = 1 }

  public partial class ViewForm : System.Windows.Forms.UserControl
  {
    protected MainForm parent = null;
    protected TypeOfOrientation orient;
    protected bool allowRotation;

    protected PictureBox focuser;

    /// <summary>
    /// コンストラクタ
    /// </summary>
    public ViewForm(MainForm aParent, TypeOfOrientation orient, bool allowRotation)
    {
      InitializeComponent();


      myViewer = new Viewer();

      parent = aParent;

      initKeyEvent();
      initMouseEvent();

      this.orient = orient;
      this.allowRotation = allowRotation;

      focuser = new PictureBox();
      focuser.Size = new Size(6, 6);
      focuser.Location = new Point(3, 3);
      focuser.BackColor = Color.DarkRed;
      focuser.BorderStyle = BorderStyle.FixedSingle;
      this.Controls.Add(focuser);

    }

    //private System.Windows.Forms.ImageList imageList1;
    private Viewer myViewer;

    /// <summary>
    /// Viewer3d 初期化
    /// </summary>
    public void InitV3D(bool is_raytracing)
    {
      IntPtr handle = this.Handle;
      if (!myViewer.InitViewer(handle, true, is_raytracing, false)) {
        MessageBox.Show("グラフィックシステム初期化エラー", "Error!",
            MessageBoxButtons.OK, MessageBoxIcon.Error);
      }
      // Init default visual appearance.
      myViewer.SetAntialiasing(false);
      // myViewer.setHighlightColor(NameOfColor.ORANGE);
      // myViewer.setSelectionColor(NameOfColor.BLUE4);
      myViewer.setHighlightColor(NameOfColor.RED);
      myViewer.setSelectionColor(NameOfColor.YELLOW);
      myViewer.setProjection(orient);
    }


    protected DisplayMode _currentDisplayMode = DisplayMode.WIREFRAME;
    public DisplayMode currentDisplayMode
    {
      set
      {
        myViewer.SetDisplayMode((int)value);
        _currentDisplayMode = value;
      }
      get { return _currentDisplayMode; }
    }

    public Viewer Viewer
    {
      get { return this.myViewer; }
      set { this.myViewer = value; }
    }

    public void InitViewer()
    {
      this.myViewer.InitOCCViewer();
    }

    public void SetContext(Viewer Viewer)
    {
      this.myViewer.SetAISContext(Viewer);
    }

    public CurAct3d CurMode
    {
      get { return this.myCurMode; }
      set { this.myCurMode = value; }
    }

    public bool DegenerateMode
    {
      get { return this.IsShading; }
      set
      {
        this.IsShading = value;
        myViewer.SetComputedMode(value);
      }
    }

    #region ツールバー イベント

    /// <summary>
    /// ビューのリセットボタン
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void tsbResetView_Click(object sender, EventArgs e)
    {
      myViewer.Reset();
      myViewer.ZoomAllView();
    }

    /// <summary>
    /// フィットボタン
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void tsbFit_Click(object sender, EventArgs e)
    {
      myViewer.ZoomAllView();
    }

    private void tsbAxoView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.XposYnegZpos);
    }
    private void tsbFrontView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.Xpos);
    }
    private void tsbBackView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.Xneg);
    }
    private void tsbLeftView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.Ypos);
    }
    private void tsbRightView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.Yneg);
    }
    private void tsbTopView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.Zpos);
    }
    private void tsbBottomView_Click(object sender, EventArgs e)
    {
      myViewer.setProjection(TypeOfOrientation.Zneg);
    }

    /// <summary>
    /// シェーディング・ワイヤフレーム切り替えボタン(トグル)
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void tsbShading_Click(object sender, EventArgs e)
    {
      ToolStripButton b = (ToolStripButton)sender;
      if (b.Checked) {
        currentDisplayMode = DisplayMode.WIREFRAME;
      }
      else {
        currentDisplayMode = DisplayMode.SHADING;
      }
      b.Checked = !b.Checked;
    }

    /// <summary>
    /// 隠面消去切り替えボタン(トグル)
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void tsbHlr_Click(object sender, EventArgs e)
    {
      ToolStripButton b = (ToolStripButton)sender;
      if (b.Checked) {
        DegenerateMode = true;
      }
      else {
        DegenerateMode = false;
      }
      b.Checked = !b.Checked;
      myViewer.UpdateCurrentViewer();
    }

    #endregion

    private void onMouseHover(object sender, EventArgs e)
    {
      this.Focus();
      focuser.BackColor = Color.Red;
    }

    private void onMouseLeave(object sender, EventArgs e)
    {
      focuser.BackColor = Color.DarkRed;
    }

    #region "描画関連"

    protected override void OnPaintBackground(PaintEventArgs e)
    {
      // Disable auto re-paint background
      // base.OnPaintBackground(e);
    }

    protected override void OnPaint(PaintEventArgs e)
    {
      // Disable auto re-paint
      // base.OnPaint(e);
    }

    private void ViewForm_SizeChanged(object sender, System.EventArgs e)
    {
      myViewer.MustBeResized();
    }

    private void ViewForm_Paint(object sender, System.Windows.Forms.PaintEventArgs e)
    {
      myViewer.Redraw();
    }

    #endregion

  }

}