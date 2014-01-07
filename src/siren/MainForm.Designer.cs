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
        //private System.ComponentModel.IContainer components;

        protected siren.ModelFormat myModelFormat;

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
            this.toolStripLabel2 = new System.Windows.Forms.ToolStripLabel();
            this.toolStripPanel2 = new System.Windows.Forms.ToolStripPanel();
            this.toolStripMain = new System.Windows.Forms.ToolStrip();
            this.tsbNew = new System.Windows.Forms.ToolStripButton();
            this.tsbOpen = new System.Windows.Forms.ToolStripButton();
            this.tsbSave = new System.Windows.Forms.ToolStripButton();
            this.tsbExit = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbNewView = new System.Windows.Forms.ToolStripButton();
            this.tsbClose = new System.Windows.Forms.ToolStripButton();
            this.tsbCascade = new System.Windows.Forms.ToolStripButton();
            this.tsbTile = new System.Windows.Forms.ToolStripButton();
            this.tsbDump = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbBox = new System.Windows.Forms.ToolStripButton();
            this.tsbSphere = new System.Windows.Forms.ToolStripButton();
            this.tsbCylinder = new System.Windows.Forms.ToolStripButton();
            this.tsbCone = new System.Windows.Forms.ToolStripButton();
            this.tsbTorus = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbCopy = new System.Windows.Forms.ToolStripButton();
            this.tsbDelete = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbTranslate = new System.Windows.Forms.ToolStripButton();
            this.tsbRotate = new System.Windows.Forms.ToolStripButton();
            this.tsbScale = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton6 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbDisplayMode = new System.Windows.Forms.ToolStripButton();
            this.tsbTransparency = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator10 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbColor = new System.Windows.Forms.ToolStripButton();
            this.tsbMaterial = new System.Windows.Forms.ToolStripSplitButton();
            this.miGold = new System.Windows.Forms.ToolStripMenuItem();
            this.miSilver = new System.Windows.Forms.ToolStripMenuItem();
            this.miCopper = new System.Windows.Forms.ToolStripMenuItem();
            this.miBronze = new System.Windows.Forms.ToolStripMenuItem();
            this.miPewter = new System.Windows.Forms.ToolStripMenuItem();
            this.miBrass = new System.Windows.Forms.ToolStripMenuItem();
            this.miSteel = new System.Windows.Forms.ToolStripMenuItem();
            this.miAluminium = new System.Windows.Forms.ToolStripMenuItem();
            this.miMetalized = new System.Windows.Forms.ToolStripMenuItem();
            this.miChrome = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.miStone = new System.Windows.Forms.ToolStripMenuItem();
            this.miPlaster = new System.Windows.Forms.ToolStripMenuItem();
            this.miObsidian = new System.Windows.Forms.ToolStripMenuItem();
            this.miJade = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.miPlastic = new System.Windows.Forms.ToolStripMenuItem();
            this.miPlastic2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator7 = new System.Windows.Forms.ToolStripSeparator();
            this.miSatin = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.miGNC = new System.Windows.Forms.ToolStripMenuItem();
            this.miPHC = new System.Windows.Forms.ToolStripMenuItem();
            this.tsbFit = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator12 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbAxoView = new System.Windows.Forms.ToolStripSplitButton();
            this.miFront = new System.Windows.Forms.ToolStripMenuItem();
            this.miBack = new System.Windows.Forms.ToolStripMenuItem();
            this.miLeft = new System.Windows.Forms.ToolStripMenuItem();
            this.miRight = new System.Windows.Forms.ToolStripMenuItem();
            this.miTop = new System.Windows.Forms.ToolStripMenuItem();
            this.miBottom = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator13 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbResetView = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator14 = new System.Windows.Forms.ToolStripSeparator();
            this.tsbHlr = new System.Windows.Forms.ToolStripButton();
            this.toolStripPanel2.SuspendLayout();
            this.toolStripMain.SuspendLayout();
            this.SuspendLayout();
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
            this.toolStripPanel2.Location = new System.Drawing.Point(0, 0);
            this.toolStripPanel2.Name = "toolStripPanel2";
            this.toolStripPanel2.Orientation = System.Windows.Forms.Orientation.Horizontal;
            this.toolStripPanel2.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
            this.toolStripPanel2.Size = new System.Drawing.Size(784, 25);
            // 
            // toolStripMain
            // 
            this.toolStripMain.Dock = System.Windows.Forms.DockStyle.None;
            this.toolStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbNew,
            this.tsbOpen,
            this.tsbSave,
            this.tsbExit,
            this.toolStripSeparator2,
            this.tsbNewView,
            this.tsbClose,
            this.tsbCascade,
            this.tsbTile,
            this.tsbDump,
            this.toolStripSeparator1,
            this.tsbBox,
            this.tsbSphere,
            this.tsbCylinder,
            this.tsbCone,
            this.tsbTorus,
            this.toolStripSeparator8,
            this.tsbCopy,
            this.tsbDelete,
            this.toolStripSeparator3,
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
            this.toolStripSeparator12,
            this.tsbAxoView,
            this.toolStripSeparator13,
            this.tsbResetView,
            this.toolStripSeparator14,
            this.tsbHlr});
            this.toolStripMain.Location = new System.Drawing.Point(3, 0);
            this.toolStripMain.Name = "toolStripMain";
            this.toolStripMain.Size = new System.Drawing.Size(736, 25);
            this.toolStripMain.TabIndex = 14;
            // 
            // tsbNew
            // 
            this.tsbNew.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbNew.Image = ((System.Drawing.Image)(resources.GetObject("tsbNew.Image")));
            this.tsbNew.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbNew.Name = "tsbNew";
            this.tsbNew.Size = new System.Drawing.Size(23, 22);
            this.tsbNew.Text = "新規ビューアー";
            this.tsbNew.Click += new System.EventHandler(this.tsbNew_Click);
            // 
            // tsbOpen
            // 
            this.tsbOpen.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbOpen.Image = ((System.Drawing.Image)(resources.GetObject("tsbOpen.Image")));
            this.tsbOpen.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbOpen.Name = "tsbOpen";
            this.tsbOpen.Size = new System.Drawing.Size(23, 22);
            this.tsbOpen.Text = "開く";
            this.tsbOpen.Click += new System.EventHandler(this.tsbOpen_Click);
            // 
            // tsbSave
            // 
            this.tsbSave.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbSave.Image = ((System.Drawing.Image)(resources.GetObject("tsbSave.Image")));
            this.tsbSave.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbSave.Name = "tsbSave";
            this.tsbSave.Size = new System.Drawing.Size(23, 22);
            this.tsbSave.Text = "選択オブジェクトを保存";
            this.tsbSave.Click += new System.EventHandler(this.tsbSave_Click);
            // 
            // tsbExit
            // 
            this.tsbExit.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbExit.Image = ((System.Drawing.Image)(resources.GetObject("tsbExit.Image")));
            this.tsbExit.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbExit.Name = "tsbExit";
            this.tsbExit.Size = new System.Drawing.Size(23, 22);
            this.tsbExit.Text = "終了";
            this.tsbExit.Click += new System.EventHandler(this.tsbExit_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbNewView
            // 
            this.tsbNewView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbNewView.Image = ((System.Drawing.Image)(resources.GetObject("tsbNewView.Image")));
            this.tsbNewView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbNewView.Name = "tsbNewView";
            this.tsbNewView.Size = new System.Drawing.Size(23, 22);
            this.tsbNewView.Text = "ビューを追加";
            this.tsbNewView.Click += new System.EventHandler(this.tsbNewView_Click);
            // 
            // tsbClose
            // 
            this.tsbClose.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbClose.Image = ((System.Drawing.Image)(resources.GetObject("tsbClose.Image")));
            this.tsbClose.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbClose.Name = "tsbClose";
            this.tsbClose.Size = new System.Drawing.Size(23, 22);
            this.tsbClose.Text = "ビューを削除";
            this.tsbClose.Click += new System.EventHandler(this.tsbClose_Click);
            // 
            // tsbCascade
            // 
            this.tsbCascade.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCascade.Image = ((System.Drawing.Image)(resources.GetObject("tsbCascade.Image")));
            this.tsbCascade.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCascade.Name = "tsbCascade";
            this.tsbCascade.Size = new System.Drawing.Size(23, 22);
            this.tsbCascade.Text = "重ねて表示";
            this.tsbCascade.Click += new System.EventHandler(this.tsbCascade_Click);
            // 
            // tsbTile
            // 
            this.tsbTile.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTile.Image = ((System.Drawing.Image)(resources.GetObject("tsbTile.Image")));
            this.tsbTile.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTile.Name = "tsbTile";
            this.tsbTile.Size = new System.Drawing.Size(23, 22);
            this.tsbTile.Text = "並べて表示";
            this.tsbTile.Click += new System.EventHandler(this.tsbTile_Click);
            // 
            // tsbDump
            // 
            this.tsbDump.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbDump.Image = ((System.Drawing.Image)(resources.GetObject("tsbDump.Image")));
            this.tsbDump.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbDump.Name = "tsbDump";
            this.tsbDump.Size = new System.Drawing.Size(23, 22);
            this.tsbDump.Text = "スクリーンショット";
            this.tsbDump.Click += new System.EventHandler(this.tsbDump_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbBox
            // 
            this.tsbBox.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbBox.Image = ((System.Drawing.Image)(resources.GetObject("tsbBox.Image")));
            this.tsbBox.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbBox.Name = "tsbBox";
            this.tsbBox.Size = new System.Drawing.Size(23, 22);
            this.tsbBox.Text = "ボックス(箱)";
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
            this.tsbSphere.Text = "スフィア(球)";
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
            this.tsbCylinder.Text = "シリンダー(円筒)";
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
            this.tsbCone.Text = "コーン(円錐)";
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
            this.tsbTorus.Text = "トーラス(輪)";
            this.tsbTorus.ToolTipText = "トーラス";
            this.tsbTorus.Click += new System.EventHandler(this.tsbTorus_Click);
            // 
            // toolStripSeparator8
            // 
            this.toolStripSeparator8.Name = "toolStripSeparator8";
            this.toolStripSeparator8.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbCopy
            // 
            this.tsbCopy.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbCopy.Image = ((System.Drawing.Image)(resources.GetObject("tsbCopy.Image")));
            this.tsbCopy.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbCopy.Name = "tsbCopy";
            this.tsbCopy.Size = new System.Drawing.Size(23, 22);
            this.tsbCopy.Text = "コピー";
            this.tsbCopy.Click += new System.EventHandler(this.tsbCopy_Click);
            // 
            // tsbDelete
            // 
            this.tsbDelete.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbDelete.Image = ((System.Drawing.Image)(resources.GetObject("tsbDelete.Image")));
            this.tsbDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbDelete.Name = "tsbDelete";
            this.tsbDelete.Size = new System.Drawing.Size(23, 22);
            this.tsbDelete.Text = "削除";
            this.tsbDelete.Click += new System.EventHandler(this.tsbDelete_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbTranslate
            // 
            this.tsbTranslate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTranslate.Image = ((System.Drawing.Image)(resources.GetObject("tsbTranslate.Image")));
            this.tsbTranslate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTranslate.Name = "tsbTranslate";
            this.tsbTranslate.Size = new System.Drawing.Size(23, 22);
            this.tsbTranslate.Text = "移動";
            this.tsbTranslate.ToolTipText = "移動";
            this.tsbTranslate.Click += new System.EventHandler(this.tsbTranslate_Click);
            // 
            // tsbRotate
            // 
            this.tsbRotate.CheckOnClick = true;
            this.tsbRotate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbRotate.Enabled = false;
            this.tsbRotate.Image = ((System.Drawing.Image)(resources.GetObject("tsbRotate.Image")));
            this.tsbRotate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbRotate.Name = "tsbRotate";
            this.tsbRotate.Size = new System.Drawing.Size(23, 22);
            this.tsbRotate.Text = "回転";
            this.tsbRotate.ToolTipText = "回転";
            // 
            // tsbScale
            // 
            this.tsbScale.CheckOnClick = true;
            this.tsbScale.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbScale.Enabled = false;
            this.tsbScale.Image = ((System.Drawing.Image)(resources.GetObject("tsbScale.Image")));
            this.tsbScale.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbScale.Name = "tsbScale";
            this.tsbScale.Size = new System.Drawing.Size(23, 22);
            this.tsbScale.Text = "拡大縮小";
            this.tsbScale.ToolTipText = "スケール";
            // 
            // toolStripButton6
            // 
            this.toolStripButton6.Name = "toolStripButton6";
            this.toolStripButton6.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbDisplayMode
            // 
            this.tsbDisplayMode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbDisplayMode.Image = ((System.Drawing.Image)(resources.GetObject("tsbDisplayMode.Image")));
            this.tsbDisplayMode.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbDisplayMode.Name = "tsbDisplayMode";
            this.tsbDisplayMode.Size = new System.Drawing.Size(23, 22);
            this.tsbDisplayMode.Text = "シェーディング";
            this.tsbDisplayMode.ToolTipText = "シェーディング";
            this.tsbDisplayMode.Click += new System.EventHandler(this.tsbDisplayMode_Click);
            // 
            // tsbTransparency
            // 
            this.tsbTransparency.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTransparency.Image = ((System.Drawing.Image)(resources.GetObject("tsbTransparency.Image")));
            this.tsbTransparency.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTransparency.Name = "tsbTransparency";
            this.tsbTransparency.Size = new System.Drawing.Size(23, 22);
            this.tsbTransparency.Text = "不透明度";
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
            this.tsbColor.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbColor.Image = ((System.Drawing.Image)(resources.GetObject("tsbColor.Image")));
            this.tsbColor.Name = "tsbColor";
            this.tsbColor.Size = new System.Drawing.Size(23, 22);
            this.tsbColor.Text = "色";
            this.tsbColor.Click += new System.EventHandler(this.tsbColor_Click);
            // 
            // tsbMaterial
            // 
            this.tsbMaterial.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbMaterial.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miGold,
            this.miSilver,
            this.miCopper,
            this.miBronze,
            this.miPewter,
            this.miBrass,
            this.miSteel,
            this.miAluminium,
            this.miMetalized,
            this.miChrome,
            this.toolStripSeparator6,
            this.miStone,
            this.miPlaster,
            this.miObsidian,
            this.miJade,
            this.toolStripSeparator5,
            this.miPlastic,
            this.miPlastic2,
            this.toolStripSeparator7,
            this.miSatin,
            this.toolStripSeparator4,
            this.miGNC,
            this.miPHC});
            this.tsbMaterial.Image = ((System.Drawing.Image)(resources.GetObject("tsbMaterial.Image")));
            this.tsbMaterial.Name = "tsbMaterial";
            this.tsbMaterial.Size = new System.Drawing.Size(32, 22);
            this.tsbMaterial.Text = "材質";
            this.tsbMaterial.ButtonClick += new System.EventHandler(this.tsbMaterial_ButtonClick);
            // 
            // miGold
            // 
            this.miGold.Name = "miGold";
            this.miGold.Size = new System.Drawing.Size(172, 22);
            this.miGold.Text = "金";
            this.miGold.Click += new System.EventHandler(this.miGold_Click);
            // 
            // miSilver
            // 
            this.miSilver.Name = "miSilver";
            this.miSilver.Size = new System.Drawing.Size(172, 22);
            this.miSilver.Text = "銀";
            this.miSilver.Click += new System.EventHandler(this.miSilver_Click);
            // 
            // miCopper
            // 
            this.miCopper.Name = "miCopper";
            this.miCopper.Size = new System.Drawing.Size(172, 22);
            this.miCopper.Text = "銅";
            this.miCopper.Click += new System.EventHandler(this.miCopper_Click);
            // 
            // miBronze
            // 
            this.miBronze.Name = "miBronze";
            this.miBronze.Size = new System.Drawing.Size(172, 22);
            this.miBronze.Text = "青銅";
            this.miBronze.Click += new System.EventHandler(this.miBronze_Click);
            // 
            // miPewter
            // 
            this.miPewter.Name = "miPewter";
            this.miPewter.Size = new System.Drawing.Size(172, 22);
            this.miPewter.Text = "スズ";
            this.miPewter.Click += new System.EventHandler(this.miPewter_Click);
            // 
            // miBrass
            // 
            this.miBrass.Name = "miBrass";
            this.miBrass.Size = new System.Drawing.Size(172, 22);
            this.miBrass.Text = "真ちゅう";
            this.miBrass.Click += new System.EventHandler(this.miBrass_Click);
            // 
            // miSteel
            // 
            this.miSteel.Name = "miSteel";
            this.miSteel.Size = new System.Drawing.Size(172, 22);
            this.miSteel.Text = "スチール";
            this.miSteel.Click += new System.EventHandler(this.miSteel_Click);
            // 
            // miAluminium
            // 
            this.miAluminium.Name = "miAluminium";
            this.miAluminium.Size = new System.Drawing.Size(172, 22);
            this.miAluminium.Text = "アルミ";
            this.miAluminium.Click += new System.EventHandler(this.miAluminium_Click);
            // 
            // miMetalized
            // 
            this.miMetalized.Name = "miMetalized";
            this.miMetalized.Size = new System.Drawing.Size(172, 22);
            this.miMetalized.Text = "メタライズ";
            this.miMetalized.Click += new System.EventHandler(this.miMetalized_Click);
            // 
            // miChrome
            // 
            this.miChrome.Name = "miChrome";
            this.miChrome.Size = new System.Drawing.Size(172, 22);
            this.miChrome.Text = "クロム";
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            this.toolStripSeparator6.Size = new System.Drawing.Size(169, 6);
            // 
            // miStone
            // 
            this.miStone.Name = "miStone";
            this.miStone.Size = new System.Drawing.Size(172, 22);
            this.miStone.Text = "石";
            this.miStone.Click += new System.EventHandler(this.miStone_Click);
            // 
            // miPlaster
            // 
            this.miPlaster.Name = "miPlaster";
            this.miPlaster.Size = new System.Drawing.Size(172, 22);
            this.miPlaster.Text = "石こう";
            this.miPlaster.Click += new System.EventHandler(this.miPlaster_Click);
            // 
            // miObsidian
            // 
            this.miObsidian.Name = "miObsidian";
            this.miObsidian.Size = new System.Drawing.Size(172, 22);
            this.miObsidian.Text = "黒曜石";
            this.miObsidian.Click += new System.EventHandler(this.miObsidian_Click);
            // 
            // miJade
            // 
            this.miJade.Name = "miJade";
            this.miJade.Size = new System.Drawing.Size(172, 22);
            this.miJade.Text = "ヒスイ";
            this.miJade.Click += new System.EventHandler(this.miJade_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(169, 6);
            // 
            // miPlastic
            // 
            this.miPlastic.Name = "miPlastic";
            this.miPlastic.Size = new System.Drawing.Size(172, 22);
            this.miPlastic.Text = "プラスチック";
            this.miPlastic.Click += new System.EventHandler(this.miPlastic_Click);
            // 
            // miPlastic2
            // 
            this.miPlastic2.Name = "miPlastic2";
            this.miPlastic2.Size = new System.Drawing.Size(172, 22);
            this.miPlastic2.Text = "光沢プラスチック";
            this.miPlastic2.Click += new System.EventHandler(this.miPlastic2_Click);
            // 
            // toolStripSeparator7
            // 
            this.toolStripSeparator7.Name = "toolStripSeparator7";
            this.toolStripSeparator7.Size = new System.Drawing.Size(169, 6);
            // 
            // miSatin
            // 
            this.miSatin.Name = "miSatin";
            this.miSatin.Size = new System.Drawing.Size(172, 22);
            this.miSatin.Text = "サテン";
            this.miSatin.Click += new System.EventHandler(this.miSatin_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(169, 6);
            // 
            // miGNC
            // 
            this.miGNC.Name = "miGNC";
            this.miGNC.Size = new System.Drawing.Size(172, 22);
            this.miGNC.Text = "ネオンGNC";
            this.miGNC.Click += new System.EventHandler(this.miGNC_Click);
            // 
            // miPHC
            // 
            this.miPHC.Name = "miPHC";
            this.miPHC.Size = new System.Drawing.Size(172, 22);
            this.miPHC.Text = "ネオンPHC";
            this.miPHC.Click += new System.EventHandler(this.miPHC_Click);
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
            // toolStripSeparator12
            // 
            this.toolStripSeparator12.Name = "toolStripSeparator12";
            this.toolStripSeparator12.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbAxoView
            // 
            this.tsbAxoView.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbAxoView.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miFront,
            this.miBack,
            this.miLeft,
            this.miRight,
            this.miTop,
            this.miBottom});
            this.tsbAxoView.Image = ((System.Drawing.Image)(resources.GetObject("tsbAxoView.Image")));
            this.tsbAxoView.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbAxoView.Name = "tsbAxoView";
            this.tsbAxoView.Size = new System.Drawing.Size(32, 22);
            this.tsbAxoView.Text = "視点";
            this.tsbAxoView.ToolTipText = "視点";
            this.tsbAxoView.ButtonClick += new System.EventHandler(this.tsbAxoView_ButtonClick);
            // 
            // miFront
            // 
            this.miFront.Image = ((System.Drawing.Image)(resources.GetObject("miFront.Image")));
            this.miFront.Name = "miFront";
            this.miFront.Size = new System.Drawing.Size(112, 22);
            this.miFront.Text = "正面";
            this.miFront.Click += new System.EventHandler(this.miFront_Click);
            // 
            // miBack
            // 
            this.miBack.Image = ((System.Drawing.Image)(resources.GetObject("miBack.Image")));
            this.miBack.Name = "miBack";
            this.miBack.Size = new System.Drawing.Size(112, 22);
            this.miBack.Text = "背面";
            this.miBack.Click += new System.EventHandler(this.miBack_Click);
            // 
            // miLeft
            // 
            this.miLeft.Image = ((System.Drawing.Image)(resources.GetObject("miLeft.Image")));
            this.miLeft.Name = "miLeft";
            this.miLeft.Size = new System.Drawing.Size(112, 22);
            this.miLeft.Text = "左側面";
            this.miLeft.Click += new System.EventHandler(this.miLeft_Click);
            // 
            // miRight
            // 
            this.miRight.Image = ((System.Drawing.Image)(resources.GetObject("miRight.Image")));
            this.miRight.Name = "miRight";
            this.miRight.Size = new System.Drawing.Size(112, 22);
            this.miRight.Text = "右側面";
            this.miRight.Click += new System.EventHandler(this.miRight_Click);
            // 
            // miTop
            // 
            this.miTop.Image = ((System.Drawing.Image)(resources.GetObject("miTop.Image")));
            this.miTop.Name = "miTop";
            this.miTop.Size = new System.Drawing.Size(112, 22);
            this.miTop.Text = "上面";
            this.miTop.Click += new System.EventHandler(this.miTop_Click);
            // 
            // miBottom
            // 
            this.miBottom.Image = ((System.Drawing.Image)(resources.GetObject("miBottom.Image")));
            this.miBottom.Name = "miBottom";
            this.miBottom.Size = new System.Drawing.Size(112, 22);
            this.miBottom.Text = "下面";
            this.miBottom.Click += new System.EventHandler(this.miBottom_Click);
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
            this.tsbResetView.Click += new System.EventHandler(this.tsbResetView_Click);
            // 
            // toolStripSeparator14
            // 
            this.toolStripSeparator14.Name = "toolStripSeparator14";
            this.toolStripSeparator14.Size = new System.Drawing.Size(6, 25);
            // 
            // tsbHlr
            // 
            this.tsbHlr.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbHlr.Image = ((System.Drawing.Image)(resources.GetObject("tsbHlr.Image")));
            this.tsbHlr.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbHlr.Name = "tsbHlr";
            this.tsbHlr.Size = new System.Drawing.Size(23, 22);
            this.tsbHlr.Text = "陰面消去";
            this.tsbHlr.ToolTipText = "隠面消去";
            this.tsbHlr.Click += new System.EventHandler(this.tsbHlr_Click);
            // 
            // MainForm
            // 
            this.AccessibleRole = System.Windows.Forms.AccessibleRole.Application;
            this.AllowDrop = true;
            this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
            this.ClientSize = new System.Drawing.Size(784, 562);
            this.Controls.Add(this.toolStripPanel2);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.IsMdiContainer = true;
            this.Name = "MainForm";
            this.Text = "siren";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.DragDrop += new System.Windows.Forms.DragEventHandler(this.MainForm_DragDrop);
            this.DragEnter += new System.Windows.Forms.DragEventHandler(this.MainForm_DragEnter);
            this.toolStripPanel2.ResumeLayout(false);
            this.toolStripPanel2.PerformLayout();
            this.toolStripMain.ResumeLayout(false);
            this.toolStripMain.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }
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
        private ToolStripSeparator toolStripSeparator12;
        private ToolStripSeparator toolStripSeparator13;
        private ToolStripButton tsbResetView;
        private ToolStripSeparator toolStripSeparator14;
        private ToolStripButton tsbHlr;
        private ToolStripSplitButton tsbAxoView;
        private ToolStripMenuItem miFront;
        private ToolStripMenuItem miBack;
        private ToolStripMenuItem miLeft;
        private ToolStripMenuItem miRight;
        private ToolStripMenuItem miTop;
        private ToolStripMenuItem miBottom;
        private ToolStripSeparator toolStripSeparator8;
        private ToolStripButton tsbTranslate;
        private ToolStripButton tsbRotate;
        private ToolStripButton tsbScale;
        private ToolStripSplitButton tsbMaterial;
        private ToolStripButton tsbNew;
        private ToolStripButton tsbOpen;
        private ToolStripButton tsbSave;
        private ToolStripButton tsbExit;
        private ToolStripSeparator toolStripSeparator2;
        private ToolStripButton tsbNewView;
        private ToolStripButton tsbDump;
        private ToolStripButton tsbCascade;
        private ToolStripButton tsbTile;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripButton tsbClose;
        private ToolStripButton tsbCopy;
        private ToolStripButton tsbDelete;
        private ToolStripSeparator toolStripSeparator3;
        private ToolStripButton tsbColor;
        private ToolStripMenuItem miPewter;
        private ToolStripMenuItem miGold;
        private ToolStripMenuItem miSilver;
        private ToolStripMenuItem miCopper;
        private ToolStripMenuItem miBronze;
        private ToolStripMenuItem miBrass;
        private ToolStripMenuItem miSteel;
        private ToolStripMenuItem miAluminium;
        private ToolStripMenuItem miMetalized;
        private ToolStripSeparator toolStripSeparator6;
        private ToolStripMenuItem miStone;
        private ToolStripMenuItem miPlaster;
        private ToolStripMenuItem miObsidian;
        private ToolStripMenuItem miJade;
        private ToolStripSeparator toolStripSeparator5;
        private ToolStripMenuItem miPlastic;
        private ToolStripMenuItem miPlastic2;
        private ToolStripMenuItem miSatin;
        private ToolStripSeparator toolStripSeparator4;
        private ToolStripMenuItem miGNC;
        private ToolStripMenuItem miPHC;
        private ToolStripSeparator toolStripSeparator7;
        private ToolStripMenuItem miChrome;

    }
}
