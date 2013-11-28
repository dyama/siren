/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
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

    public partial class ViewForm : System.Windows.Forms.Form
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
            kemap.Add(Keys.Enter, showTerminal);
            kemap.Add(Keys.Space, showMenu);
            kemap.Add(Keys.Delete, myViewer.EraseObjects);
        }

        /// <summary>
        /// キー イベント: KeyDown
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
		private void onKeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
		{
			if (e.Shift)
				myCurSpKey=CurSpKey.SHIFT;
			else if (e.Control)
				myCurSpKey=CurSpKey.CTRL;

            if (kemap != null && kemap.ContainsKey(e.KeyCode))
                kemap[e.KeyCode]();
            
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
            if (isSpaceKeyDown) {
                m.Visible = false;
                isSpaceKeyDown = false;
                this.Focus();
            }
            return;
		}

        /// <summary>
        /// Key Event: show mruby command terminal on view
        /// </summary>
        public void showTerminal()
        {
            t.Visible = true;
            t.BringToFront();
            t.setFocus();
            return;
        }

        /// <summary>
        /// Key Event: show interactive menu on view
        /// </summary>
        public void showMenu()
        {
            if (!isSpaceKeyDown) {
                m.Location = Parent.PointToClient(Cursor.Position);
                m.Visible = true;
                isSpaceKeyDown = true;
            }
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

        /// <summary>
        /// ビュー ウィンドウの最大化切り替え
        /// </summary>
        private void toggleWindowState()
        {
            if (this.WindowState == FormWindowState.Normal || this.WindowState == FormWindowState.Minimized)
                this.WindowState = FormWindowState.Maximized;
            else
                this.WindowState = FormWindowState.Normal;
            return;
        }

        private void AxoView()
        {
            myViewer.setProjection(TypeOfOrientation.XposYnegZpos);
        }
        private void FrontView()
        {
            myViewer.setProjection(TypeOfOrientation.Xpos);
        }
        private void BackView()
        {
            myViewer.setProjection(TypeOfOrientation.Xneg);
        }
        private void LeftView()
        {
            myViewer.setProjection(TypeOfOrientation.Ypos);
        }
        private void RightView()
        {
            myViewer.setProjection(TypeOfOrientation.Yneg);
        }
        private void TopView()
        {
            myViewer.setProjection(TypeOfOrientation.Zpos);
        }
        private void BottomView()
        {
            myViewer.setProjection(TypeOfOrientation.Zneg);
        }
    }
}
