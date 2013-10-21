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
        private System.Windows.Forms.ToolBarButton New;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.ToolBarButton About;
        private System.Windows.Forms.StatusStrip myStatusBar;
        private System.Windows.Forms.ToolStripMenuItem miSaveFile;
        private System.ComponentModel.IContainer components;
        private System.Windows.Forms.ToolStripMenuItem miExit;
        private System.Windows.Forms.ToolStripMenuItem miAbout;
        private System.Windows.Forms.ToolStripMenuItem ViewerToolbar;
        private System.Windows.Forms.ToolStripMenuItem ViewerStatusBar;
        private System.Windows.Forms.ToolStripMenuItem menuItem4;
        private System.Windows.Forms.ToolStripMenuItem WindowCascade;
        private System.Windows.Forms.ToolStripMenuItem WindowTile;

        protected siren.ModelFormat myModelFormat;
        private System.Windows.Forms.ToolBarButton wireframe;
        private System.Windows.Forms.ToolBarButton shading;
        private System.Windows.Forms.ToolBarButton toolBarButton1;
        private System.Windows.Forms.ToolBarButton color;
        private System.Windows.Forms.ToolBarButton transparency;
        private System.Windows.Forms.ToolBarButton delete;
        private System.Windows.Forms.ToolBarButton material;
        private System.Windows.Forms.ToolBar toolBarTool;
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
			if( disposing ) {
				if(components != null) {
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            System.Configuration.AppSettingsReader configurationAppSettings = new System.Configuration.AppSettingsReader();
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
            this.miOption = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.ViewerToolbar = new System.Windows.Forms.ToolStripMenuItem();
            this.ViewerStatusBar = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.menuItem11 = new System.Windows.Forms.ToolStripMenuItem();
            this.miHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.miAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.toolBarTool = new System.Windows.Forms.ToolBar();
            this.New = new System.Windows.Forms.ToolBarButton();
            this.About = new System.Windows.Forms.ToolBarButton();
            this.toolBarButton1 = new System.Windows.Forms.ToolBarButton();
            this.wireframe = new System.Windows.Forms.ToolBarButton();
            this.shading = new System.Windows.Forms.ToolBarButton();
            this.color = new System.Windows.Forms.ToolBarButton();
            this.material = new System.Windows.Forms.ToolBarButton();
            this.transparency = new System.Windows.Forms.ToolBarButton();
            this.delete = new System.Windows.Forms.ToolBarButton();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.myStatusBar = new System.Windows.Forms.StatusStrip();
            this.toolStripSplitButton1 = new System.Windows.Forms.ToolStripSplitButton();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripProgressBar1 = new System.Windows.Forms.ToolStripProgressBar();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.tsbNewFile = new System.Windows.Forms.ToolStripButton();
            this.tsbOpenFile = new System.Windows.Forms.ToolStripButton();
            this.tsbSaveFile = new System.Windows.Forms.ToolStripButton();
            this.tsbPrint = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this.tsbCut = new System.Windows.Forms.ToolStripButton();
            this.tsbCopy = new System.Windows.Forms.ToolStripButton();
            this.tsbPaste = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbHelp = new System.Windows.Forms.ToolStripButton();
            this.menu.SuspendLayout();
            this.myStatusBar.SuspendLayout();
            this.toolStrip1.SuspendLayout();
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
            this.menu.Size = new System.Drawing.Size(1024, 26);
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
            this.miExit.Image = ((System.Drawing.Image)(resources.GetObject("menuItem1.Image")));
            this.miExit.Name = "menuItem1";
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
            this.miRubyLicense});
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
            this.ViewerToolbar.Click += new System.EventHandler(this.ViewerToolbar_Click);
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
            // toolBarTool
            // 
            this.toolBarTool.AccessibleRole = System.Windows.Forms.AccessibleRole.ToolBar;
            this.toolBarTool.Buttons.AddRange(new System.Windows.Forms.ToolBarButton[] {
            this.New,
            this.About,
            this.toolBarButton1,
            this.wireframe,
            this.shading,
            this.color,
            this.material,
            this.transparency,
            this.delete});
            this.toolBarTool.DropDownArrows = true;
            this.toolBarTool.ImageList = this.imageList1;
            this.toolBarTool.Location = new System.Drawing.Point(0, 26);
            this.toolBarTool.Name = "toolBarTool";
            this.toolBarTool.ShowToolTips = true;
            this.toolBarTool.Size = new System.Drawing.Size(1024, 28);
            this.toolBarTool.TabIndex = 2;
            this.toolBarTool.ButtonClick += new System.Windows.Forms.ToolBarButtonClickEventHandler(this.toolBar1_ButtonClick);
            this.toolBarTool.Enter += new System.EventHandler(this.miClose_Click);
            // 
            // New
            // 
            this.New.ImageIndex = 0;
            this.New.Name = "New";
            this.New.ToolTipText = "New";
            this.New.Visible = ((bool)(configurationAppSettings.GetValue("New.Visible", typeof(bool))));
            // 
            // About
            // 
            this.About.ImageIndex = 1;
            this.About.Name = "About";
            this.About.ToolTipText = "About(F1)";
            this.About.Visible = ((bool)(configurationAppSettings.GetValue("About.Visible", typeof(bool))));
            // 
            // toolBarButton1
            // 
            this.toolBarButton1.Name = "toolBarButton1";
            this.toolBarButton1.Style = System.Windows.Forms.ToolBarButtonStyle.Separator;
            // 
            // wireframe
            // 
            this.wireframe.Enabled = ((bool)(configurationAppSettings.GetValue("wireframe.Enabled", typeof(bool))));
            this.wireframe.ImageIndex = 2;
            this.wireframe.Name = "wireframe";
            this.wireframe.Pushed = ((bool)(configurationAppSettings.GetValue("wireframe.Pushed", typeof(bool))));
            this.wireframe.ToolTipText = "Wireframe";
            this.wireframe.Visible = ((bool)(configurationAppSettings.GetValue("wireframe.Visible", typeof(bool))));
            // 
            // shading
            // 
            this.shading.Enabled = ((bool)(configurationAppSettings.GetValue("shading.Enabled", typeof(bool))));
            this.shading.ImageIndex = 3;
            this.shading.Name = "shading";
            this.shading.Pushed = ((bool)(configurationAppSettings.GetValue("shading.Pushed", typeof(bool))));
            this.shading.ToolTipText = "Shading";
            this.shading.Visible = ((bool)(configurationAppSettings.GetValue("shading.Visible", typeof(bool))));
            // 
            // color
            // 
            this.color.Enabled = ((bool)(configurationAppSettings.GetValue("color.Enabled", typeof(bool))));
            this.color.ImageIndex = 4;
            this.color.Name = "color";
            this.color.ToolTipText = "Color";
            this.color.Visible = ((bool)(configurationAppSettings.GetValue("color.Visible", typeof(bool))));
            // 
            // material
            // 
            this.material.Enabled = ((bool)(configurationAppSettings.GetValue("material.Enabled", typeof(bool))));
            this.material.ImageIndex = 5;
            this.material.Name = "material";
            this.material.ToolTipText = "Material";
            this.material.Visible = ((bool)(configurationAppSettings.GetValue("material.Visible", typeof(bool))));
            // 
            // transparency
            // 
            this.transparency.Enabled = ((bool)(configurationAppSettings.GetValue("transparency.Enabled", typeof(bool))));
            this.transparency.ImageIndex = 6;
            this.transparency.Name = "transparency";
            this.transparency.ToolTipText = "Transparency";
            this.transparency.Visible = ((bool)(configurationAppSettings.GetValue("transparency.Visible", typeof(bool))));
            // 
            // delete
            // 
            this.delete.Enabled = ((bool)(configurationAppSettings.GetValue("delete.Enabled", typeof(bool))));
            this.delete.ImageIndex = 7;
            this.delete.Name = "delete";
            this.delete.ToolTipText = "Delete";
            this.delete.Visible = ((bool)(configurationAppSettings.GetValue("delete.Visible", typeof(bool))));
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "");
            this.imageList1.Images.SetKeyName(1, "");
            this.imageList1.Images.SetKeyName(2, "");
            this.imageList1.Images.SetKeyName(3, "");
            this.imageList1.Images.SetKeyName(4, "");
            this.imageList1.Images.SetKeyName(5, "");
            this.imageList1.Images.SetKeyName(6, "");
            this.imageList1.Images.SetKeyName(7, "");
            this.imageList1.Images.SetKeyName(8, "");
            this.imageList1.Images.SetKeyName(9, "");
            this.imageList1.Images.SetKeyName(10, "");
            this.imageList1.Images.SetKeyName(11, "");
            this.imageList1.Images.SetKeyName(12, "");
            this.imageList1.Images.SetKeyName(13, "");
            this.imageList1.Images.SetKeyName(14, "");
            this.imageList1.Images.SetKeyName(15, "");
            this.imageList1.Images.SetKeyName(16, "");
            this.imageList1.Images.SetKeyName(17, "");
            this.imageList1.Images.SetKeyName(18, "");
            this.imageList1.Images.SetKeyName(19, "");
            this.imageList1.Images.SetKeyName(20, "");
            this.imageList1.Images.SetKeyName(21, "");
            this.imageList1.Images.SetKeyName(22, "");
            this.imageList1.Images.SetKeyName(23, "");
            // 
            // myStatusBar
            // 
            this.myStatusBar.AccessibleRole = System.Windows.Forms.AccessibleRole.StatusBar;
            this.myStatusBar.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripSplitButton1,
            this.toolStripStatusLabel1,
            this.toolStripProgressBar1});
            this.myStatusBar.Location = new System.Drawing.Point(0, 725);
            this.myStatusBar.Name = "myStatusBar";
            this.myStatusBar.Size = new System.Drawing.Size(1024, 22);
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
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(875, 17);
            this.toolStripStatusLabel1.Spring = true;
            this.toolStripStatusLabel1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // toolStripProgressBar1
            // 
            this.toolStripProgressBar1.Name = "toolStripProgressBar1";
            this.toolStripProgressBar1.Size = new System.Drawing.Size(100, 16);
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbNewFile,
            this.tsbOpenFile,
            this.tsbSaveFile,
            this.tsbPrint,
            this.toolStripSeparator,
            this.tsbCut,
            this.tsbCopy,
            this.tsbPaste,
            this.toolStripSeparator8,
            this.tsbHelp});
            this.toolStrip1.Location = new System.Drawing.Point(0, 54);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(1024, 25);
            this.toolStrip1.TabIndex = 5;
            this.toolStrip1.Text = "toolStrip1";
            this.toolStrip1.Visible = false;
            // 
            // tsbNewFile
            // 
            this.tsbNewFile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbNewFile.Image = ((System.Drawing.Image)(resources.GetObject("tsbNewFile.Image")));
            this.tsbNewFile.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbNewFile.Name = "tsbNewFile";
            this.tsbNewFile.Size = new System.Drawing.Size(23, 22);
            this.tsbNewFile.Text = "新規作成(&N)";
            // 
            // tsbOpenFile
            // 
            this.tsbOpenFile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbOpenFile.Image = ((System.Drawing.Image)(resources.GetObject("tsbOpenFile.Image")));
            this.tsbOpenFile.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbOpenFile.Name = "tsbOpenFile";
            this.tsbOpenFile.Size = new System.Drawing.Size(23, 22);
            this.tsbOpenFile.Text = "開く(&O)";
            // 
            // tsbSaveFile
            // 
            this.tsbSaveFile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbSaveFile.Image = ((System.Drawing.Image)(resources.GetObject("tsbSaveFile.Image")));
            this.tsbSaveFile.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbSaveFile.Name = "tsbSaveFile";
            this.tsbSaveFile.Size = new System.Drawing.Size(23, 22);
            this.tsbSaveFile.Text = "上書き保存(&S)";
            // 
            // tsbPrint
            // 
            this.tsbPrint.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbPrint.Image = ((System.Drawing.Image)(resources.GetObject("tsbPrint.Image")));
            this.tsbPrint.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbPrint.Name = "tsbPrint";
            this.tsbPrint.Size = new System.Drawing.Size(23, 22);
            this.tsbPrint.Text = "印刷(&P)";
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            this.toolStripSeparator.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbCut
            // 
            this.tsbCut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCut.Image = ((System.Drawing.Image)(resources.GetObject("tsbCut.Image")));
            this.tsbCut.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCut.Name = "tsbCut";
            this.tsbCut.Size = new System.Drawing.Size(23, 22);
            this.tsbCut.Text = "切り取り(&U)";
            // 
            // tsbCopy
            // 
            this.tsbCopy.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCopy.Image = ((System.Drawing.Image)(resources.GetObject("tsbCopy.Image")));
            this.tsbCopy.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCopy.Name = "tsbCopy";
            this.tsbCopy.Size = new System.Drawing.Size(23, 22);
            this.tsbCopy.Text = "コピー(&C)";
            // 
            // tsbPaste
            // 
            this.tsbPaste.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbPaste.Image = ((System.Drawing.Image)(resources.GetObject("tsbPaste.Image")));
            this.tsbPaste.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbPaste.Name = "tsbPaste";
            this.tsbPaste.Size = new System.Drawing.Size(23, 22);
            this.tsbPaste.Text = "貼り付け(&P)";
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbHelp
            // 
            this.tsbHelp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHelp.Image = ((System.Drawing.Image)(resources.GetObject("tsbHelp.Image")));
            this.tsbHelp.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHelp.Name = "tsbHelp";
            this.tsbHelp.Size = new System.Drawing.Size(23, 22);
            this.tsbHelp.Text = "ヘルプ(&L)";
            // 
            // MainForm
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Application;
            this.AllowDrop = true;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
            this.ClientSize = new System.Drawing.Size(1024, 747);
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.myStatusBar);
            this.Controls.Add(this.toolBarTool);
            this.Controls.Add(this.menu);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menu;
            this.Name = "MainForm";
            this.Text = "siren";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Activated += new System.EventHandler(this.MainForm_Activated);
            this.DragDrop += new System.Windows.Forms.DragEventHandler(this.MainForm_DragDrop);
            this.DragEnter += new System.Windows.Forms.DragEventHandler(this.MainForm_DragEnter);
            this.menu.ResumeLayout(false);
            this.menu.PerformLayout();
            this.myStatusBar.ResumeLayout(false);
            this.myStatusBar.PerformLayout();
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
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
        private ToolStrip toolStrip1;
        private ToolStripButton tsbNewFile;
        private ToolStripButton tsbOpenFile;
        private ToolStripButton tsbSaveFile;
        private ToolStripButton tsbPrint;
        private ToolStripSeparator toolStripSeparator;
        private ToolStripButton tsbCut;
        private ToolStripButton tsbCopy;
        private ToolStripButton tsbPaste;
        private ToolStripSeparator toolStripSeparator8;
        private ToolStripButton tsbHelp;

    }
}
