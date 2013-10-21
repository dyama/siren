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

        #region "イベント"

        void MainForm_Load(object sender, EventArgs e)
        {
            List<string> args = new List<string>(System.Environment.GetCommandLineArgs());
            // コマンドライン引数から開く
            args.RemoveAt(0); // 自身の呼び出しパス
            if (args != null) {
                foreach (string file in args) {
                    if (!OpenFile(file, Common.getFormatByExt(file)))
                        break;
                }
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

        #endregion // イベント

        private bool OpenFile(string filename, ModelFormat theformat)
        {
            if (theformat == ModelFormat.UNKNOWN) {
                MessageBox.Show("サポートされていないファイル形式です。", "エラー", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

			this.Cursor = System.Windows.Forms.Cursors.WaitCursor;

            NewFile();
		    ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            bool result = curForm.Import(filename, theformat);

			this.Cursor = System.Windows.Forms.Cursors.Default;

            if (!result) {
                MessageBox.Show("ファイルの読み込みに失敗しました。", "エラー", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }


		private bool OpenFile()
		{
			OpenFileDialog d = new OpenFileDialog();
            d.CheckFileExists = true;
   
			string filter="";
            d.RestoreDirectory = true;

            filter = "対応している全てのファイル(brep brp ble csfdb stp step igs iges)|*.brep; *.brp; *.rle; *.csfdb; *.stp; *.step; *.igs; *.iges";
			filter += "|BREP ファイル(*.brep *.brp *.rle)|*.brep; *.brp; *.rle";
			filter += "|CSFDB ファイル(*.csfdb)|*.csfdb";
			filter += "|STEP ファイル(*.stp *.step)|*.stp; *.step";
			filter += "|IGES ファイル(*.igs *.iges)|*.igs; *.iges";
			d.Filter = filter+"|All files (*.*)|*.*" ;

            if (d.ShowDialog() != DialogResult.OK)
                return false;

            return OpenFile(d.FileName, Common.getFormatByExt(d.FileName));
		}

        private bool SaveFile(string filename, ModelFormat format)
        {
            if (format == ModelFormat.UNKNOWN) {
                MessageBox.Show("サポートされていないファイル形式です。", "エラー", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

			this.Cursor=System.Windows.Forms.Cursors.WaitCursor;

			ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            if (curForm == null)
                return false;

            bool result = curForm.Export(filename, Common.getFormatByExt(filename));

			this.Cursor=System.Windows.Forms.Cursors.Default;

            if (!result) {
                MessageBox.Show("ファイルの保存に失敗しました。", "エラー", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            return result;
        }

        private bool SaveFile()
        {
			System.Windows.Forms.SaveFileDialog  d = new SaveFileDialog();
			string filter="";
			filter += "BREP ファイル(*.brep *.brp *.rle)|*.brep; *.brp; *.rle";
			filter += "|CSFDB ファイル(*.csfdb)|*.csfdb";
			filter += "|STEP ファイル(*.stp *.step)|*.step; *.stp";
			filter += "|IGES ファイル(*.igs *.iges)| *.iges; *.igs";
			filter += "|VRML ファイル(*.vrml)|*.vrml";
			filter += "|STL ファイル(*.stl)|*.stl";
			filter += "|WebGL JavaScript ファイル(*.js)|*.js";
			filter += "|画像ファイル(*.bmp *.gif *.xwd)| *.bmp; *.gif; *.xwd";
			d.Filter = filter;

            if (d.ShowDialog() != DialogResult.OK)
                return false;

            return SaveFile(d.FileName, Common.getFormatByExt(d.FileName));
        }

		private void toolBar1_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
		{

			ViewForm curForm = (ViewForm) this.ActiveMdiChild;
			switch(toolBarTool.Buttons.IndexOf(e.Button))
			{
				case 0:
					this.Cursor=System.Windows.Forms.Cursors.WaitCursor;
					this.NewFile();
					break;
				case 1:
					AboutDialog myDlg = new AboutDialog();
					myDlg.ShowDialog(this);
					break;

				case 2: //just separator
					break;
				case 3:
					if (curForm == null)
						return;
                    curForm.currentDisplayMode = DisplayMode.WIREFRAME;
					this.wireframe.Enabled=false;
					this.shading.Enabled=true;
					this.transparency.Enabled=false;
					break;
				case 4:
					if (curForm == null)
						return;
                    curForm.currentDisplayMode = DisplayMode.SHADING;
					this.shading.Enabled=false;
					this.wireframe.Enabled=true;
					this.transparency.Enabled=true;
					break;
				case 5:
					if (curForm == null)
						return;
					curForm.ChangeColor(true);
					break;
				case 6:
					if (curForm == null)
						return;
					MaterialDialog m = new MaterialDialog();
					m.Viewer=curForm.Viewer;
					m.ShowDialog(curForm);
					break;
				case 7:
					if (curForm == null)
						return;
					siren.TransparencyDialog t = new TransparencyDialog();
					t.Viewer=curForm.Viewer;
					t.ShowDialog(curForm);
					break;
				case 8:
					if (curForm == null)
						return;
					curForm.DeleteObjects();
					break;
				default:
					break;
			}
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

		private void ViewerToolbar_Click(object sender, System.EventArgs e)
		{
			
			if (this.ViewerToolbar.Checked)
			{
				if (this.MdiChildren.Length > 0)
				{
					this.New.Visible=false;
					this.About.Visible=false;
				}
				else
					this.toolBarTool.Hide();
				this.ViewerToolbar.Checked=false;
			}
			else
			{
				if (this.MdiChildren.Length > 0)
				{
					this.New.Visible=true;
					this.About.Visible=true;
				} 
				else
					this.toolBarTool.Show();
				this.ViewerToolbar.Checked=true;
			}
			
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
            string str = System.String.Format(newForm.Text + " {0}: ビュー {1}", siren.MainForm.myNbOfChildren, 1);
            newForm.Text = str;
			newForm.Show();
			newForm.InitViewer();
			newForm.InitV3D();
			this.miView.Visible=true;
			this.wireframe.Visible=true;
			this.shading.Visible=true;
			this.color.Visible=true;
			this.material.Visible=true;
			this.transparency.Visible=true;
			this.delete.Visible=true;
			this.Cursor=System.Windows.Forms.Cursors.Default;
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
            newViewer.Viewer.CreateNewView(newViewer.cont.ContentPanel.Handle);
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

		public void SelectionChanged()
		{
			if (this.MdiChildren.Length == 0 )
				return;
			siren.ViewForm curForm = (siren.ViewForm) this.ActiveMdiChild;
			if ( curForm == null )
				return;
			switch (curForm.Viewer.DisplayMode())
				{
				case -1:
					this.shading.Enabled=false;
					this.wireframe.Enabled=false;
					break;
				case 0:
					this.wireframe.Enabled=false;
					this.shading.Enabled=true;
					this.transparency.Enabled=false;
					break;
				case 1:
					this.wireframe.Enabled=true;
					this.shading.Enabled=false;
					this.transparency.Enabled=true;
					break;
				case 10:
					this.wireframe.Enabled=true;
					this.shading.Enabled=true;
					this.transparency.Enabled=true;
					break;
				default:
					break;
				}
			bool IsSelected = curForm.Viewer.IsObjectSelected();
			if (IsSelected)
			{
				this.color.Enabled=true;
				this.material.Enabled=true;
				this.delete.Enabled=true;
			}
			else
			{
				this.color.Enabled=false;
				this.material.Enabled=false;
				this.transparency.Enabled=false;
				this.delete.Enabled=false;
			}

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
				this.wireframe.Visible=false;
				this.shading.Visible=false;
				this.color.Visible=false;
				this.material.Visible=false;
				this.transparency.Visible=false;
				this.delete.Visible=false;
			}
		}


		private void MainForm_Activated(object sender, System.EventArgs e)
		{
			//if (this.toolBarViewer.Visible)
			//	this.SelectionChanged();
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
			filter += "画像ファイル(*.bmp *.gif *.xwd)| *.bmp; *.gif; *.xwd";
			filter += "|BMP ファイル(*.bmp)|*.bmp";
			filter += "|GIF ファイル(*.gif)|*.gif";
			filter += "|XWD ァイル(*.xwd)|*.xwd";
			d.Filter = filter;

            d.Title = "スクリーンショットの保存";

            if (d.ShowDialog() != DialogResult.OK)
                return;

            SaveFile(d.FileName, ModelFormat.IMAGE);
        }

        private void miView_Paint(object sender, PaintEventArgs e)
        {
			siren.ViewForm curForm = (siren.ViewForm) this.ActiveMdiChild;
            miScreenShot.Enabled = (curForm != null);
        }


	}

}