/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCMENTATION OF THIS PROJECT.
 * ---------------------------------------------------------
 * AUTHOR: dyama <dyama@member.fsf.org>
 */

using System;
using System.Windows.Forms;
using System.Collections.Generic;

namespace siren
{
	public enum ModelFormat : int{ UNKNOWN = -1, BREP = 0, CSFDB = 1, STEP = 2, IGES = 3, VRML = 4, STL = 5, IMAGE = 6 }

	public partial class MainForm : System.Windows.Forms.Form
	{

		[STAThread]
		static void Main() 
		{
			Application.Run(new MainForm());
        }

        #region "�C�x���g"

        void MainForm_Load(object sender, EventArgs e)
        {
            List<string> args = new List<string>(System.Environment.GetCommandLineArgs());
            // �R�}���h���C����������J��
            args.RemoveAt(0); // ���g�̌Ăяo���p�X
            if (args != null && args.Count > 0) {
                foreach (string file in args) {
                    if (!OpenFile(file, Common.getFormatByExt(file)))
                        break;
                }
            }
            else {
                NewFile();
            }
        }

        void MainForm_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Move;
        }

        void MainForm_DragDrop(object sender, DragEventArgs e)
        {
            List<string> files = new List<string>((string[])e.Data.GetData(DataFormats.FileDrop, false));
            if (files != null) {
                foreach (string file in files) {
                    if (!OpenFile(file, Common.getFormatByExt(file)))
                        break;
                }
            }
        }

        private void miNewViewer_Click(object sender, System.EventArgs e)
		{
			this.Cursor=System.Windows.Forms.Cursors.WaitCursor;
			this.NewFile();
		}

		private void miClose_Click(object sender, System.EventArgs e)
		{
			if ( this.MdiChildren.Length > 0 )
				this.ActiveMdiChild.Close();
		}

        private void miOpen_Click(object sender, System.EventArgs e)
        {
            OpenFile();
        }

        /// <summary>
        /// �c�[���o�[��Ԃ̐؂�ւ�
        /// </summary>
        public void onSelectObject()
        {
            tsbTranslate.Enabled = true;
            tsbRotate.Enabled = true;
            tsbScale.Enabled = true;
            tsbDisplayMode.Enabled = true;
            tsbTransparency.Enabled = true;
            tsbColor.Enabled = true;
            tsbMaterial.Enabled = true;
        }
        public void onUnselectObject()
        {
            tsbTranslate.Enabled = false;
            tsbRotate.Enabled = false;
            tsbScale.Enabled = false;
            tsbDisplayMode.Enabled = false;
            tsbTransparency.Enabled = false;
            tsbColor.Enabled = false;
            tsbMaterial.Enabled = false;
        }

        #endregion // �C�x���g

        private bool OpenFile(string filename, ModelFormat theformat)
        {
            if (theformat == ModelFormat.UNKNOWN) {
                MessageBox.Show("�T�|�[�g����Ă��Ȃ��t�@�C���`���ł��B", "�G���[", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

			this.Cursor = System.Windows.Forms.Cursors.WaitCursor;

            NewFile();
		    ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            bool result = curForm.Import(filename, theformat);

			this.Cursor = System.Windows.Forms.Cursors.Default;

            if (!result) {
                MessageBox.Show("�t�@�C���̓ǂݍ��݂Ɏ��s���܂����B", "�G���[", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            this.toolStripMain.Enabled = true;

            return true;
        }


		private bool OpenFile()
		{
			OpenFileDialog d = new OpenFileDialog();
            d.CheckFileExists = true;
   
			string filter="";
            d.RestoreDirectory = true;

            filter = "�Ή����Ă���S�Ẵt�@�C��(brep brp ble csfdb stp step igs iges)|*.brep; *.brp; *.rle; *.csfdb; *.stp; *.step; *.igs; *.iges";
			filter += "|BREP �t�@�C��(*.brep *.brp *.rle)|*.brep; *.brp; *.rle";
			filter += "|CSFDB �t�@�C��(*.csfdb)|*.csfdb";
			filter += "|STEP �t�@�C��(*.stp *.step)|*.stp; *.step";
			filter += "|IGES �t�@�C��(*.igs *.iges)|*.igs; *.iges";
			d.Filter = filter+"|All files (*.*)|*.*" ;

            if (d.ShowDialog() != DialogResult.OK)
                return false;

            return OpenFile(d.FileName, Common.getFormatByExt(d.FileName));
		}

        private bool SaveFile(string filename, ModelFormat format)
        {
            if (format == ModelFormat.UNKNOWN) {
                MessageBox.Show("�T�|�[�g����Ă��Ȃ��t�@�C���`���ł��B", "�G���[", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

			this.Cursor=System.Windows.Forms.Cursors.WaitCursor;

			ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            if (curForm == null)
                return false;

            bool result = curForm.Export(filename, Common.getFormatByExt(filename));

			this.Cursor=System.Windows.Forms.Cursors.Default;

            if (!result) {
                MessageBox.Show("�t�@�C���̕ۑ��Ɏ��s���܂����B", "�G���[", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            return result;
        }

        private bool SaveFile()
        {
			System.Windows.Forms.SaveFileDialog  d = new SaveFileDialog();
			string filter="";
			filter += "BREP �t�@�C��(*.brep *.brp *.rle)|*.brep; *.brp; *.rle";
			filter += "|CSFDB �t�@�C��(*.csfdb)|*.csfdb";
			filter += "|STEP �t�@�C��(*.stp *.step)|*.step; *.stp";
			filter += "|IGES �t�@�C��(*.igs *.iges)| *.iges; *.igs";
			filter += "|VRML �t�@�C��(*.vrml)|*.vrml";
			filter += "|STL �t�@�C��(*.stl)|*.stl";
			filter += "|WebGL JavaScript �t�@�C��(*.js)|*.js";
			filter += "|�摜�t�@�C��(*.bmp *.gif *.xwd)| *.bmp; *.gif; *.xwd";
			d.Filter = filter;

            if (d.ShowDialog() != DialogResult.OK)
                return false;

            return SaveFile(d.FileName, Common.getFormatByExt(d.FileName));
        }

		private void SaveFile_Click(object sender, System.EventArgs e)
		{
            SaveFile();
		}

		private void HelpAbout_Click(object sender, System.EventArgs e)
		{
			AboutDialog myDlg = new AboutDialog();
			myDlg.ShowDialog(this);
		}

		private void ViewerStatusBar_Click(object sender, System.EventArgs e)
		{
			if (this.ViewerStatusBar.Checked)
			{
				this.myStatusBar.Hide(); 
				this.ViewerStatusBar.Checked=false;
			}
			else
			{
				this.myStatusBar.Show();
				this.ViewerStatusBar.Checked=true;
			}
		}

		public void NewFile()
		{
			ViewForm newForm = new ViewForm();
            newForm.MdiParent = this;
            siren.MainForm.myNbOfChildren = siren.MainForm.myNbOfChildren + 1;
            string str = System.String.Format(newForm.Text + " {0}: �r���[ {1}", siren.MainForm.myNbOfChildren, 1);
            newForm.Text = str;
			newForm.Show();
			newForm.InitViewer();
			newForm.InitV3D();
			this.miView.Visible=true;
			this.Cursor=System.Windows.Forms.Cursors.Default;
            this.toolStripMain.Enabled = true;
		}

		private void miExit_Click(object sender, System.EventArgs e)
		{
			this.Close();
            return;
		}

		private void File_Popup(object sender, System.EventArgs e)
		{
			if (this.MdiChildren.Length > 0 )
				this.miFileClose.Enabled=true;
			else 
				this.miFileClose.Enabled=false;
            
            siren.ViewForm curForm = (siren.ViewForm)this.ActiveMdiChild;
            if (curForm != null)
                this.miSaveFile.Enabled = curForm.Viewer.IsObjectSelected();

            return;
		}

		private void menuItem4_Click(object sender, System.EventArgs e)
        {
            siren.ViewForm curForm = (siren.ViewForm)this.ActiveMdiChild;
            siren.ViewForm newViewer = new ViewForm();
            newViewer.MdiParent = this;
            newViewer.Show();
            newViewer.InitViewer();
            newViewer.SetContext(curForm.Viewer);
            newViewer.Viewer.CreateNewView(newViewer.Handle);
            {
                string title = curForm.Text;
                System.Text.StringBuilder bld= new System.Text.StringBuilder(title);
                char c = bld[title.Length - 1];
                string s=c.ToString();
                int NbOfViewer = newViewer.Viewer.CharToInt(s);
                NbOfViewer++;
                bld.Remove(title.Length - 1, 1);
                bld.Append(NbOfViewer);
                newViewer.Text = bld.ToString();
            }
        }

		private void WindowCascade_Click(object sender, System.EventArgs e)
		{
			this.LayoutMdi(System.Windows.Forms.MdiLayout.Cascade);
		}

		private void WindowTile_Click(object sender, System.EventArgs e)
		{
			this.LayoutMdi(System.Windows.Forms.MdiLayout.TileVertical);
		}

		public StatusStrip StatusBar
		{
			get
			{
				return this.myStatusBar;
			}
		}

		public void OnFileClose()
		{
			if ( this.MdiChildren.Length <=  1)
			{
				this.miFileClose.Enabled=false;
				this.miView.Visible=false;
                this.toolStripMain.Enabled = false;
			}
		}

		private void toolBarViewer_MouseHover(object sender, System.EventArgs e)
		{
			this.myStatusBar.Text="Viewer toolbar";
		}

		private void toolBarViewer_MouseLeave(object sender, System.EventArgs e)
		{
			this.myStatusBar.Text="";
		}

        private void miScreenShot_Click(object sender, EventArgs e)
        {
            SaveFileDialog d = new SaveFileDialog();
            d.RestoreDirectory = true;

            string filter = "";
			filter += "�摜�t�@�C��(*.bmp *.gif *.xwd)| *.bmp; *.gif; *.xwd";
			filter += "|BMP �t�@�C��(*.bmp)|*.bmp";
			filter += "|GIF �t�@�C��(*.gif)|*.gif";
			filter += "|XWD �t�@�C��(*.xwd)|*.xwd";
			d.Filter = filter;

            d.Title = "�X�N���[���V���b�g�̕ۑ�";

            if (d.ShowDialog() != DialogResult.OK)
                return;

            SaveFile(d.FileName, ModelFormat.IMAGE);
        }

        private void miView_Paint(object sender, PaintEventArgs e)
        {
			siren.ViewForm curForm = (siren.ViewForm) this.ActiveMdiChild;
            miScreenShot.Enabled = (curForm != null);
        }

        private void miFile_Paint(object sender, PaintEventArgs e)
        {
			siren.ViewForm curForm = (siren.ViewForm) this.ActiveMdiChild;
            if (curForm != null && curForm.Viewer.IsObjectSelected()) {
                miSaveFile.Enabled = true;
            }
            else {
                miSaveFile.Enabled = false;
            }
            return;
        }

        private void miDebug_Click(object sender, EventArgs e)
        {
			siren.ViewForm curForm = (siren.ViewForm) this.ActiveMdiChild;
            if (curForm == null)
                return;
            curForm.showTerminal();
        }

        private void tsbAbout_Click(object sender, EventArgs e)
        {
			AboutDialog myDlg = new AboutDialog();
			myDlg.ShowDialog(this);
        }

        private void tsbDisplayMode_Click(object sender, EventArgs e)
        {
            ToolStripButton mybutton = (ToolStripButton)sender;
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;

            if (!mybutton.Checked) {
                curForm.currentDisplayMode = DisplayMode.SHADING;
                mybutton.Checked = true;
            }
            else {
                curForm.currentDisplayMode = DisplayMode.WIREFRAME;
                mybutton.Checked = false;
            }
        }

        private void tsbTransparency_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
			if (curForm == null)
				return;
			siren.TransparencyDialog t = new TransparencyDialog();
			t.Viewer=curForm.Viewer;
			t.ShowDialog(curForm);
        }

        private void tsbFit_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;
            curForm.Viewer.ZoomAllView();
        }

        private void tsbBox_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;
            curForm.getterm().execute("a=box tri10");
        }

        private void tsbSphere_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;
            curForm.getterm().execute("a=sphere 10");
        }

        private void tsbCylinder_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;
            curForm.getterm().execute("a=cylinder op, [0, 0, 1], 10, 20, " + deg2rad(360).ToString());
        }

        private void tsbCone_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;
            curForm.getterm().execute("a=cone op, [0, 0, 1], 10, 0, 20, " + deg2rad(360).ToString() );
        }

        private void tsbTorus_Click(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;
        }

        private double deg2rad(double deg)
        {
            return (Math.PI / 180.0 * deg);
        }

        private void tsbColor_ButtonClick(object sender, EventArgs e)
        {
            ViewForm curForm = (ViewForm)this.ActiveMdiChild;
            if (curForm == null)
                return;

            int r, g, b;
            r = curForm.Viewer.GetObjColR();
            g = curForm.Viewer.GetObjColG();
            b = curForm.Viewer.GetObjColB();

            System.Windows.Forms.ColorDialog ColDlg = new ColorDialog();
            ColDlg.Color = System.Drawing.Color.FromArgb(r, g, b);
            if (ColDlg.ShowDialog() == DialogResult.OK) {
                System.Drawing.Color c = ColDlg.Color;
                r = c.R;
                g = c.G;
                b = c.B;
                curForm.Viewer.SetColor(r, g, b);
            }
            curForm.Viewer.UpdateCurrentViewer();
        }

	}

}