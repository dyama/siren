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

	public partial class ViewForm : System.Windows.Forms.UserControl
	{
        protected MainForm parent = null;
        protected TypeOfOrientation orient;
        protected bool allowRotation;

        protected PictureBox focuser;

        /// <summary>
        /// �R���X�g���N�^
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
        /// Viewer3d ������
        /// </summary>
		public void InitV3D(bool is_raytracing)
		{
            IntPtr handle = this.Handle;
            if (!myViewer.InitViewer(handle, is_raytracing, false)) {
                MessageBox.Show("�O���t�B�b�N�V�X�e���������G���[", "Error!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            // Init default visual appearance.
            myViewer.SetAntialiasing(false);
            myViewer.setHighlightColor(NameOfColor.ORANGE);
            myViewer.setSelectionColor(NameOfColor.YELLOW);
            myViewer.setProjection(orient);
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
        /// �C���|�[�g
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
                {
                    filename = filename.Replace(@"\", @"\\"); // escape
                    int err = parent.myTerm.execute("a = bload(\"" + filename + "\")");
                    if (err == 0) {
                        parent.myTerm.execute("fit");
                        return true;
                    }
                    else
                        return false;
                }
            case ModelFormat.IGES:
                {
                    filename = filename.Replace(@"\", @"\\"); // escape
                    int err = parent.myTerm.execute("a = iload(\"" + filename + "\")");
                    if (err == 0) {
                        parent.myTerm.execute("fit");
                        return true;
                    }
                    else
                        return false;
                }
            case ModelFormat.CSFDB:
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
        /// �G�N�X�|�[�g
        /// </summary>
        /// <param name="filename"></param>
        /// <param name="format"></param>
        /// <returns></returns>
		public bool Export(string filename, ModelFormat format)
		{
            switch (format) {
            case ModelFormat.BREP:
                {
                    filename = filename.Replace(@"\", @"\\"); // escape
                    return (parent.myTerm.execute("bsave(\"" + filename + "\", selected[0])") == 0);
                }
            //case ModelFormat.CSFDB:
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

        #region �c�[���o�[ �C�x���g

        /// <summary>
        /// �r���[�̃��Z�b�g�{�^��
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void tsbResetView_Click(object sender, EventArgs e)
        {
            myViewer.Reset();
            myViewer.ZoomAllView();
        }

        /// <summary>
        /// �t�B�b�g�{�^��
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
        /// �V�F�[�f�B���O�E���C���t���[���؂�ւ��{�^��(�g�O��)
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
        /// �B�ʏ����؂�ւ��{�^��(�g�O��)
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

    }

}