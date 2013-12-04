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
	/// <summary>
	/// Summary description for MainForm.
	/// </summary>
    public partial class MainForm : System.Windows.Forms.Form
    {
        private MenuStrip menu;
        private ToolStripMenuItem miFile;
        private ToolStripMenuItem miEdit;
        private ToolStripMenuItem miOption;
        private ToolStripMenuItem miTool;
        private ToolStripMenuItem miRuby;
        private ToolStripMenuItem miMode;
        private ToolStripMenuItem miView;
        private ToolStripMenuItem miHelp;
        private System.Windows.Forms.ToolStripMenuItem miFileNew;
        private System.Windows.Forms.ToolStripMenuItem miFileClose;
        private System.Windows.Forms.ToolStripMenuItem miOpen;
        private System.Windows.Forms.StatusStrip myStatusBar;
        private System.Windows.Forms.ToolStripMenuItem miSaveFile;
        //private System.ComponentModel.IContainer components;
        private System.Windows.Forms.ToolStripMenuItem miExit;
        private System.Windows.Forms.ToolStripMenuItem miAbout;
        private System.Windows.Forms.ToolStripMenuItem ViewerToolbar;
        private System.Windows.Forms.ToolStripMenuItem ViewerStatusBar;
        private System.Windows.Forms.ToolStripMenuItem menuItem4;
        private System.Windows.Forms.ToolStripMenuItem WindowCascade;
        private System.Windows.Forms.ToolStripMenuItem WindowTile;

        protected siren.ModelFormat myModelFormat;
        private ToolStripMenuItem menuItem15;
        private ToolStripMenuItem miSelectAll;
        private ToolStripMenuItem miUnselect;
        private ToolStripMenuItem miCopy;
        private ToolStripMenuItem miCut;
        private ToolStripMenuItem miPaste;
        private ToolStripMenuItem miDelete;
        private ToolStripMenuItem miObjectInfo;
        private ToolStripMenuItem miFileInfo;

        private ToolStripMenuItem miTranslate;
        private ToolStripMenuItem miScale;
        private ToolStripMenuItem miRotate;
        private ToolStripMenuItem miVertex;
        private ToolStripMenuItem miCurve;
        private ToolStripMenuItem miSurface;
        private ToolStripMenuItem miModule;
        private ToolStripMenuItem miRubyLicense;

        protected static int myNbOfChildren;

        public MainForm()
        {
            InitializeComponent();
        }

		protected override void Dispose( bool disposing )
		{
			//if( disposing ) {
			//	if(components != null) {
			//		components.Dispose();
			//	}
			//}
			base.Dispose( disposing );
		}

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.menu = new System.Windows.Forms.MenuStrip();
            this.miFile = new System.Windows.Forms.ToolStripMenuItem();
            this.miFileNew = new System.Windows.Forms.ToolStripMenuItem();
            this.miOpen = new System.Windows.Forms.ToolStripMenuItem();
            this.miSaveFile = new System.Windows.Forms.ToolStripMenuItem();
            this.miFileClose = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem12 = new System.Windows.Forms.ToolStripSeparator();
            this.menuItem15 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem19 = new System.Windows.Forms.ToolStripSeparator();
            this.miFileInfo = new System.Windows.Forms.ToolStripMenuItem();
            this.miNewViewer = new System.Windows.Forms.ToolStripSeparator();
            this.miExit = new System.Windows.Forms.ToolStripMenuItem();
            this.miEdit = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.miSelectAll = new System.Windows.Forms.ToolStripMenuItem();
            this.miUnselect = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem9 = new System.Windows.Forms.ToolStripSeparator();
            this.miCopy = new System.Windows.Forms.ToolStripMenuItem();
            this.miCut = new System.Windows.Forms.ToolStripMenuItem();
            this.miPaste = new System.Windows.Forms.ToolStripMenuItem();
            this.miDelete = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem16 = new System.Windows.Forms.ToolStripSeparator();
            this.miObjectInfo = new System.Windows.Forms.ToolStripMenuItem();
            this.miMode = new System.Windows.Forms.ToolStripMenuItem();
            this.miTranslate = new System.Windows.Forms.ToolStripMenuItem();
            this.miScale = new System.Windows.Forms.ToolStripMenuItem();
            this.miRotate = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem26 = new System.Windows.Forms.ToolStripSeparator();
            this.miVertex = new System.Windows.Forms.ToolStripMenuItem();
            this.miCurve = new System.Windows.Forms.ToolStripMenuItem();
            this.miSurface = new System.Windows.Forms.ToolStripMenuItem();
            this.miView = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripMenuItem();
            this.miScreenShot = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
            this.menuItem2 = new System.Windows.Forms.ToolStripSeparator();
            this.WindowCascade = new System.Windows.Forms.ToolStripMenuItem();
            this.WindowTile = new System.Windows.Forms.ToolStripMenuItem();
            this.miTool = new System.Windows.Forms.ToolStripMenuItem();
            this.miSolidModeler = new System.Windows.Forms.ToolStripMenuItem();
            this.miRuby = new System.Windows.Forms.ToolStripMenuItem();
            this.miModule = new System.Windows.Forms.ToolStripMenuItem();
            this.menuItem30 = new System.Windows.Forms.ToolStripSeparator();
            this.miRubyLicense = new System.Windows.Forms.ToolStripMenuItem();
            this.miDebug = new System.Windows.Forms.ToolStripMenuItem();
            this.miOption = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.ViewerToolbar = new System.Windows.Forms.ToolStripMenuItem();
            this.ViewerStatusBar = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.menuItem11 = new System.Windows.Forms.ToolStripMenuItem();
            this.miHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.miAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.myStatusBar = new System.Windows.Forms.StatusStrip();
            this.toolStripSplitButton1 = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripProgressBar1 = new System.Windows.Forms.ToolStripProgressBar();
            this.toolStripLabel2 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripPanel2 = new System.Windows.Forms.ToolStripPanel();
            this.toolStripMain = new System.Windows.Forms.ToolStrip();
            this.tsbBox = new System.Windows.Forms.ToolStripButton();
            this.tsbSphere = new System.Windows.Forms.ToolStripButton();
            this.tsbCylinder = new System.Windows.Forms.ToolStripButton();
            this.tsbCone = new System.Windows.Forms.ToolStripButton();
            this.tsbTorus = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbTranslate = new System.Windows.Forms.ToolStripButton();
            this.tsbRotate = new System.Windows.Forms.ToolStripButton();
            this.tsbScale = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton6 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbDisplayMode = new System.Windows.Forms.ToolStripButton();
            this.tsbTransparency = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbColor = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem5 = new System.Windows.Forms.ToolStripMenuItem();
            this.赤ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.青ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.緑ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.水色ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.紫ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.黄ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.黒ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tsbFit = new System.Windows.Forms.ToolStripButton();
            this.tsbBookmark = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripSeparator12 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbAxoView = new System.Windows.Forms.ToolStripSplitButton();
            this.正面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.背面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.左側面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.右側面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.上面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.下面ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator13 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbResetView = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator14 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbHlr = new System.Windows.Forms.ToolStripButton();
            this.tsbMaterial = new System.Windows.Forms.ToolStripSplitButton();
            this.miIrons = new System.Windows.Forms.ToolStripMenuItem();
            this.真鍮ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.アルミToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ブロンズToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.銅ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.金ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.スズToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.銀ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.スチールToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miStones = new System.Windows.Forms.ToolStripMenuItem();
            this.miStone = new System.Windows.Forms.ToolStripMenuItem();
            this.石膏ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.黒曜石ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.メタリックToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.翡翠ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miArtifacts = new System.Windows.Forms.ToolStripMenuItem();
            this.miPlastic = new System.Windows.Forms.ToolStripMenuItem();
            this.miPlastic2 = new System.Windows.Forms.ToolStripMenuItem();
            this.miSateen = new System.Windows.Forms.ToolStripMenuItem();
            this.miNeons = new System.Windows.Forms.ToolStripMenuItem();
            this.miPHC = new System.Windows.Forms.ToolStripMenuItem();
            this.miGNC = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem7 = new System.Windows.Forms.ToolStripSeparator();
            this.miDefault = new System.Windows.Forms.ToolStripMenuItem();
            this.menu.SuspendLayout();
            this.myStatusBar.SuspendLayout();
            this.toolStripPanel2.SuspendLayout();
            this.toolStripMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // menu
            // 
            this.menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miFile,
            this.miEdit,
            this.miMode,
            this.miView,
            this.miTool,
            this.miRuby,
            this.miOption,
            this.miHelp});
            this.menu.Location = new System.Drawing.Point(0, 0);
            this.menu.Name = "menu";
            this.menu.Size = new System.Drawing.Size(784, 26);
            this.menu.TabIndex = 3;
            // 
            // miFile
            // 
            this.miFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miFileNew,
            this.miOpen,
            this.miSaveFile,
            this.miFileClose,
            this.menuItem12,
            this.menuItem15,
            this.menuItem19,
            this.miFileInfo,
            this.miNewViewer,
            this.miExit});
            this.miFile.Name = "miFile";
            this.miFile.Size = new System.Drawing.Size(85, 22);
            this.miFile.Text = "ファイル(&F)";
            this.miFile.Paint += new System.Windows.Forms.PaintEventHandler(this.miFile_Paint);
            // 
            // miFileNew
            // 
            this.miFileNew.Image = ((System.Drawing.Image)(resources.GetObject("miFileNew.Image")));
            this.miFileNew.Name = "miFileNew";
            this.miFileNew.ShortcutKeyDisplayString = "";
            this.miFileNew.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N)));
            this.miFileNew.Size = new System.Drawing.Size(285, 22);
            this.miFileNew.Text = "新しいビューア(&N)";
            this.miFileNew.Click += new System.EventHandler(this.miNewViewer_Click);
            // 
            // miOpen
            // 
            this.miOpen.Image = ((System.Drawing.Image)(resources.GetObject("miOpen.Image")));
            this.miOpen.Name = "miOpen";
            this.miOpen.ShortcutKeyDisplayString = "";
            this.miOpen.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.miOpen.Size = new System.Drawing.Size(285, 22);
            this.miOpen.Text = "開く(&O)...";
            this.miOpen.Click += new System.EventHandler(this.miOpen_Click);
            // 
            // miSaveFile
            // 
            this.miSaveFile.Enabled = false;
            this.miSaveFile.Image = ((System.Drawing.Image)(resources.GetObject("miSaveFile.Image")));
            this.miSaveFile.Name = "miSaveFile";
            this.miSaveFile.ShortcutKeyDisplayString = "";
            this.miSaveFile.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.miSaveFile.Size = new System.Drawing.Size(285, 22);
            this.miSaveFile.Text = "選択オブジェクトを保存(&A)...";
            this.miSaveFile.Click += new System.EventHandler(this.SaveFile_Click);
            // 
            // miFileClose
            // 
            this.miFileClose.Enabled = false;
            this.miFileClose.Name = "miFileClose";
            this.miFileClose.ShortcutKeyDisplayString = "";
            this.miFileClose.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.W)));
            this.miFileClose.Size = new System.Drawing.Size(285, 22);
            this.miFileClose.Text = "閉じる(&C)";
            this.miFileClose.Click += new System.EventHandler(this.miClose_Click);
            // 
            // menuItem12
            // 
            this.menuItem12.Name = "menuItem12";
            this.menuItem12.Size = new System.Drawing.Size(282, 6);
            // 
            // menuItem15
            // 
            this.menuItem15.Enabled = false;
            this.menuItem15.Image = ((System.Drawing.Image)(resources.GetObject("menuItem15.Image")));
            this.menuItem15.Name = "menuItem15";
            this.menuItem15.ShortcutKeyDisplayString = "";
            this.menuItem15.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.P)));
            this.menuItem15.Size = new System.Drawing.Size(285, 22);
            this.menuItem15.Text = "印刷(&P)...";
            // 
            // menuItem19
            // 
            this.menuItem19.Name = "menuItem19";
            this.menuItem19.Size = new System.Drawing.Size(282, 6);
            // 
            // miFileInfo
            // 
            this.miFileInfo.Enabled = false;
            this.miFileInfo.Image = ((System.Drawing.Image)(resources.GetObject("miFileInfo.Image")));
            this.miFileInfo.Name = "miFileInfo";
            this.miFileInfo.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.P)));
            this.miFileInfo.Size = new System.Drawing.Size(285, 22);
            this.miFileInfo.Text = "ファイル情報(&I)...";
            // 
            // miNewViewer
            // 
            this.miNewViewer.Name = "miNewViewer";
            this.miNewViewer.Size = new System.Drawing.Size(282, 6);
            // 
            // miExit
            // 
            this.miExit.Image = ((System.Drawing.Image)(resources.GetObject("miExit.Image")));
            this.miExit.Name = "miExit";
            this.miExit.ShortcutKeyDisplayString = "";
            this.miExit.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Q)));
            this.miExit.Size = new System.Drawing.Size(285, 22);
            this.miExit.Text = "終了(&Q)";
            this.miExit.Click += new System.EventHandler(this.miExit_Click);
            // 
            // miEdit
            // 
            this.miEdit.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem2,
            this.toolStripMenuItem1,
            this.toolStripSeparator1,
            this.miSelectAll,
            this.miUnselect,
            this.toolStripSeparator2,
            this.toolStripMenuItem3,
            this.menuItem9,
            this.miCopy,
            this.miCut,
            this.miPaste,
            this.miDelete,
            this.menuItem16,
            this.miObjectInfo});
            this.miEdit.Name = "miEdit";
            this.miEdit.Size = new System.Drawing.Size(61, 22);
            this.miEdit.Text = "編集(&E)";
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Enabled = false;
            this.toolStripMenuItem2.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem2.Image")));
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.ShortcutKeyDisplayString = "";
            this.toolStripMenuItem2.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Z)));
            this.toolStripMenuItem2.Size = new System.Drawing.Size(281, 22);
            this.toolStripMenuItem2.Text = "元に戻す";
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Enabled = false;
            this.toolStripMenuItem1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem1.Image")));
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.ShortcutKeyDisplayString = "";
            this.toolStripMenuItem1.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.R)));
            this.toolStripMenuItem1.Size = new System.Drawing.Size(281, 22);
            this.toolStripMenuItem1.Text = "やり直し";
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(278, 6);
            // 
            // miSelectAll
            // 
            this.miSelectAll.Enabled = false;
            this.miSelectAll.Image = ((System.Drawing.Image)(resources.GetObject("miSelectAll.Image")));
            this.miSelectAll.Name = "miSelectAll";
            this.miSelectAll.ShortcutKeyDisplayString = "";
            this.miSelectAll.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.A)));
            this.miSelectAll.Size = new System.Drawing.Size(281, 22);
            this.miSelectAll.Text = "全て選択(&A)";
            // 
            // miUnselect
            // 
            this.miUnselect.Enabled = false;
            this.miUnselect.Name = "miUnselect";
            this.miUnselect.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift)
                        | System.Windows.Forms.Keys.A)));
            this.miUnselect.Size = new System.Drawing.Size(281, 22);
            this.miUnselect.Text = "選択解除(&U)";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(278, 6);
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Enabled = false;
            this.toolStripMenuItem3.Image = ((System.Drawing.Image)(resources.GetObject("toolStripMenuItem3.Image")));
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.ShortcutKeyDisplayString = "";
            this.toolStripMenuItem3.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.F)));
            this.toolStripMenuItem3.Size = new System.Drawing.Size(281, 22);
            this.toolStripMenuItem3.Text = "オブジェクトの検索(&F)...";
            // 
            // menuItem9
            // 
            this.menuItem9.Name = "menuItem9";
            this.menuItem9.Size = new System.Drawing.Size(278, 6);
            // 
            // miCopy
            // 
            this.miCopy.Enabled = false;
            this.miCopy.Image = ((System.Drawing.Image)(resources.GetObject("miCopy.Image")));
            this.miCopy.Name = "miCopy";
            this.miCopy.ShortcutKeyDisplayString = "";
            this.miCopy.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C)));
            this.miCopy.Size = new System.Drawing.Size(281, 22);
            this.miCopy.Text = "コピー(&C)";
            // 
            // miCut
            // 
            this.miCut.Enabled = false;
            this.miCut.Image = ((System.Drawing.Image)(resources.GetObject("miCut.Image")));
            this.miCut.Name = "miCut";
            this.miCut.ShortcutKeyDisplayString = "";
            this.miCut.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.X)));
            this.miCut.Size = new System.Drawing.Size(281, 22);
            this.miCut.Text = "切り取り(&X)";
            // 
            // miPaste
            // 
            this.miPaste.Enabled = false;
            this.miPaste.Image = ((System.Drawing.Image)(resources.GetObject("miPaste.Image")));
            this.miPaste.Name = "miPaste";
            this.miPaste.ShortcutKeyDisplayString = "";
            this.miPaste.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V)));
            this.miPaste.Size = new System.Drawing.Size(281, 22);
            this.miPaste.Text = "貼り付け(&V)";
            // 
            // miDelete
            // 
            this.miDelete.Enabled = false;
            this.miDelete.Image = ((System.Drawing.Image)(resources.GetObject("miDelete.Image")));
            this.miDelete.Name = "miDelete";
            this.miDelete.ShortcutKeyDisplayString = "";
            this.miDelete.ShortcutKeys = System.Windows.Forms.Keys.Delete;
            this.miDelete.Size = new System.Drawing.Size(281, 22);
            this.miDelete.Text = "削除(&D)";
            // 
            // menuItem16
            // 
            this.menuItem16.Name = "menuItem16";
            this.menuItem16.Size = new System.Drawing.Size(278, 6);
            // 
            // miObjectInfo
            // 
            this.miObjectInfo.Enabled = false;
            this.miObjectInfo.Name = "miObjectInfo";
            this.miObjectInfo.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.I)));
            this.miObjectInfo.Size = new System.Drawing.Size(281, 22);
            this.miObjectInfo.Text = "オブジェクトのプロパティ(&P)";
            // 
            // miMode
            // 
            this.miMode.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miTranslate,
            this.miScale,
            this.miRotate,
            this.menuItem26,
            this.miVertex,
            this.miCurve,
            this.miSurface});
            this.miMode.Name = "miMode";
            this.miMode.Size = new System.Drawing.Size(76, 22);
            this.miMode.Text = "モード(&M)";
            // 
            // miTranslate
            // 
            this.miTranslate.Enabled = false;
            this.miTranslate.Name = "miTranslate";
            this.miTranslate.ShortcutKeyDisplayString = "W";
            this.miTranslate.Size = new System.Drawing.Size(157, 22);
            this.miTranslate.Text = "移動(&T)";
            // 
            // miScale
            // 
            this.miScale.Enabled = false;
            this.miScale.Name = "miScale";
            this.miScale.ShortcutKeyDisplayString = "E";
            this.miScale.Size = new System.Drawing.Size(157, 22);
            this.miScale.Text = "スケール(&S)";
            // 
            // miRotate
            // 
            this.miRotate.Enabled = false;
            this.miRotate.Name = "miRotate";
            this.miRotate.ShortcutKeyDisplayString = "R";
            this.miRotate.Size = new System.Drawing.Size(157, 22);
            this.miRotate.Text = "回転(&R)";
            // 
            // menuItem26
            // 
            this.menuItem26.Name = "menuItem26";
            this.menuItem26.Size = new System.Drawing.Size(154, 6);
            // 
            // miVertex
            // 
            this.miVertex.Enabled = false;
            this.miVertex.Name = "miVertex";
            this.miVertex.Size = new System.Drawing.Size(157, 22);
            this.miVertex.Text = "点(&V)";
            // 
            // miCurve
            // 
            this.miCurve.Enabled = false;
            this.miCurve.Name = "miCurve";
            this.miCurve.Size = new System.Drawing.Size(157, 22);
            this.miCurve.Text = "カーブ(&C)";
            // 
            // miSurface
            // 
            this.miSurface.Enabled = false;
            this.miSurface.Name = "miSurface";
            this.miSurface.Size = new System.Drawing.Size(157, 22);
            this.miSurface.Text = "サーフェス(&U)";
            // 
            // miView
            // 
            this.miView.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuItem4,
            this.toolStripSeparator5,
            this.toolStripSeparator4,
            this.miScreenShot,
            this.toolStripSeparator7,
            this.menuItem2,
            this.WindowCascade,
            this.WindowTile});
            this.miView.Name = "miView";
            this.miView.Size = new System.Drawing.Size(78, 22);
            this.miView.Text = "ビュー(&W)";
            this.miView.Visible = false;
            this.miView.Paint += new System.Windows.Forms.PaintEventHandler(this.miView_Paint);
            // 
            // menuItem4
            // 
            this.menuItem4.Image = ((System.Drawing.Image)(resources.GetObject("menuItem4.Image")));
            this.menuItem4.Name = "menuItem4";
            this.menuItem4.ShortcutKeyDisplayString = "V";
            this.menuItem4.Size = new System.Drawing.Size(272, 22);
            this.menuItem4.Text = "新しいビュー(&N)";
            this.menuItem4.Click += new System.EventHandler(this.menuItem4_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(269, 6);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Enabled = false;
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.ShortcutKeyDisplayString = "F";
            this.toolStripSeparator4.Size = new System.Drawing.Size(272, 22);
            this.toolStripSeparator4.Text = "フィット(&F)";
            // 
            // miScreenShot
            // 
            this.miScreenShot.Name = "miScreenShot";
            this.miScreenShot.ShortcutKeys = System.Windows.Forms.Keys.F4;
            this.miScreenShot.Size = new System.Drawing.Size(272, 22);
            this.miScreenShot.Text = "スクリーンショットの保存(&S)...";
            this.miScreenShot.Click += new System.EventHandler(this.miScreenShot_Click);
            // 
            // toolStripSeparator7
            // 
            this.toolStripSeparator7.Name = "toolStripSeparator7";
            this.toolStripSeparator7.Size = new System.Drawing.Size(269, 6);
            // 
            // menuItem2
            // 
            this.menuItem2.Name = "menuItem2";
            this.menuItem2.Size = new System.Drawing.Size(269, 6);
            // 
            // WindowCascade
            // 
            this.WindowCascade.Image = ((System.Drawing.Image)(resources.GetObject("WindowCascade.Image")));
            this.WindowCascade.Name = "WindowCascade";
            this.WindowCascade.Size = new System.Drawing.Size(272, 22);
            this.WindowCascade.Text = "重ねて表示(&C)";
            this.WindowCascade.Click += new System.EventHandler(this.WindowCascade_Click);
            // 
            // WindowTile
            // 
            this.WindowTile.Name = "WindowTile";
            this.WindowTile.Size = new System.Drawing.Size(272, 22);
            this.WindowTile.Text = "並べて表示(&T)";
            this.WindowTile.Click += new System.EventHandler(this.WindowTile_Click);
            // 
            // miTool
            // 
            this.miTool.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miSolidModeler});
            this.miTool.Name = "miTool";
            this.miTool.Size = new System.Drawing.Size(74, 22);
            this.miTool.Text = "ツール(&T)";
            // 
            // miSolidModeler
            // 
            this.miSolidModeler.Enabled = false;
            this.miSolidModeler.Name = "miSolidModeler";
            this.miSolidModeler.Size = new System.Drawing.Size(206, 22);
            this.miSolidModeler.Text = "ソリッド モデラー(&S)...";
            // 
            // miRuby
            // 
            this.miRuby.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miModule,
            this.menuItem30,
            this.miRubyLicense,
            this.miDebug});
            this.miRuby.Name = "miRuby";
            this.miRuby.Size = new System.Drawing.Size(49, 22);
            this.miRuby.Text = "&Ruby";
            // 
            // miModule
            // 
            this.miModule.Enabled = false;
            this.miModule.Image = ((System.Drawing.Image)(resources.GetObject("miModule.Image")));
            this.miModule.Name = "miModule";
            this.miModule.Size = new System.Drawing.Size(237, 22);
            this.miModule.Text = "Ruby モジュールの管理(&M)...";
            // 
            // menuItem30
            // 
            this.menuItem30.Name = "menuItem30";
            this.menuItem30.Size = new System.Drawing.Size(234, 6);
            // 
            // miRubyLicense
            // 
            this.miRubyLicense.Enabled = false;
            this.miRubyLicense.Image = ((System.Drawing.Image)(resources.GetObject("miRubyLicense.Image")));
            this.miRubyLicense.Name = "miRubyLicense";
            this.miRubyLicense.Size = new System.Drawing.Size(237, 22);
            this.miRubyLicense.Text = "ライセンス情報(&L)...";
            // 
            // miDebug
            // 
            this.miDebug.Name = "miDebug";
            this.miDebug.Size = new System.Drawing.Size(237, 22);
            this.miDebug.Text = "Show &Terminal";
            this.miDebug.Click += new System.EventHandler(this.miDebug_Click);
            // 
            // miOption
            // 
            this.miOption.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSeparator3,
            this.ViewerToolbar,
            this.ViewerStatusBar,
            this.toolStripSeparator6,
            this.menuItem11});
            this.miOption.Name = "miOption";
            this.miOption.Size = new System.Drawing.Size(98, 22);
            this.miOption.Text = "オプション(&V)";
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(179, 6);
            // 
            // ViewerToolbar
            // 
            this.ViewerToolbar.Checked = true;
            this.ViewerToolbar.CheckState = System.Windows.Forms.CheckState.Checked;
            this.ViewerToolbar.Name = "ViewerToolbar";
            this.ViewerToolbar.Size = new System.Drawing.Size(182, 22);
            this.ViewerToolbar.Text = "ツールバー(&T)";
            // 
            // ViewerStatusBar
            // 
            this.ViewerStatusBar.Checked = true;
            this.ViewerStatusBar.CheckState = System.Windows.Forms.CheckState.Checked;
            this.ViewerStatusBar.Name = "ViewerStatusBar";
            this.ViewerStatusBar.Size = new System.Drawing.Size(182, 22);
            this.ViewerStatusBar.Text = "ステータスバー(&S)";
            this.ViewerStatusBar.Click += new System.EventHandler(this.ViewerStatusBar_Click);
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(179, 6);
            // 
            // menuItem11
            // 
            this.menuItem11.Enabled = false;
            this.menuItem11.Image = ((System.Drawing.Image)(resources.GetObject("menuItem11.Image")));
            this.menuItem11.Name = "menuItem11";
            this.menuItem11.ShortcutKeys = System.Windows.Forms.Keys.F10;
            this.menuItem11.Size = new System.Drawing.Size(182, 22);
            this.menuItem11.Text = "環境設定(&P)...";
            // 
            // miHelp
            // 
            this.miHelp.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miAbout});
            this.miHelp.Name = "miHelp";
            this.miHelp.Size = new System.Drawing.Size(75, 22);
            this.miHelp.Text = "ヘルプ(&H)";
            // 
            // miAbout
            // 
            this.miAbout.Image = ((System.Drawing.Image)(resources.GetObject("miAbout.Image")));
            this.miAbout.Name = "miAbout";
            this.miAbout.ShortcutKeys = System.Windows.Forms.Keys.F1;
            this.miAbout.Size = new System.Drawing.Size(200, 22);
            this.miAbout.Text = "バージョン情報(&A)";
            this.miAbout.Click += new System.EventHandler(this.HelpAbout_Click);
            // 
            // myStatusBar
            // 
            this.myStatusBar.AccessibleRole = System.Windows.Forms.AccessibleRole.StatusBar;
            this.myStatusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSplitButton1,
            this.toolStripStatusLabel1,
            this.toolStripProgressBar1});
            this.myStatusBar.Location = new System.Drawing.Point(0, 540);
            this.myStatusBar.Name = "myStatusBar";
            this.myStatusBar.Size = new System.Drawing.Size(784, 22);
            this.myStatusBar.TabIndex = 1;
            // 
            // toolStripSplitButton1
            // 
            this.toolStripSplitButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripSplitButton1.Image = ((System.Drawing.Image)(resources.GetObject("toolStripSplitButton1.Image")));
            this.toolStripSplitButton1.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripSplitButton1.Name = "toolStripSplitButton1";
            this.toolStripSplitButton1.Size = new System.Drawing.Size(32, 20);
            this.toolStripSplitButton1.Text = "toolStripSplitButton1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(635, 17);
            this.toolStripStatusLabel1.Spring = true;
            this.toolStripStatusLabel1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStripProgressBar1
            // 
            this.toolStripProgressBar1.Name = "toolStripProgressBar1";
            this.toolStripProgressBar1.Size = new System.Drawing.Size(100, 16);
            // 
            // toolStripLabel2
            // 
            this.toolStripLabel2.Name = "toolStripLabel2";
            this.toolStripLabel2.Size = new System.Drawing.Size(25, 23);
            this.toolStripLabel2.Text = "色:";
            // 
            // toolStripPanel2
            // 
            this.toolStripPanel2.Controls.Add(this.toolStripMain);
            this.toolStripPanel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.toolStripPanel2.Location = new System.Drawing.Point(0, 26);
            this.toolStripPanel2.Name = "toolStripPanel2";
            this.toolStripPanel2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            this.toolStripPanel2.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
            this.toolStripPanel2.Size = new System.Drawing.Size(784, 25);
            // 
            // toolStripMain
            // 
            this.toolStripMain.Dock = System.Windows.Forms.DockStyle.None;
            this.toolStripMain.Enabled = false;
            this.toolStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbBox,
            this.tsbSphere,
            this.tsbCylinder,
            this.tsbCone,
            this.tsbTorus,
            this.toolStripSeparator8,
            this.tsbTranslate,
            this.tsbRotate,
            this.tsbScale,
            this.toolStripButton6,
            this.tsbDisplayMode,
            this.tsbTransparency,
            this.toolStripSeparator10,
            this.tsbColor,
            this.tsbMaterial,
            this.tsbFit,
            this.tsbBookmark,
            this.toolStripSeparator12,
            this.tsbAxoView,
            this.toolStripSeparator13,
            this.tsbResetView,
            this.toolStripSeparator14,
            this.tsbHlr});
            this.toolStripMain.Location = new System.Drawing.Point(3, 0);
            this.toolStripMain.Name = "toolStripMain";
            this.toolStripMain.Size = new System.Drawing.Size(506, 25);
            this.toolStripMain.TabIndex = 14;
            // 
            // tsbBox
            // 
            this.tsbBox.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBox.Image = ((System.Drawing.Image)(resources.GetObject("tsbBox.Image")));
            this.tsbBox.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBox.Name = "tsbBox";
            this.tsbBox.Size = new System.Drawing.Size(23, 22);
            this.tsbBox.Text = "toolStripButton1";
            this.tsbBox.ToolTipText = "ボックス";
            this.tsbBox.Click += new System.EventHandler(this.tsbBox_Click);
            // 
            // tsbSphere
            // 
            this.tsbSphere.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbSphere.Image = ((System.Drawing.Image)(resources.GetObject("tsbSphere.Image")));
            this.tsbSphere.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbSphere.Name = "tsbSphere";
            this.tsbSphere.Size = new System.Drawing.Size(23, 22);
            this.tsbSphere.Text = "toolStripButton2";
            this.tsbSphere.ToolTipText = "スフィア";
            this.tsbSphere.Click += new System.EventHandler(this.tsbSphere_Click);
            // 
            // tsbCylinder
            // 
            this.tsbCylinder.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCylinder.Image = ((System.Drawing.Image)(resources.GetObject("tsbCylinder.Image")));
            this.tsbCylinder.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCylinder.Name = "tsbCylinder";
            this.tsbCylinder.Size = new System.Drawing.Size(23, 22);
            this.tsbCylinder.Text = "toolStripButton3";
            this.tsbCylinder.ToolTipText = "シリンダー";
            this.tsbCylinder.Click += new System.EventHandler(this.tsbCylinder_Click);
            // 
            // tsbCone
            // 
            this.tsbCone.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCone.Image = ((System.Drawing.Image)(resources.GetObject("tsbCone.Image")));
            this.tsbCone.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCone.Name = "tsbCone";
            this.tsbCone.Size = new System.Drawing.Size(23, 22);
            this.tsbCone.Text = "toolStripButton4";
            this.tsbCone.ToolTipText = "コーン";
            this.tsbCone.Click += new System.EventHandler(this.tsbCone_Click);
            // 
            // tsbTorus
            // 
            this.tsbTorus.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTorus.Image = ((System.Drawing.Image)(resources.GetObject("tsbTorus.Image")));
            this.tsbTorus.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTorus.Name = "tsbTorus";
            this.tsbTorus.Size = new System.Drawing.Size(23, 22);
            this.tsbTorus.Text = "toolStripButton5";
            this.tsbTorus.ToolTipText = "トーラス";
            this.tsbTorus.Click += new System.EventHandler(this.tsbTorus_Click);
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbTranslate
            // 
            this.tsbTranslate.CheckOnClick = true;
            this.tsbTranslate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTranslate.Image = ((System.Drawing.Image)(resources.GetObject("tsbTranslate.Image")));
            this.tsbTranslate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTranslate.Name = "tsbTranslate";
            this.tsbTranslate.Size = new System.Drawing.Size(23, 22);
            this.tsbTranslate.ToolTipText = "移動";
            // 
            // tsbRotate
            // 
            this.tsbRotate.CheckOnClick = true;
            this.tsbRotate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbRotate.Image = ((System.Drawing.Image)(resources.GetObject("tsbRotate.Image")));
            this.tsbRotate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbRotate.Name = "tsbRotate";
            this.tsbRotate.Size = new System.Drawing.Size(23, 22);
            this.tsbRotate.ToolTipText = "回転";
            // 
            // tsbScale
            // 
            this.tsbScale.CheckOnClick = true;
            this.tsbScale.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbScale.Image = ((System.Drawing.Image)(resources.GetObject("tsbScale.Image")));
            this.tsbScale.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbScale.Name = "tsbScale";
            this.tsbScale.Size = new System.Drawing.Size(23, 22);
            this.tsbScale.ToolTipText = "スケール";
            // 
            // toolStripButton6
            // 
            this.toolStripButton6.Name = "toolStripButton6";
            this.toolStripButton6.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbDisplayMode
            // 
            this.tsbDisplayMode.CheckOnClick = true;
            this.tsbDisplayMode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbDisplayMode.Image = ((System.Drawing.Image)(resources.GetObject("tsbDisplayMode.Image")));
            this.tsbDisplayMode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbDisplayMode.Name = "tsbDisplayMode";
            this.tsbDisplayMode.Size = new System.Drawing.Size(23, 22);
            this.tsbDisplayMode.Text = "toolStripButton1";
            this.tsbDisplayMode.ToolTipText = "シェーディング";
            // 
            // tsbTransparency
            // 
            this.tsbTransparency.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTransparency.Image = ((System.Drawing.Image)(resources.GetObject("tsbTransparency.Image")));
            this.tsbTransparency.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTransparency.Name = "tsbTransparency";
            this.tsbTransparency.Size = new System.Drawing.Size(23, 22);
            this.tsbTransparency.ToolTipText = "不透明度";
            this.tsbTransparency.Click += new System.EventHandler(this.tsbTransparency_Click);
            // 
            // toolStripSeparator10
            // 
            this.toolStripSeparator10.Name = "toolStripSeparator10";
            this.toolStripSeparator10.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbColor
            // 
            this.tsbColor.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem4,
            this.toolStripMenuItem5,
            this.赤ToolStripMenuItem,
            this.青ToolStripMenuItem,
            this.緑ToolStripMenuItem,
            this.水色ToolStripMenuItem,
            this.紫ToolStripMenuItem,
            this.黄ToolStripMenuItem,
            this.黒ToolStripMenuItem});
            this.tsbColor.Image = ((System.Drawing.Image)(resources.GetObject("tsbColor.Image")));
            this.tsbColor.Name = "tsbColor";
            this.tsbColor.Size = new System.Drawing.Size(32, 22);
            this.tsbColor.ButtonClick += new System.EventHandler(this.tsbColor_ButtonClick);
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(112, 22);
            this.toolStripMenuItem4.Text = "白";
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size(112, 22);
            this.toolStripMenuItem5.Text = "グレイ";
            // 
            // 赤ToolStripMenuItem
            // 
            this.赤ToolStripMenuItem.Name = "赤ToolStripMenuItem";
            this.赤ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.赤ToolStripMenuItem.Text = "赤";
            // 
            // 青ToolStripMenuItem
            // 
            this.青ToolStripMenuItem.Name = "青ToolStripMenuItem";
            this.青ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.青ToolStripMenuItem.Text = "青";
            // 
            // 緑ToolStripMenuItem
            // 
            this.緑ToolStripMenuItem.Name = "緑ToolStripMenuItem";
            this.緑ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.緑ToolStripMenuItem.Text = "緑";
            // 
            // 水色ToolStripMenuItem
            // 
            this.水色ToolStripMenuItem.Name = "水色ToolStripMenuItem";
            this.水色ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.水色ToolStripMenuItem.Text = "水色";
            // 
            // 紫ToolStripMenuItem
            // 
            this.紫ToolStripMenuItem.Name = "紫ToolStripMenuItem";
            this.紫ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.紫ToolStripMenuItem.Text = "紫";
            // 
            // 黄ToolStripMenuItem
            // 
            this.黄ToolStripMenuItem.Name = "黄ToolStripMenuItem";
            this.黄ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.黄ToolStripMenuItem.Text = "黄";
            // 
            // 黒ToolStripMenuItem
            // 
            this.黒ToolStripMenuItem.Name = "黒ToolStripMenuItem";
            this.黒ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.黒ToolStripMenuItem.Text = "黒";
            // 
            // tsbFit
            // 
            this.tsbFit.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbFit.Image = ((System.Drawing.Image)(resources.GetObject("tsbFit.Image")));
            this.tsbFit.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbFit.Name = "tsbFit";
            this.tsbFit.Size = new System.Drawing.Size(23, 22);
            this.tsbFit.Text = "フィット";
            this.tsbFit.Click += new System.EventHandler(this.tsbFit_Click);
            // 
            // tsbBookmark
            // 
            this.tsbBookmark.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBookmark.Enabled = false;
            this.tsbBookmark.Image = ((System.Drawing.Image)(resources.GetObject("tsbBookmark.Image")));
            this.tsbBookmark.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBookmark.Name = "tsbBookmark";
            this.tsbBookmark.Size = new System.Drawing.Size(32, 22);
            this.tsbBookmark.Text = "toolStripButton11";
            this.tsbBookmark.ToolTipText = "ブックマーク";
            // 
            // toolStripSeparator12
            // 
            this.toolStripSeparator12.Name = "toolStripSeparator12";
            this.toolStripSeparator12.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbAxoView
            // 
            this.tsbAxoView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbAxoView.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.正面ToolStripMenuItem,
            this.背面ToolStripMenuItem,
            this.左側面ToolStripMenuItem,
            this.右側面ToolStripMenuItem,
            this.上面ToolStripMenuItem,
            this.下面ToolStripMenuItem});
            this.tsbAxoView.Image = ((System.Drawing.Image)(resources.GetObject("tsbAxoView.Image")));
            this.tsbAxoView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbAxoView.Name = "tsbAxoView";
            this.tsbAxoView.Size = new System.Drawing.Size(32, 22);
            this.tsbAxoView.Text = "toolStripButton10";
            this.tsbAxoView.ToolTipText = "視点";
            // 
            // 正面ToolStripMenuItem
            // 
            this.正面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("正面ToolStripMenuItem.Image")));
            this.正面ToolStripMenuItem.Name = "正面ToolStripMenuItem";
            this.正面ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.正面ToolStripMenuItem.Text = "正面";
            // 
            // 背面ToolStripMenuItem
            // 
            this.背面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("背面ToolStripMenuItem.Image")));
            this.背面ToolStripMenuItem.Name = "背面ToolStripMenuItem";
            this.背面ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.背面ToolStripMenuItem.Text = "背面";
            // 
            // 左側面ToolStripMenuItem
            // 
            this.左側面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("左側面ToolStripMenuItem.Image")));
            this.左側面ToolStripMenuItem.Name = "左側面ToolStripMenuItem";
            this.左側面ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.左側面ToolStripMenuItem.Text = "左側面";
            // 
            // 右側面ToolStripMenuItem
            // 
            this.右側面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("右側面ToolStripMenuItem.Image")));
            this.右側面ToolStripMenuItem.Name = "右側面ToolStripMenuItem";
            this.右側面ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.右側面ToolStripMenuItem.Text = "右側面";
            // 
            // 上面ToolStripMenuItem
            // 
            this.上面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("上面ToolStripMenuItem.Image")));
            this.上面ToolStripMenuItem.Name = "上面ToolStripMenuItem";
            this.上面ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.上面ToolStripMenuItem.Text = "上面";
            // 
            // 下面ToolStripMenuItem
            // 
            this.下面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("下面ToolStripMenuItem.Image")));
            this.下面ToolStripMenuItem.Name = "下面ToolStripMenuItem";
            this.下面ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.下面ToolStripMenuItem.Text = "下面";
            // 
            // toolStripSeparator13
            // 
            this.toolStripSeparator13.Name = "toolStripSeparator13";
            this.toolStripSeparator13.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbResetView
            // 
            this.tsbResetView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbResetView.Image = ((System.Drawing.Image)(resources.GetObject("tsbResetView.Image")));
            this.tsbResetView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbResetView.Name = "tsbResetView";
            this.tsbResetView.Size = new System.Drawing.Size(23, 22);
            this.tsbResetView.Text = "ビューをリセット";
            // 
            // toolStripSeparator14
            // 
            this.toolStripSeparator14.Name = "toolStripSeparator14";
            this.toolStripSeparator14.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbHlr
            // 
            this.tsbHlr.CheckOnClick = true;
            this.tsbHlr.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHlr.Image = ((System.Drawing.Image)(resources.GetObject("tsbHlr.Image")));
            this.tsbHlr.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHlr.Name = "tsbHlr";
            this.tsbHlr.Size = new System.Drawing.Size(23, 22);
            this.tsbHlr.ToolTipText = "隠面消去";
            // 
            // tsbMaterial
            // 
            this.tsbMaterial.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miIrons,
            this.miStones,
            this.miArtifacts,
            this.miNeons,
            this.toolStripMenuItem7,
            this.miDefault});
            this.tsbMaterial.Image = ((System.Drawing.Image)(resources.GetObject("tsbMaterial.Image")));
            this.tsbMaterial.Name = "tsbMaterial";
            this.tsbMaterial.Size = new System.Drawing.Size(32, 22);
            // 
            // miIrons
            // 
            this.miIrons.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.真鍮ToolStripMenuItem,
            this.スチールToolStripMenuItem,
            this.銀ToolStripMenuItem,
            this.スズToolStripMenuItem,
            this.金ToolStripMenuItem,
            this.銅ToolStripMenuItem,
            this.ブロンズToolStripMenuItem,
            this.アルミToolStripMenuItem,
            this.メタリックToolStripMenuItem});
            this.miIrons.Name = "miIrons";
            this.miIrons.Size = new System.Drawing.Size(155, 22);
            this.miIrons.Text = "金属(&I)";
            // 
            // 真鍮ToolStripMenuItem
            // 
            this.真鍮ToolStripMenuItem.Name = "真鍮ToolStripMenuItem";
            this.真鍮ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.真鍮ToolStripMenuItem.Text = "真鍮";
            // 
            // アルミToolStripMenuItem
            // 
            this.アルミToolStripMenuItem.Name = "アルミToolStripMenuItem";
            this.アルミToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.アルミToolStripMenuItem.Text = "アルミ";
            // 
            // ブロンズToolStripMenuItem
            // 
            this.ブロンズToolStripMenuItem.Name = "ブロンズToolStripMenuItem";
            this.ブロンズToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.ブロンズToolStripMenuItem.Text = "ブロンズ";
            // 
            // 銅ToolStripMenuItem
            // 
            this.銅ToolStripMenuItem.Name = "銅ToolStripMenuItem";
            this.銅ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.銅ToolStripMenuItem.Text = "銅";
            // 
            // 金ToolStripMenuItem
            // 
            this.金ToolStripMenuItem.Name = "金ToolStripMenuItem";
            this.金ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.金ToolStripMenuItem.Text = "金";
            // 
            // スズToolStripMenuItem
            // 
            this.スズToolStripMenuItem.Name = "スズToolStripMenuItem";
            this.スズToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.スズToolStripMenuItem.Text = "スズ";
            // 
            // 銀ToolStripMenuItem
            // 
            this.銀ToolStripMenuItem.Name = "銀ToolStripMenuItem";
            this.銀ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.銀ToolStripMenuItem.Text = "銀";
            // 
            // スチールToolStripMenuItem
            // 
            this.スチールToolStripMenuItem.Name = "スチールToolStripMenuItem";
            this.スチールToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.スチールToolStripMenuItem.Text = "スチール";
            // 
            // miStones
            // 
            this.miStones.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miStone,
            this.石膏ToolStripMenuItem,
            this.黒曜石ToolStripMenuItem,
            this.翡翠ToolStripMenuItem});
            this.miStones.Name = "miStones";
            this.miStones.Size = new System.Drawing.Size(155, 22);
            this.miStones.Text = "石(&S)";
            // 
            // miStone
            // 
            this.miStone.Name = "miStone";
            this.miStone.Size = new System.Drawing.Size(152, 22);
            this.miStone.Text = "石";
            // 
            // 石膏ToolStripMenuItem
            // 
            this.石膏ToolStripMenuItem.Name = "石膏ToolStripMenuItem";
            this.石膏ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.石膏ToolStripMenuItem.Text = "石膏";
            // 
            // 黒曜石ToolStripMenuItem
            // 
            this.黒曜石ToolStripMenuItem.Name = "黒曜石ToolStripMenuItem";
            this.黒曜石ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.黒曜石ToolStripMenuItem.Text = "黒曜石";
            // 
            // メタリックToolStripMenuItem
            // 
            this.メタリックToolStripMenuItem.Name = "メタリックToolStripMenuItem";
            this.メタリックToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.メタリックToolStripMenuItem.Text = "メタリック";
            // 
            // 翡翠ToolStripMenuItem
            // 
            this.翡翠ToolStripMenuItem.Name = "翡翠ToolStripMenuItem";
            this.翡翠ToolStripMenuItem.Size = new System.Drawing.Size(152, 22);
            this.翡翠ToolStripMenuItem.Text = "翡翠";
            // 
            // miArtifacts
            // 
            this.miArtifacts.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miPlastic,
            this.miPlastic2,
            this.miSateen});
            this.miArtifacts.Name = "miArtifacts";
            this.miArtifacts.Size = new System.Drawing.Size(155, 22);
            this.miArtifacts.Text = "人工物(&A)";
            // 
            // miPlastic
            // 
            this.miPlastic.Name = "miPlastic";
            this.miPlastic.Size = new System.Drawing.Size(182, 22);
            this.miPlastic.Text = "プラスチック";
            // 
            // miPlastic2
            // 
            this.miPlastic2.Name = "miPlastic2";
            this.miPlastic2.Size = new System.Drawing.Size(182, 22);
            this.miPlastic2.Text = "プラスチック(光沢)";
            // 
            // miSateen
            // 
            this.miSateen.Name = "miSateen";
            this.miSateen.Size = new System.Drawing.Size(182, 22);
            this.miSateen.Text = "サテン";
            // 
            // miNeons
            // 
            this.miNeons.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miPHC,
            this.miGNC});
            this.miNeons.Name = "miNeons";
            this.miNeons.Size = new System.Drawing.Size(155, 22);
            this.miNeons.Text = "ネオン(&N)";
            // 
            // miPHC
            // 
            this.miPHC.Name = "miPHC";
            this.miPHC.Size = new System.Drawing.Size(152, 22);
            this.miPHC.Text = "ネオンPHC";
            // 
            // miGNC
            // 
            this.miGNC.Name = "miGNC";
            this.miGNC.Size = new System.Drawing.Size(152, 22);
            this.miGNC.Text = "ネオンGNC";
            // 
            // toolStripMenuItem7
            // 
            this.toolStripMenuItem7.Name = "toolStripMenuItem7";
            this.toolStripMenuItem7.Size = new System.Drawing.Size(152, 6);
            // 
            // miDefault
            // 
            this.miDefault.Name = "miDefault";
            this.miDefault.Size = new System.Drawing.Size(155, 22);
            this.miDefault.Text = "デフォルト(&D)";
            // 
            // MainForm
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Application;
            this.AllowDrop = true;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
            this.ClientSize = new System.Drawing.Size(784, 562);
            this.Controls.Add(this.toolStripPanel2);
            this.Controls.Add(this.myStatusBar);
            this.Controls.Add(this.menu);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menu;
            this.Name = "MainForm";
            this.Text = "siren";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.DragDrop += new System.Windows.Forms.DragEventHandler(this.MainForm_DragDrop);
            this.DragEnter += new System.Windows.Forms.DragEventHandler(this.MainForm_DragEnter);
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.myStatusBar.ResumeLayout(false);
            this.myStatusBar.PerformLayout();
            this.toolStripPanel2.ResumeLayout(false);
            this.toolStripPanel2.PerformLayout();
            this.toolStripMain.ResumeLayout(false);
            this.toolStripMain.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private ToolStripSeparator menuItem12;
        private ToolStripSeparator menuItem19;
        private ToolStripSeparator miNewViewer;
        private ToolStripSeparator menuItem9;
        private ToolStripSeparator menuItem16;
        private ToolStripSeparator menuItem26;
        private ToolStripSeparator menuItem30;
        private ToolStripSeparator menuItem2;
        private ToolStripMenuItem toolStripMenuItem2;
        private ToolStripMenuItem toolStripMenuItem1;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripSeparator toolStripSeparator2;
        private ToolStripMenuItem toolStripMenuItem3;
        private ToolStripSeparator toolStripSeparator3;
        private ToolStripSplitButton toolStripSplitButton1;
        private ToolStripStatusLabel toolStripStatusLabel1;
        private ToolStripProgressBar toolStripProgressBar1;
        private ToolStripSeparator toolStripSeparator5;
        private ToolStripMenuItem miScreenShot;
        private ToolStripMenuItem toolStripSeparator4;
        private ToolStripSeparator toolStripSeparator6;
        private ToolStripMenuItem menuItem11;
        private ToolStripMenuItem miSolidModeler;
        private ToolStripSeparator toolStripSeparator7;
        private ToolStripMenuItem miDebug;
        private ToolStripLabel toolStripLabel2;
        private ToolStripPanel toolStripPanel2;
        private ToolStripButton tsbDisplayMode;
        private ToolStripSeparator toolStripSeparator10;
        private ToolStripButton tsbTransparency;
        private ToolStrip toolStripMain;
        private ToolStripButton tsbBox;
        private ToolStripButton tsbSphere;
        private ToolStripButton tsbCylinder;
        private ToolStripButton tsbCone;
        private ToolStripButton tsbTorus;
        private ToolStripSeparator toolStripButton6;
        private ToolStripButton tsbFit;
        private ToolStripSplitButton tsbBookmark;
        private ToolStripSeparator toolStripSeparator12;
        private ToolStripSeparator toolStripSeparator13;
        private ToolStripButton tsbResetView;
        private ToolStripSeparator toolStripSeparator14;
        private ToolStripButton tsbHlr;
        private ToolStripSplitButton tsbAxoView;
        private ToolStripMenuItem 正面ToolStripMenuItem;
        private ToolStripMenuItem 背面ToolStripMenuItem;
        private ToolStripMenuItem 左側面ToolStripMenuItem;
        private ToolStripMenuItem 右側面ToolStripMenuItem;
        private ToolStripMenuItem 上面ToolStripMenuItem;
        private ToolStripMenuItem 下面ToolStripMenuItem;
        private ToolStripSeparator toolStripSeparator8;
        private ToolStripButton tsbTranslate;
        private ToolStripButton tsbRotate;
        private ToolStripButton tsbScale;
        private ToolStripSplitButton tsbColor;
        private ToolStripMenuItem toolStripMenuItem4;
        private ToolStripMenuItem toolStripMenuItem5;
        private ToolStripMenuItem 赤ToolStripMenuItem;
        private ToolStripMenuItem 青ToolStripMenuItem;
        private ToolStripMenuItem 緑ToolStripMenuItem;
        private ToolStripMenuItem 水色ToolStripMenuItem;
        private ToolStripMenuItem 紫ToolStripMenuItem;
        private ToolStripMenuItem 黄ToolStripMenuItem;
        private ToolStripMenuItem 黒ToolStripMenuItem;
        private ToolStripSplitButton tsbMaterial;
        private ToolStripMenuItem miIrons;
        private ToolStripMenuItem 真鍮ToolStripMenuItem;
        private ToolStripMenuItem スチールToolStripMenuItem;
        private ToolStripMenuItem 銀ToolStripMenuItem;
        private ToolStripMenuItem スズToolStripMenuItem;
        private ToolStripMenuItem 金ToolStripMenuItem;
        private ToolStripMenuItem 銅ToolStripMenuItem;
        private ToolStripMenuItem ブロンズToolStripMenuItem;
        private ToolStripMenuItem アルミToolStripMenuItem;
        private ToolStripMenuItem miStones;
        private ToolStripMenuItem miStone;
        private ToolStripMenuItem 石膏ToolStripMenuItem;
        private ToolStripMenuItem 黒曜石ToolStripMenuItem;
        private ToolStripMenuItem メタリックToolStripMenuItem;
        private ToolStripMenuItem 翡翠ToolStripMenuItem;
        private ToolStripMenuItem miArtifacts;
        private ToolStripMenuItem miPlastic;
        private ToolStripMenuItem miPlastic2;
        private ToolStripMenuItem miSateen;
        private ToolStripMenuItem miNeons;
        private ToolStripMenuItem miPHC;
        private ToolStripMenuItem miGNC;
        private ToolStripSeparator toolStripMenuItem7;
        private ToolStripMenuItem miDefault;

    }
}
