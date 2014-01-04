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

        #region "イベント"

        void MainForm_Load(object sender, EventArgs e)
        {
            List<string> args = new List<string>(System.Environment.GetCommandLineArgs());
            // コマンドライン引数から開く
            args.RemoveAt(0); // 自身の呼び出しパス
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
        /// ツールバー状態の切り替え
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

		private void SaveFile_Click(object sender, System.EventArgs e)
		{
            SaveFile();
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
			this.Cursor=System.Windows.Forms.Cursors.Default;
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

        private void tsbExit_Click(object sender, EventArgs e)
        {
            this.Close();
            return;
        }

        private void tsbSave_Click(object sender, EventArgs e)
        {
            this.SaveFile();
        }

        private void tsbOpen_Click(object sender, EventArgs e)
        {
            this.OpenFile();
        }

        private void tsbNew_Click(object sender, EventArgs e)
        {
            this.NewFile();
        }

        private void tsbNewView_Click(object sender, EventArgs e)
        {
			this.Cursor = System.Windows.Forms.Cursors.WaitCursor;
            
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
            this.Cursor = System.Windows.Forms.Cursors.Default;
        }

        private void tsbCascade_Click(object sender, EventArgs e)
        {
			this.LayoutMdi(System.Windows.Forms.MdiLayout.Cascade);
        }

        private void tsbTile_Click(object sender, EventArgs e)
        {
			this.LayoutMdi(System.Windows.Forms.MdiLayout.TileVertical);
        }

        private void tsbDump_Click(object sender, EventArgs e)
        {
            SaveFileDialog d = new SaveFileDialog();
            d.RestoreDirectory = true;

            string filter = "";
			filter += "画像ファイル(*.bmp *.gif *.xwd)| *.bmp; *.gif; *.xwd";
			filter += "|BMP ファイル(*.bmp)|*.bmp";
			filter += "|GIF ファイル(*.gif)|*.gif";
			filter += "|XWD ファイル(*.xwd)|*.xwd";
			d.Filter = filter;

            d.Title = "スクリーンショットの保存";

            if (d.ShowDialog() != DialogResult.OK)
                return;

            SaveFile(d.FileName, ModelFormat.IMAGE);
        }

        private void tsbClose_Click(object sender, EventArgs e)
        {
		    ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            if (curForm != null)
                curForm.Close();
        }

        private void tsbDisplayMode_Click(object sender, EventArgs e)
        {
		    ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            if (curForm != null)
                curForm.toggleDisplayMode(); 
        }

        private void tsbDelete_Click(object sender, EventArgs e)
        {
		    ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            if (curForm != null)
                curForm.Viewer.EraseObjects();
        }

        private void tsbCopy_Click(object sender, EventArgs e)
        {
		    ViewForm curForm = (ViewForm) this.ActiveMdiChild;
            if (curForm != null)
            {
                curForm.getterm().execute("a = []; selected.each { |obj| a.push(copy(obj)) }");
            }
        }

	}

}