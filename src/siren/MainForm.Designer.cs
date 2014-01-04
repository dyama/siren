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
            this.tsbMaterial = new System.Windows.Forms.ToolStripSplitButton();
            this.miIrons = new System.Windows.Forms.ToolStripMenuItem();
            this.真鍮ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.スチールToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.銀ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.スズToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.金ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.銅ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ブロンズToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.アルミToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.メタリックToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.miStones = new System.Windows.Forms.ToolStripMenuItem();
            this.miStone = new System.Windows.Forms.ToolStripMenuItem();
            this.石膏ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.黒曜石ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
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
            this.tsbFit = new System.Windows.Forms.ToolStripButton();
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
            this.toolStripMain.Size = new System.Drawing.Size(743, 25);
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
            this.tsbTorus.Enabled = false;
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
            this.tsbTranslate.CheckOnClick = true;
            this.tsbTranslate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsbTranslate.Enabled = false;
            this.tsbTranslate.Image = ((System.Drawing.Image)(resources.GetObject("tsbTranslate.Image")));
            this.tsbTranslate.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsbTranslate.Name = "tsbTranslate";
            this.tsbTranslate.Size = new System.Drawing.Size(23, 22);
            this.tsbTranslate.Text = "移動";
            this.tsbTranslate.ToolTipText = "移動";
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
            this.tsbColor.Text = "色";
            this.tsbColor.ButtonClick += new System.EventHandler(this.tsbColor_ButtonClick);
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(101, 22);
            this.toolStripMenuItem4.Text = "白";
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size(101, 22);
            this.toolStripMenuItem5.Text = "グレイ";
            // 
            // 赤ToolStripMenuItem
            // 
            this.赤ToolStripMenuItem.Name = "赤ToolStripMenuItem";
            this.赤ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.赤ToolStripMenuItem.Text = "赤";
            // 
            // 青ToolStripMenuItem
            // 
            this.青ToolStripMenuItem.Name = "青ToolStripMenuItem";
            this.青ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.青ToolStripMenuItem.Text = "青";
            // 
            // 緑ToolStripMenuItem
            // 
            this.緑ToolStripMenuItem.Name = "緑ToolStripMenuItem";
            this.緑ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.緑ToolStripMenuItem.Text = "緑";
            // 
            // 水色ToolStripMenuItem
            // 
            this.水色ToolStripMenuItem.Name = "水色ToolStripMenuItem";
            this.水色ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.水色ToolStripMenuItem.Text = "水色";
            // 
            // 紫ToolStripMenuItem
            // 
            this.紫ToolStripMenuItem.Name = "紫ToolStripMenuItem";
            this.紫ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.紫ToolStripMenuItem.Text = "紫";
            // 
            // 黄ToolStripMenuItem
            // 
            this.黄ToolStripMenuItem.Name = "黄ToolStripMenuItem";
            this.黄ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.黄ToolStripMenuItem.Text = "黄";
            // 
            // 黒ToolStripMenuItem
            // 
            this.黒ToolStripMenuItem.Name = "黒ToolStripMenuItem";
            this.黒ToolStripMenuItem.Size = new System.Drawing.Size(101, 22);
            this.黒ToolStripMenuItem.Text = "黒";
            // 
            // tsbMaterial
            // 
            this.tsbMaterial.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
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
            this.tsbMaterial.Text = "材質";
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
            this.miIrons.Size = new System.Drawing.Size(133, 22);
            this.miIrons.Text = "金属(&I)";
            // 
            // 真鍮ToolStripMenuItem
            // 
            this.真鍮ToolStripMenuItem.Name = "真鍮ToolStripMenuItem";
            this.真鍮ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.真鍮ToolStripMenuItem.Text = "真鍮";
            // 
            // スチールToolStripMenuItem
            // 
            this.スチールToolStripMenuItem.Name = "スチールToolStripMenuItem";
            this.スチールToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.スチールToolStripMenuItem.Text = "スチール";
            // 
            // 銀ToolStripMenuItem
            // 
            this.銀ToolStripMenuItem.Name = "銀ToolStripMenuItem";
            this.銀ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.銀ToolStripMenuItem.Text = "銀";
            // 
            // スズToolStripMenuItem
            // 
            this.スズToolStripMenuItem.Name = "スズToolStripMenuItem";
            this.スズToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.スズToolStripMenuItem.Text = "スズ";
            // 
            // 金ToolStripMenuItem
            // 
            this.金ToolStripMenuItem.Name = "金ToolStripMenuItem";
            this.金ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.金ToolStripMenuItem.Text = "金";
            // 
            // 銅ToolStripMenuItem
            // 
            this.銅ToolStripMenuItem.Name = "銅ToolStripMenuItem";
            this.銅ToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.銅ToolStripMenuItem.Text = "銅";
            // 
            // ブロンズToolStripMenuItem
            // 
            this.ブロンズToolStripMenuItem.Name = "ブロンズToolStripMenuItem";
            this.ブロンズToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.ブロンズToolStripMenuItem.Text = "ブロンズ";
            // 
            // アルミToolStripMenuItem
            // 
            this.アルミToolStripMenuItem.Name = "アルミToolStripMenuItem";
            this.アルミToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.アルミToolStripMenuItem.Text = "アルミ";
            // 
            // メタリックToolStripMenuItem
            // 
            this.メタリックToolStripMenuItem.Name = "メタリックToolStripMenuItem";
            this.メタリックToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.メタリックToolStripMenuItem.Text = "メタリック";
            // 
            // miStones
            // 
            this.miStones.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miStone,
            this.石膏ToolStripMenuItem,
            this.黒曜石ToolStripMenuItem,
            this.翡翠ToolStripMenuItem});
            this.miStones.Name = "miStones";
            this.miStones.Size = new System.Drawing.Size(133, 22);
            this.miStones.Text = "石(&S)";
            // 
            // miStone
            // 
            this.miStone.Name = "miStone";
            this.miStone.Size = new System.Drawing.Size(110, 22);
            this.miStone.Text = "石";
            // 
            // 石膏ToolStripMenuItem
            // 
            this.石膏ToolStripMenuItem.Name = "石膏ToolStripMenuItem";
            this.石膏ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.石膏ToolStripMenuItem.Text = "石膏";
            // 
            // 黒曜石ToolStripMenuItem
            // 
            this.黒曜石ToolStripMenuItem.Name = "黒曜石ToolStripMenuItem";
            this.黒曜石ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.黒曜石ToolStripMenuItem.Text = "黒曜石";
            // 
            // 翡翠ToolStripMenuItem
            // 
            this.翡翠ToolStripMenuItem.Name = "翡翠ToolStripMenuItem";
            this.翡翠ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.翡翠ToolStripMenuItem.Text = "翡翠";
            // 
            // miArtifacts
            // 
            this.miArtifacts.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miPlastic,
            this.miPlastic2,
            this.miSateen});
            this.miArtifacts.Name = "miArtifacts";
            this.miArtifacts.Size = new System.Drawing.Size(133, 22);
            this.miArtifacts.Text = "人工物(&A)";
            // 
            // miPlastic
            // 
            this.miPlastic.Name = "miPlastic";
            this.miPlastic.Size = new System.Drawing.Size(156, 22);
            this.miPlastic.Text = "プラスチック";
            // 
            // miPlastic2
            // 
            this.miPlastic2.Name = "miPlastic2";
            this.miPlastic2.Size = new System.Drawing.Size(156, 22);
            this.miPlastic2.Text = "プラスチック(光沢)";
            // 
            // miSateen
            // 
            this.miSateen.Name = "miSateen";
            this.miSateen.Size = new System.Drawing.Size(156, 22);
            this.miSateen.Text = "サテン";
            // 
            // miNeons
            // 
            this.miNeons.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miPHC,
            this.miGNC});
            this.miNeons.Name = "miNeons";
            this.miNeons.Size = new System.Drawing.Size(133, 22);
            this.miNeons.Text = "ネオン(&N)";
            // 
            // miPHC
            // 
            this.miPHC.Name = "miPHC";
            this.miPHC.Size = new System.Drawing.Size(123, 22);
            this.miPHC.Text = "ネオンPHC";
            // 
            // miGNC
            // 
            this.miGNC.Name = "miGNC";
            this.miGNC.Size = new System.Drawing.Size(123, 22);
            this.miGNC.Text = "ネオンGNC";
            // 
            // toolStripMenuItem7
            // 
            this.toolStripMenuItem7.Name = "toolStripMenuItem7";
            this.toolStripMenuItem7.Size = new System.Drawing.Size(130, 6);
            // 
            // miDefault
            // 
            this.miDefault.Name = "miDefault";
            this.miDefault.Size = new System.Drawing.Size(133, 22);
            this.miDefault.Text = "デフォルト(&D)";
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
            this.tsbAxoView.Text = "視点";
            this.tsbAxoView.ToolTipText = "視点";
            // 
            // 正面ToolStripMenuItem
            // 
            this.正面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("正面ToolStripMenuItem.Image")));
            this.正面ToolStripMenuItem.Name = "正面ToolStripMenuItem";
            this.正面ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.正面ToolStripMenuItem.Text = "正面";
            // 
            // 背面ToolStripMenuItem
            // 
            this.背面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("背面ToolStripMenuItem.Image")));
            this.背面ToolStripMenuItem.Name = "背面ToolStripMenuItem";
            this.背面ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.背面ToolStripMenuItem.Text = "背面";
            // 
            // 左側面ToolStripMenuItem
            // 
            this.左側面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("左側面ToolStripMenuItem.Image")));
            this.左側面ToolStripMenuItem.Name = "左側面ToolStripMenuItem";
            this.左側面ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.左側面ToolStripMenuItem.Text = "左側面";
            // 
            // 右側面ToolStripMenuItem
            // 
            this.右側面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("右側面ToolStripMenuItem.Image")));
            this.右側面ToolStripMenuItem.Name = "右側面ToolStripMenuItem";
            this.右側面ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.右側面ToolStripMenuItem.Text = "右側面";
            // 
            // 上面ToolStripMenuItem
            // 
            this.上面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("上面ToolStripMenuItem.Image")));
            this.上面ToolStripMenuItem.Name = "上面ToolStripMenuItem";
            this.上面ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.上面ToolStripMenuItem.Text = "上面";
            // 
            // 下面ToolStripMenuItem
            // 
            this.下面ToolStripMenuItem.Image = ((System.Drawing.Image)(resources.GetObject("下面ToolStripMenuItem.Image")));
            this.下面ToolStripMenuItem.Name = "下面ToolStripMenuItem";
            this.下面ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
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
            this.tsbHlr.Text = "陰面消去";
            this.tsbHlr.ToolTipText = "隠面消去";
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

    }
}
