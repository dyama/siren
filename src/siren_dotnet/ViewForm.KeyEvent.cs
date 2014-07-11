/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

using System;
using System.Drawing;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Forms;
using sirenenv;

namespace siren
{
  public enum CurSpKey { NOTHING, CTRL, SHIFT, META }

  public partial class ViewForm : System.Windows.Forms.UserControl
  {
    /// <summary>
    /// 現在押されている特殊キー
    /// </summary>
    protected CurSpKey myCurSpKey;

    protected bool isSpaceKeyDown = false;

    /// <summary>
    /// キー イベントのメソッド定義
    /// </summary>
    protected delegate void keyevent();

    /// <summary>
    /// キー イベント マップ
    /// </summary>
    protected Dictionary<Keys, keyevent> kemap;

    /// <summary>
    /// キー イベントの初期化
    /// </summary>
    protected void initKeyEvent()
    {
      myCurSpKey = CurSpKey.NOTHING;

      kemap = new Dictionary<Keys, keyevent>();

      kemap.Add(Keys.F, myViewer.ZoomAllView);
      kemap.Add(Keys.H, toggleDisplayMode);
      //kemap.Add(Keys.Space, toggleWindowState);
      kemap.Add(Keys.D1, AxoView);
      kemap.Add(Keys.D2, BackView);
      kemap.Add(Keys.D3, TopView);
      kemap.Add(Keys.D4, RightView);
      kemap.Add(Keys.Space, parent.toggleFullscreen);
      kemap.Add(Keys.Delete, eraseSelected);
      kemap.Add(Keys.X, eraseSelected);
      kemap.Add(Keys.Enter, parent.focusTerminal);

      // funny move
      kemap.Add(Keys.W, move_to_front);
      kemap.Add(Keys.S, move_to_back);
      kemap.Add(Keys.D, move_to_right);
      kemap.Add(Keys.A, move_to_left);
      kemap.Add(Keys.E, move_to_top);
      kemap.Add(Keys.Q, move_to_bottom);

      //
      kemap.Add(Keys.Oemplus, scale_up);
      kemap.Add(Keys.OemMinus, scale_down);

      kemap.Add(Keys.G, group);
    }

    /// <summary>
    /// キー イベント: KeyDown
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void onKeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
    {
      if (e.Shift)
        myCurSpKey = CurSpKey.SHIFT;
      else if (e.Control)
        myCurSpKey = CurSpKey.CTRL;
      else if (e.Alt)
        myCurSpKey = CurSpKey.META;

      if (kemap != null && kemap.ContainsKey(e.KeyCode)) {
        kemap[e.KeyCode]();
        siren.MainForm parent = (siren.MainForm)this.ParentForm;
        parent.changeState();
      }

      return;
    }

    /// <summary>
    /// キー イベント: KeyUp
    /// </summary>
    /// <param name="sender"></param>
    /// <param name="e"></param>
    private void onKeyUp(object sender, System.Windows.Forms.KeyEventArgs e)
    {
      myCurSpKey = CurSpKey.NOTHING;
      return;
    }

    /// <summary>
    /// ディスプレイ モード切り替え
    /// </summary>
    public void toggleDisplayMode()
    {
      if (currentDisplayMode == DisplayMode.WIREFRAME)
        currentDisplayMode = DisplayMode.SHADING;
      else
        currentDisplayMode = DisplayMode.WIREFRAME;
      return;
    }

    public void AxoView() { myViewer.setProjection(TypeOfOrientation.XnegYnegZpos); }
    public void FrontView() { myViewer.setProjection(TypeOfOrientation.Xpos); }
    public void BackView() { myViewer.setProjection(TypeOfOrientation.Xneg); }
    public void LeftView() { myViewer.setProjection(TypeOfOrientation.Ypos); }
    public void RightView() { myViewer.setProjection(TypeOfOrientation.Yneg); }
    public void TopView() { myViewer.setProjection(TypeOfOrientation.Zpos); }
    public void BottomView() { myViewer.setProjection(TypeOfOrientation.Zneg); }

    private void move_to_front()
    {
      if (!Viewer.IsObjectSelected())
        return;
      switch (myCurSpKey) {
      case CurSpKey.CTRL:
        break;
      case CurSpKey.META:
        parent.myTerm.execute("selected.each { |obj| scale obj, $SUP, (location obj) }", this, false, false);
        break;
      case CurSpKey.SHIFT:
        parent.myTerm.execute("selected.each { |obj| rotate obj, (location obj), [0, 1, 0], $ANG }", this, false, false);
        break;
      case CurSpKey.NOTHING:
      default:
        parent.myTerm.execute("selected.each { |obj| translate obj, [$DIST, 0, 0] }", this, false, false);
        break;
      }
    }
    private void move_to_back()
    {
      if (!Viewer.IsObjectSelected())
        return;
      switch (myCurSpKey) {
      case CurSpKey.CTRL:
        break;
      case CurSpKey.META:
        parent.myTerm.execute("selected.each { |obj| scale obj, $SDOWN, (location obj) }", this, false, false);
        break;
      case CurSpKey.SHIFT:
        parent.myTerm.execute("selected.each { |obj| rotate obj, (location obj), [0, 1, 0], -$ANG }", this, false, false);
        break;
      case CurSpKey.NOTHING:
      default:
        parent.myTerm.execute("selected.each { |obj| translate obj, [-$DIST, 0, 0] }", this, false, false);
        break;
      }
    }
    private void move_to_left()
    {
      if (!Viewer.IsObjectSelected())
        return;
      switch (myCurSpKey) {
      case CurSpKey.CTRL:
        break;
      case CurSpKey.META:
        break;
      case CurSpKey.SHIFT:
        parent.myTerm.execute("selected.each { |obj| rotate obj, (location obj), [1, 0, 0], -$ANG }", this, false, false);
        break;
      case CurSpKey.NOTHING:
      default:
        parent.myTerm.execute("selected.each { |obj| translate obj, [0, $DIST, 0] }", this, false, false);
        break;
      }
    }
    private void move_to_right()
    {
      if (!Viewer.IsObjectSelected())
        return;
      switch (myCurSpKey) {
      case CurSpKey.CTRL:
        parent.myTerm.execute("a = []; selected.each { |obj| a.push(copy obj) }", this, false, false);
        break;
      case CurSpKey.META:
        break;
      case CurSpKey.SHIFT:
        parent.myTerm.execute("selected.each { |obj| rotate obj, (location obj), [1, 0, 0], $ANG }", this, false, false);
        break;
      case CurSpKey.NOTHING:
      default:
        parent.myTerm.execute("selected.each { |obj| translate obj, [0, -$DIST, 0] }", this, false, false);
        break;
      }
    }
    private void move_to_top()
    {
      if (!Viewer.IsObjectSelected())
        return;
      switch (myCurSpKey) {
      case CurSpKey.CTRL:
        break;
      case CurSpKey.META:
        break;
      case CurSpKey.SHIFT:
        parent.myTerm.execute("selected.each { |obj| rotate obj, (location obj), [0, 0, 1], $ANG }", this, false, false);
        break;
      case CurSpKey.NOTHING:
      default:
        parent.myTerm.execute("selected.each { |obj| translate obj, [0, 0, $DIST] }", this, false, false);
        break;
      }
    }
    private void move_to_bottom()
    {
      if (!Viewer.IsObjectSelected())
        return;
      switch (myCurSpKey) {
      case CurSpKey.CTRL:
        break;
      case CurSpKey.META:
        break;
      case CurSpKey.SHIFT:
        parent.myTerm.execute("selected.each { |obj| rotate obj, (location obj), [0, 0, 1], -$ANG }", this, false, false);
        break;
      case CurSpKey.NOTHING:
      default:
        parent.myTerm.execute("selected.each { |obj| translate obj, [0, 0, -$DIST] }", this, false, false);
        break;
      }
    }

    private void scale_up()
    {
      if (!Viewer.IsObjectSelected())
        return;
      parent.myTerm.execute("selected.each { |obj| scale obj, $SUP, (location obj) }", this, false, false);
    }

    private void scale_down()
    {
      if (!Viewer.IsObjectSelected())
        return;
      parent.myTerm.execute("selected.each { |obj| scale obj, $SDOWN, (location obj) }", this, false, false);
    }

    private void group()
    {
      if (myCurSpKey == CurSpKey.CTRL) {
        if (Viewer.NbSelected() > 1) {
          parent.myTerm.execute("a = compound selected", this, true, true);
        }
      }
    }

    private void eraseSelected()
    {
      if (Viewer.NbSelected() > 0) {
        parent.myTerm.execute("__bu_draw = $DRAW; $DRAW = false; selected.each { |item| erase item; }; $DRAW = __bu_draw; update", this, true, true);
      }
    }

  }
}
