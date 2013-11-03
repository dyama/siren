/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
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

	public partial class ViewForm : System.Windows.Forms.Form
	{
        private term t;

        /// <summary>
        /// コンストラクタ
        /// </summary>
		public ViewForm()
		{
			InitializeComponent();

			myViewer = new Viewer();
            t = new term(myViewer);
            this.cont.ContentPanel.Controls.Add(t);
            t.Visible = false;

            initKeyEvent();
            initMouseEvent();
		}

        //private System.Windows.Forms.ImageList imageList1;
		private Viewer myViewer;

        /// <summary>
        /// Viewer3d 初期化
        /// </summary>
		public void InitV3D()
		{
            IntPtr handle = this.cont.ContentPanel.Handle;
            if (!myViewer.InitViewer(handle)) {
                MessageBox.Show("グラフィックシステム初期化エラー", "Error!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            // Init default visual appearance.
            myViewer.SetAntialiasing(false);
            myViewer.setHighlightColor(NameOfColor.ORANGE);
            myViewer.setSelectionColor(NameOfColor.WHITE);
		}

		private void ViewForm_SizeChanged(object sender, System.EventArgs e)
		{
			myViewer.UpdateView();
		}

		private void ViewForm_Paint(object sender, System.Windows.Forms.PaintEventArgs e)
		{
			myViewer.RedrawView();
			myViewer.UpdateView();
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

		public void ChangeColor(bool IsObjectColor)
		{
			int r, g, b;
			if (IsObjectColor) {
				r = myViewer.GetObjColR();
				g = myViewer.GetObjColG();
				b = myViewer.GetObjColB();
			}
			else {
				r = myViewer.GetBGColR();
				g = myViewer.GetBGColG();
				b = myViewer.GetBGColB();
			}
			System.Windows.Forms.ColorDialog ColDlg = new ColorDialog();
			ColDlg.Color=System.Drawing.Color.FromArgb(r, g, b);
			if (ColDlg.ShowDialog() == DialogResult.OK) {
				Color c = ColDlg.Color;
				r = c.R;
				g = c.G;
				b = c.B;
				if (IsObjectColor)
					myViewer.SetColor(r, g, b);
				else
					myViewer.SetBackgroundColor(r, g, b);
			}
			this.myViewer.UpdateCurrentViewer();

		}

		public void DeleteObjects()
		{
			myViewer.EraseObjects();
		}

        /// <summary>
        /// インポート
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="format"></param>
        /// <returns></returns>
		public bool Import(string filename, siren.ModelFormat format)
		{
            if (!System.IO.File.Exists(filename))
                return false;
            switch (format) {
            case ModelFormat.BREP:
            case ModelFormat.CSFDB:
            case ModelFormat.IGES:
            case ModelFormat.STEP:
                bool result = myViewer.TranslateModel(filename, (int)format, true) ;
                if (result)
                    myViewer.ZoomAllView();
                return result;
            default:
                return false;
            }
		}

        /// <summary>
        /// エクスポート
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="format"></param>
        /// <returns></returns>
		public bool Export(string filename, ModelFormat format)
		{
            switch (format) {
            case ModelFormat.BREP:
            case ModelFormat.CSFDB:
            case ModelFormat.IGES:
            case ModelFormat.STEP:
            case ModelFormat.STL:
            case ModelFormat.VRML:
            case ModelFormat.IMAGE:
                return myViewer.TranslateModel(filename, (int)format, false);
            default:
                return false;
            }
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

		private void onClosed(object sender, System.EventArgs e)
		{
			siren.MainForm parent = (siren.MainForm) this.ParentForm;
			parent.OnFileClose();
		}

		public CurAct3d CurMode
		{
			get { return this.myCurMode; }
			set { this.myCurMode=value; }
		}

		public float Zoom { set { this.myCurZoom = value; } }

		public bool DegenerateMode
		{
			get { return this.myDegenerateModeIsOn; }
			set
			{
				this.myDegenerateModeIsOn=value;
                if (value)
                    myViewer.SetDegenerateModeOn();
                else
                    myViewer.SetDegenerateModeOff();
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

    }

}