﻿/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
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
  public enum MouseState : int { DOWN = -1, UP = 1 }
  public enum CurAct3d { NOTHING, ZOOM, WINZOOM, PAN, GLOPAN, ROTATE }

  public partial class ViewForm : System.Windows.Forms.UserControl
  {
    protected CurAct3d myCurMode;
    public bool IsShading;
    protected int myXmin;
    protected int myYmin;
    protected int myXmax;
    protected int myYmax;
    protected int theButtonDownX;
    protected int theButtonDownY;
    // 矩形削除用
    protected int theRectDownX;
    protected int theRectDownY;
    protected bool IsRectVisible;

    protected void initMouseEvent()
    {
      myCurMode = CurAct3d.NOTHING;
      IsShading = true;
      IsRectVisible = false;

      return;
    }

    void onMouseEnter(object sender, EventArgs e)
    {
      this.Focus();
    }

    private void onMouseWheel(object sender, MouseEventArgs e)
    {
      double factor = 0.15;
      double scale = myViewer.Scale();

      factor = e.Delta < 0 ? scale * factor : scale * -factor;
      if (scale - factor < 0)
        scale = 0.001;
      else
        scale = scale - factor;

      myViewer.SetScale(scale);
    }

    void onMouseDoubleClick(object sender, MouseEventArgs e)
    {
      if (e.Button == MouseButtons.Middle)
        myViewer.ZoomAllView();
    }

    protected void DragEvent(int x, int y, MouseState theState)
    {
      if (theState == MouseState.DOWN) {
        theButtonDownX = x;
        theButtonDownY = y;
      }
      else if (theState == MouseState.UP) {
        myViewer.Select(Math.Min(theButtonDownX, x), Math.Min(theButtonDownY, y), Math.Max(theButtonDownX, x), Math.Max(theButtonDownY, y));
      }
    }

    private void DrawRectangle(bool draw)
    {
      Graphics gr = Graphics.FromHwnd(this.Handle);
      System.Drawing.Pen p = null;

      if (!draw) {
        //this.myViewer.UpdateView();
        return;
      }

      // if (this.IsRectVisible ||(!draw)) //erase the rect
      // {
      // 	int r = myViewer.GetBGColR();
      // 	int g = myViewer.GetBGColG();
      // 	int b = myViewer.GetBGColB();
      // 	p = new Pen(System.Drawing.Color.FromArgb(r,g, b));
      // 	this.IsRectVisible = false;
      // 	this.myViewer.UpdateView();
      // } 
      // else if (draw) 
      // {
      // 	p = new Pen(System.Drawing.Color.White);
      // 	this.IsRectVisible = true;
      // }

      p = new Pen(System.Drawing.Color.White, 2);

      if (p == null)
        return;

      int x = Math.Min(myXmin, myXmax);
      int y = Math.Min(myYmin, myYmax);
      int w = Math.Abs(myXmax - myXmin);
      int h = Math.Abs(myYmax - myYmin);

      gr.FillRectangle(Brushes.Black, x, y, w, h);
      //this.myViewer.UpdateView();
      //this.myViewer.RedrawView();
      //this.myViewer.UpdateCurrentViewer();
      this.myViewer.Redraw(x, y, w, h);

      gr.DrawRectangle(p, x, y, w, h);

      this.theRectDownX = Math.Max(this.myXmin, this.myXmax);
      this.theRectDownY = Math.Max(this.myYmin, this.myYmax);

    }

    public bool isDirectTranslateMode = false;
    private void ViewForm_Click(object sender, EventArgs e)
    {
      MouseEventArgs mea = (MouseEventArgs)e;

      MousePicking mp = parent.MousePickingEvent;

      // マウスによるピック イベント
      if (mp != null && mp.ApplyEvent != null) {

        // Shiftが押されていたら座標を丸める
        bool doRound = (myCurSpKey == CurSpKey.SHIFT);

        if (mp.Count > 0) {
          // Count が正数の時はカウントダウン式
          if (mea.Button == MouseButtons.Left) {
            if (mp.PickedPoints == null)
              mp.PickedPoints = new List<Point3d>();
            double x, y, z;
            Viewer.xy2xyz(mea.X, mea.Y, out x, out y, out z, doRound);
            mp.PickedPoints.Add(new Point3d(x, y, z));
          }
          else {
            // カウントダウン式の時に左クリック以外を押すとキャンセル
            if (mp.CancelEvent != null) {
              mp.CancelEvent();
              mp.init();
            }
          }
          mp.Count -= 1;
        }
        else if (mp.Count < 0) {
          // Count が負数の時は任意の数
          if (mea.Button == MouseButtons.Left) {
            if (mp.PickedPoints == null)
              mp.PickedPoints = new List<Point3d>();
            double x, y, z;
            Viewer.xy2xyz(mea.X, mea.Y, out x, out y, out z, doRound);
            mp.PickedPoints.Add(new Point3d(x, y, z));
          }
          else {
            if (mp.PickedPoints == null || mp.PickedPoints.Count < 2) {
              // キャンセル
              if (mp.CancelEvent != null) {
                mp.CancelEvent();
                mp.init();
              }
            }
            else {
              // 確定
              mp.Count = 0;
            }
          }
        }
        // 終了条件
        if (mp.ApplyEvent != null && mp.Count == 0) {
          mp.ApplyEvent(mp.PickedPoints);
          mp.init();
        }
      }

      if (isDirectTranslateMode) {
        if (mea.Button == MouseButtons.Left) {
          double x, y, z;
          this.Viewer.xy2xyz(mea.X, mea.Y, out x, out y, out z, true);
          string pos = "[" + x.ToString() + "," + y.ToString() + "," + z.ToString() + "]";
          parent.myTerm.execute("location ?, " + pos);
        }
        isDirectTranslateMode = false;
      }
    }

    private void onMouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
    {
      switch (e.Button) {
      case MouseButtons.Left:
        myXmin = myXmax = e.X;
        myYmin = myYmax = e.Y;
        if (myCurSpKey == CurSpKey.CTRL) {
          this.Cursor = System.Windows.Forms.Cursors.SizeWE;
          myCurMode = CurAct3d.ZOOM;
        }
        else if (myCurMode == CurAct3d.NOTHING) {
          DragEvent(myXmax, myYmax, MouseState.DOWN);
        }
        break;
      case MouseButtons.Right: {
          if (allowRotation) {
            if (!IsShading)
              myViewer.SetComputedMode(false);
            this.Cursor = System.Windows.Forms.Cursors.SizeAll;
            myViewer.StartRotation(e.X, e.Y);
          }
        }
        break;
      case MouseButtons.Middle: {
          this.Cursor = System.Windows.Forms.Cursors.NoMove2D;
        }
        break;
      default: {
          break;
        }
      }
    }

    private void onMouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
    {
      switch (e.Button) {
      case MouseButtons.Left: {
          if (myCurSpKey == CurSpKey.CTRL) {
            myViewer.Zoom(myXmax, myYmax, e.X, e.Y);
            myXmax = e.X;
            myYmax = e.Y;
          }
          else if (myCurMode == CurAct3d.NOTHING) {
            DrawRectangle(false);
            myXmax = e.X;
            myYmax = e.Y;
            DrawRectangle(true);
          }
        }
        break;
      case MouseButtons.Middle: {
				double x = Math.Abs( e.X - myXmax );
				double y = Math.Abs(e.Y - myYmax);
				if ( x > 5 || y > 5 )
				{
					myViewer.Pan(e.X - myXmax, myYmax - e.Y);
					myXmax = e.X;
					myYmax = e.Y;
				}
        }
        break;
      case MouseButtons.Right: {
          if (allowRotation) {
            myViewer.Rotation(e.X, e.Y);
          }
        }
        break;
      default: {
          myXmax = e.X;
          myYmax = e.Y;
          myViewer.MoveTo(e.X, e.Y);
        }
        break;
      }

      return;
    }

    private void onMouseUp(object sender, System.Windows.Forms.MouseEventArgs e)
    {
      switch (e.Button) {
      case MouseButtons.Left: {
          if (myCurSpKey == CurSpKey.CTRL) {
            this.Cursor = Cursors.Default;
            return;
          }
          if (myCurMode == CurAct3d.NOTHING) {
            if (e.X == myXmin && e.Y == myYmin) {
              myXmax = e.X;
              myYmax = e.Y;
              if (myCurSpKey == CurSpKey.SHIFT) {
                myViewer.ShiftSelect();
              }
              else {
                myViewer.Select();
              }
            }
            else {
              myXmax = e.X;
              myYmax = e.Y;
              DragEvent(myXmax, myYmax, MouseState.UP);
            }
          }
          else {
            myCurMode = CurAct3d.NOTHING;
          }
        }
        break;
      case MouseButtons.Right: {
          if (allowRotation) {
            if (!IsShading) {
              myViewer.SetComputedMode(true);
              IsShading = false;
            }
            else {
              myViewer.SetComputedMode(false);
              IsShading = true;
            }
            this.Viewer.ZFitAll();
          }
        }
        break;
      default: {
          // nothing to do
          break;
        }
      }

      this.Cursor = System.Windows.Forms.Cursors.Default;

      siren.MainForm parent = (siren.MainForm)this.ParentForm;
      parent.changeState();

      return;
    }

  }
}