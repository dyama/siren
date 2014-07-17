/* THIS FILE IS PART OF *SIREN* SOURCE CODES.
 * WHEN YOU WANT THE LICENSE OF THIS FILE, YOU CAN GET IT
 * IN README OR LICENSE DOCUMENTATION OF THIS PROJECT.
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
          this.tsbVertex = new System.Windows.Forms.ToolStripButton();
          this.tsbLine = new System.Windows.Forms.ToolStripButton();
          this.tsbPolyline = new System.Windows.Forms.ToolStripButton();
          this.tsbCurve = new System.Windows.Forms.ToolStripButton();
          this.tsbPlane = new System.Windows.Forms.ToolStripButton();
          this.tsbBox = new System.Windows.Forms.ToolStripButton();
          this.tsbSphere = new System.Windows.Forms.ToolStripButton();
          this.tsbCylinder = new System.Windows.Forms.ToolStripButton();
          this.tsbCone = new System.Windows.Forms.ToolStripButton();
          this.tsbTorus = new System.Windows.Forms.ToolStripButton();
          this.toolStripSeparator8 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbCopy = new System.Windows.Forms.ToolStripButton();
          this.tsbDelete = new System.Windows.Forms.ToolStripButton();
          this.tsbCompound = new System.Windows.Forms.ToolStripButton();
          this.toolStripSeparator9 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbExplode = new System.Windows.Forms.ToolStripSplitButton();
          this.miExCompound = new System.Windows.Forms.ToolStripMenuItem();
          this.miExSolid = new System.Windows.Forms.ToolStripMenuItem();
          this.miExShell = new System.Windows.Forms.ToolStripMenuItem();
          this.miExFace = new System.Windows.Forms.ToolStripMenuItem();
          this.miExWire = new System.Windows.Forms.ToolStripMenuItem();
          this.miExEdge = new System.Windows.Forms.ToolStripMenuItem();
          this.miExVertex = new System.Windows.Forms.ToolStripMenuItem();
          this.toolStripSeparator11 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbTranslate = new System.Windows.Forms.ToolStripButton();
          this.tsbRotate = new System.Windows.Forms.ToolStripButton();
          this.tsbScale = new System.Windows.Forms.ToolStripButton();
          this.tsbMirror = new System.Windows.Forms.ToolStripButton();
          this.toolStripButton6 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbLoft = new System.Windows.Forms.ToolStripButton();
          this.tsbOffset = new System.Windows.Forms.ToolStripButton();
          this.tsbSewing = new System.Windows.Forms.ToolStripButton();
          this.toolStripSeparator17 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbFuse = new System.Windows.Forms.ToolStripButton();
          this.tsbCut = new System.Windows.Forms.ToolStripButton();
          this.tsbCommon = new System.Windows.Forms.ToolStripButton();
          this.tsbIntersect = new System.Windows.Forms.ToolStripButton();
          this.toolStripSeparator16 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbInfo = new System.Windows.Forms.ToolStripSplitButton();
          this.miVolume = new System.Windows.Forms.ToolStripMenuItem();
          this.miCog = new System.Windows.Forms.ToolStripMenuItem();
          this.miBndbox = new System.Windows.Forms.ToolStripMenuItem();
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
          this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbFit = new System.Windows.Forms.ToolStripButton();
          this.tsbAxoView = new System.Windows.Forms.ToolStripSplitButton();
          this.miFront = new System.Windows.Forms.ToolStripMenuItem();
          this.miBack = new System.Windows.Forms.ToolStripMenuItem();
          this.miLeft = new System.Windows.Forms.ToolStripMenuItem();
          this.miRight = new System.Windows.Forms.ToolStripMenuItem();
          this.miTop = new System.Windows.Forms.ToolStripMenuItem();
          this.miBottom = new System.Windows.Forms.ToolStripMenuItem();
          this.tsbResetView = new System.Windows.Forms.ToolStripButton();
          this.tsbHlr = new System.Windows.Forms.ToolStripButton();
          this.tsbDump = new System.Windows.Forms.ToolStripButton();
          this.tsbRender = new System.Windows.Forms.ToolStripButton();
          this.tsbNew = new System.Windows.Forms.ToolStripButton();
          this.tsbOpen = new System.Windows.Forms.ToolStripButton();
          this.tsbSave = new System.Windows.Forms.ToolStripButton();
          this.tsbExit = new System.Windows.Forms.ToolStripButton();
          this.toolStripPanel1 = new System.Windows.Forms.ToolStripPanel();
          this.toolStripGeneral = new System.Windows.Forms.ToolStrip();
          this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
          this.toolStripSeparator12 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbClipPlane = new System.Windows.Forms.ToolStripButton();
          this.tsbSectionClipper = new System.Windows.Forms.ToolStripButton();
          this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
          this.toolStripSeparator13 = new System.Windows.Forms.ToolStripSeparator();
          this.tsbHelp = new System.Windows.Forms.ToolStripButton();
          this.tsbVersion = new System.Windows.Forms.ToolStripButton();
          this.toolStripContainer1 = new System.Windows.Forms.ToolStripContainer();
          this.splitContainer1 = new System.Windows.Forms.SplitContainer();
          this.splitContainer2 = new System.Windows.Forms.SplitContainer();
          this.splitContainer3 = new System.Windows.Forms.SplitContainer();
          this.splitContainer4 = new System.Windows.Forms.SplitContainer();
          this.myTerm = new siren.term();
          this.propertyGrid1 = new System.Windows.Forms.PropertyGrid();
          this.toolStripMain.SuspendLayout();
          this.toolStripGeneral.SuspendLayout();
          this.toolStripContainer1.ContentPanel.SuspendLayout();
          this.toolStripContainer1.LeftToolStripPanel.SuspendLayout();
          this.toolStripContainer1.TopToolStripPanel.SuspendLayout();
          this.toolStripContainer1.SuspendLayout();
          this.splitContainer1.Panel1.SuspendLayout();
          this.splitContainer1.Panel2.SuspendLayout();
          this.splitContainer1.SuspendLayout();
          this.splitContainer2.Panel1.SuspendLayout();
          this.splitContainer2.Panel2.SuspendLayout();
          this.splitContainer2.SuspendLayout();
          this.splitContainer3.Panel1.SuspendLayout();
          this.splitContainer3.SuspendLayout();
          this.splitContainer4.SuspendLayout();
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
          this.toolStripPanel2.Dock = System.Windows.Forms.DockStyle.Top;
          this.toolStripPanel2.Location = new System.Drawing.Point(0, 0);
          this.toolStripPanel2.Name = "toolStripPanel2";
          this.toolStripPanel2.Orientation = System.Windows.Forms.Orientation.Horizontal;
          this.toolStripPanel2.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
          this.toolStripPanel2.Size = new System.Drawing.Size(1192, 0);
          // 
          // toolStripMain
          // 
          this.toolStripMain.AutoSize = false;
          this.toolStripMain.Dock = System.Windows.Forms.DockStyle.None;
          this.toolStripMain.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
          this.toolStripMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbVertex,
            this.tsbLine,
            this.tsbPolyline,
            this.tsbCurve,
            this.tsbPlane,
            this.tsbBox,
            this.tsbSphere,
            this.tsbCylinder,
            this.tsbCone,
            this.tsbTorus,
            this.toolStripSeparator8,
            this.tsbCopy,
            this.tsbDelete,
            this.tsbCompound,
            this.toolStripSeparator9,
            this.tsbExplode,
            this.toolStripSeparator11,
            this.tsbTranslate,
            this.tsbRotate,
            this.tsbScale,
            this.tsbMirror,
            this.toolStripButton6,
            this.tsbLoft,
            this.tsbOffset,
            this.tsbSewing,
            this.toolStripSeparator17,
            this.tsbFuse,
            this.tsbCut,
            this.tsbCommon,
            this.tsbIntersect,
            this.toolStripSeparator16,
            this.tsbInfo});
          this.toolStripMain.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.VerticalStackWithOverflow;
          this.toolStripMain.Location = new System.Drawing.Point(0, 0);
          this.toolStripMain.Name = "toolStripMain";
          this.toolStripMain.Size = new System.Drawing.Size(33, 716);
          this.toolStripMain.Stretch = true;
          this.toolStripMain.TabIndex = 14;
          // 
          // tsbVertex
          // 
          this.tsbVertex.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbVertex.Image = ((System.Drawing.Image)(resources.GetObject("tsbVertex.Image")));
          this.tsbVertex.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbVertex.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbVertex.Name = "tsbVertex";
          this.tsbVertex.Size = new System.Drawing.Size(31, 20);
          this.tsbVertex.Text = "バーテックス(点)";
          this.tsbVertex.Click += new System.EventHandler(this.tsbVertex_Click);
          // 
          // tsbLine
          // 
          this.tsbLine.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbLine.Image = ((System.Drawing.Image)(resources.GetObject("tsbLine.Image")));
          this.tsbLine.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbLine.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbLine.Name = "tsbLine";
          this.tsbLine.Size = new System.Drawing.Size(31, 20);
          this.tsbLine.Text = "ライン(直線)";
          this.tsbLine.Click += new System.EventHandler(this.tsbLine_Click);
          // 
          // tsbPolyline
          // 
          this.tsbPolyline.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbPolyline.Image = ((System.Drawing.Image)(resources.GetObject("tsbPolyline.Image")));
          this.tsbPolyline.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbPolyline.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbPolyline.Name = "tsbPolyline";
          this.tsbPolyline.Size = new System.Drawing.Size(31, 20);
          this.tsbPolyline.Text = "ポリライン(折れ線)";
          this.tsbPolyline.Click += new System.EventHandler(this.tsbPolyline_Click);
          // 
          // tsbCurve
          // 
          this.tsbCurve.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCurve.Image = ((System.Drawing.Image)(resources.GetObject("tsbCurve.Image")));
          this.tsbCurve.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCurve.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCurve.Name = "tsbCurve";
          this.tsbCurve.Size = new System.Drawing.Size(31, 20);
          this.tsbCurve.Text = "カーブ(曲線)";
          this.tsbCurve.Click += new System.EventHandler(this.tsbCurve_Click);
          // 
          // tsbPlane
          // 
          this.tsbPlane.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbPlane.Image = ((System.Drawing.Image)(resources.GetObject("tsbPlane.Image")));
          this.tsbPlane.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbPlane.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbPlane.Name = "tsbPlane";
          this.tsbPlane.Size = new System.Drawing.Size(31, 20);
          this.tsbPlane.Text = "プレーン(面)";
          this.tsbPlane.ToolTipText = "プレーン(面)";
          this.tsbPlane.Click += new System.EventHandler(this.tsbPlane_Click);
          // 
          // tsbBox
          // 
          this.tsbBox.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbBox.Image = ((System.Drawing.Image)(resources.GetObject("tsbBox.Image")));
          this.tsbBox.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbBox.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbBox.Margin = new System.Windows.Forms.Padding(0);
          this.tsbBox.Name = "tsbBox";
          this.tsbBox.Size = new System.Drawing.Size(31, 20);
          this.tsbBox.Text = "ボックス(箱)";
          this.tsbBox.ToolTipText = "ボックス(箱)";
          this.tsbBox.Click += new System.EventHandler(this.tsbBox_Click);
          // 
          // tsbSphere
          // 
          this.tsbSphere.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbSphere.Image = ((System.Drawing.Image)(resources.GetObject("tsbSphere.Image")));
          this.tsbSphere.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbSphere.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbSphere.Name = "tsbSphere";
          this.tsbSphere.Size = new System.Drawing.Size(31, 20);
          this.tsbSphere.Text = "スフィア(球)";
          this.tsbSphere.ToolTipText = "スフィア(球)";
          this.tsbSphere.Click += new System.EventHandler(this.tsbSphere_Click);
          // 
          // tsbCylinder
          // 
          this.tsbCylinder.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCylinder.Image = ((System.Drawing.Image)(resources.GetObject("tsbCylinder.Image")));
          this.tsbCylinder.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCylinder.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCylinder.Name = "tsbCylinder";
          this.tsbCylinder.Size = new System.Drawing.Size(31, 20);
          this.tsbCylinder.Text = "シリンダー(円筒)";
          this.tsbCylinder.ToolTipText = "シリンダー(円筒)";
          this.tsbCylinder.Click += new System.EventHandler(this.tsbCylinder_Click);
          // 
          // tsbCone
          // 
          this.tsbCone.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCone.Image = ((System.Drawing.Image)(resources.GetObject("tsbCone.Image")));
          this.tsbCone.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCone.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCone.Name = "tsbCone";
          this.tsbCone.Size = new System.Drawing.Size(31, 20);
          this.tsbCone.Text = "コーン(円錐)";
          this.tsbCone.ToolTipText = "コーン(円錐)";
          this.tsbCone.Click += new System.EventHandler(this.tsbCone_Click);
          // 
          // tsbTorus
          // 
          this.tsbTorus.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbTorus.Image = ((System.Drawing.Image)(resources.GetObject("tsbTorus.Image")));
          this.tsbTorus.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbTorus.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbTorus.Name = "tsbTorus";
          this.tsbTorus.Size = new System.Drawing.Size(31, 20);
          this.tsbTorus.Text = "トーラス(輪)";
          this.tsbTorus.ToolTipText = "トーラス(輪)";
          this.tsbTorus.Click += new System.EventHandler(this.tsbTorus_Click);
          // 
          // toolStripSeparator8
          // 
          this.toolStripSeparator8.Name = "toolStripSeparator8";
          this.toolStripSeparator8.Size = new System.Drawing.Size(31, 6);
          // 
          // tsbCopy
          // 
          this.tsbCopy.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCopy.Image = ((System.Drawing.Image)(resources.GetObject("tsbCopy.Image")));
          this.tsbCopy.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCopy.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCopy.Name = "tsbCopy";
          this.tsbCopy.Size = new System.Drawing.Size(31, 20);
          this.tsbCopy.Text = "コピー";
          this.tsbCopy.Click += new System.EventHandler(this.tsbCopy_Click);
          // 
          // tsbDelete
          // 
          this.tsbDelete.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbDelete.Image = ((System.Drawing.Image)(resources.GetObject("tsbDelete.Image")));
          this.tsbDelete.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbDelete.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbDelete.Name = "tsbDelete";
          this.tsbDelete.Size = new System.Drawing.Size(31, 20);
          this.tsbDelete.Text = "削除";
          this.tsbDelete.Click += new System.EventHandler(this.tsbDelete_Click);
          // 
          // tsbCompound
          // 
          this.tsbCompound.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCompound.Image = ((System.Drawing.Image)(resources.GetObject("tsbCompound.Image")));
          this.tsbCompound.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCompound.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCompound.Name = "tsbCompound";
          this.tsbCompound.Size = new System.Drawing.Size(31, 20);
          this.tsbCompound.Text = "コンパウンド";
          this.tsbCompound.ToolTipText = "コンパウンド";
          this.tsbCompound.Click += new System.EventHandler(this.tsbCompound_Click);
          // 
          // toolStripSeparator9
          // 
          this.toolStripSeparator9.Name = "toolStripSeparator9";
          this.toolStripSeparator9.Size = new System.Drawing.Size(31, 6);
          // 
          // tsbExplode
          // 
          this.tsbExplode.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbExplode.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miExCompound,
            this.miExSolid,
            this.miExShell,
            this.miExFace,
            this.miExWire,
            this.miExEdge,
            this.miExVertex});
          this.tsbExplode.Image = ((System.Drawing.Image)(resources.GetObject("tsbExplode.Image")));
          this.tsbExplode.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbExplode.Name = "tsbExplode";
          this.tsbExplode.Size = new System.Drawing.Size(31, 20);
          this.tsbExplode.Text = "エクスプロード";
          this.tsbExplode.ToolTipText = "エクスプロード";
          // 
          // miExCompound
          // 
          this.miExCompound.Image = ((System.Drawing.Image)(resources.GetObject("miExCompound.Image")));
          this.miExCompound.Name = "miExCompound";
          this.miExCompound.Size = new System.Drawing.Size(166, 22);
          this.miExCompound.Text = "コンパウンド(&C)";
          this.miExCompound.Click += new System.EventHandler(this.miExCompound_Click);
          // 
          // miExSolid
          // 
          this.miExSolid.Image = ((System.Drawing.Image)(resources.GetObject("miExSolid.Image")));
          this.miExSolid.Name = "miExSolid";
          this.miExSolid.Size = new System.Drawing.Size(166, 22);
          this.miExSolid.Text = "ソリッド(&L)";
          this.miExSolid.Click += new System.EventHandler(this.miExSolid_Click);
          // 
          // miExShell
          // 
          this.miExShell.Image = ((System.Drawing.Image)(resources.GetObject("miExShell.Image")));
          this.miExShell.Name = "miExShell";
          this.miExShell.Size = new System.Drawing.Size(166, 22);
          this.miExShell.Text = "シェル(&S)";
          this.miExShell.Click += new System.EventHandler(this.miExShell_Click);
          // 
          // miExFace
          // 
          this.miExFace.Image = ((System.Drawing.Image)(resources.GetObject("miExFace.Image")));
          this.miExFace.Name = "miExFace";
          this.miExFace.Size = new System.Drawing.Size(166, 22);
          this.miExFace.Text = "フェイス(&F)";
          this.miExFace.Click += new System.EventHandler(this.miExFace_Click);
          // 
          // miExWire
          // 
          this.miExWire.Image = ((System.Drawing.Image)(resources.GetObject("miExWire.Image")));
          this.miExWire.Name = "miExWire";
          this.miExWire.Size = new System.Drawing.Size(166, 22);
          this.miExWire.Text = "ワイヤー(&W)";
          this.miExWire.Click += new System.EventHandler(this.miExWire_Click);
          // 
          // miExEdge
          // 
          this.miExEdge.Image = ((System.Drawing.Image)(resources.GetObject("miExEdge.Image")));
          this.miExEdge.Name = "miExEdge";
          this.miExEdge.Size = new System.Drawing.Size(166, 22);
          this.miExEdge.Text = "エッジ(&E)";
          this.miExEdge.Click += new System.EventHandler(this.miExEdge_Click);
          // 
          // miExVertex
          // 
          this.miExVertex.Image = ((System.Drawing.Image)(resources.GetObject("miExVertex.Image")));
          this.miExVertex.Name = "miExVertex";
          this.miExVertex.Size = new System.Drawing.Size(166, 22);
          this.miExVertex.Text = "バーテックス(&V)";
          this.miExVertex.Click += new System.EventHandler(this.miExVertex_Click);
          // 
          // toolStripSeparator11
          // 
          this.toolStripSeparator11.Name = "toolStripSeparator11";
          this.toolStripSeparator11.Size = new System.Drawing.Size(31, 6);
          // 
          // tsbTranslate
          // 
          this.tsbTranslate.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbTranslate.Image = ((System.Drawing.Image)(resources.GetObject("tsbTranslate.Image")));
          this.tsbTranslate.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbTranslate.Name = "tsbTranslate";
          this.tsbTranslate.Size = new System.Drawing.Size(31, 20);
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
          this.tsbRotate.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbRotate.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbRotate.Name = "tsbRotate";
          this.tsbRotate.Size = new System.Drawing.Size(31, 20);
          this.tsbRotate.Text = "回転";
          this.tsbRotate.ToolTipText = "回転";
          // 
          // tsbScale
          // 
          this.tsbScale.CheckOnClick = true;
          this.tsbScale.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbScale.Enabled = false;
          this.tsbScale.Image = ((System.Drawing.Image)(resources.GetObject("tsbScale.Image")));
          this.tsbScale.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbScale.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbScale.Name = "tsbScale";
          this.tsbScale.Size = new System.Drawing.Size(31, 20);
          this.tsbScale.Text = "拡大縮小";
          this.tsbScale.ToolTipText = "スケール";
          // 
          // tsbMirror
          // 
          this.tsbMirror.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbMirror.Enabled = false;
          this.tsbMirror.Image = ((System.Drawing.Image)(resources.GetObject("tsbMirror.Image")));
          this.tsbMirror.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbMirror.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbMirror.Name = "tsbMirror";
          this.tsbMirror.Size = new System.Drawing.Size(31, 20);
          this.tsbMirror.Text = "ミラー";
          // 
          // toolStripButton6
          // 
          this.toolStripButton6.Name = "toolStripButton6";
          this.toolStripButton6.Size = new System.Drawing.Size(31, 6);
          // 
          // tsbLoft
          // 
          this.tsbLoft.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbLoft.Image = ((System.Drawing.Image)(resources.GetObject("tsbLoft.Image")));
          this.tsbLoft.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbLoft.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbLoft.Name = "tsbLoft";
          this.tsbLoft.Size = new System.Drawing.Size(31, 20);
          this.tsbLoft.Text = "ロフト";
          this.tsbLoft.Click += new System.EventHandler(this.tsbLoft_Click);
          // 
          // tsbOffset
          // 
          this.tsbOffset.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbOffset.Image = ((System.Drawing.Image)(resources.GetObject("tsbOffset.Image")));
          this.tsbOffset.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbOffset.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbOffset.Name = "tsbOffset";
          this.tsbOffset.Size = new System.Drawing.Size(31, 20);
          this.tsbOffset.Text = "オフセット";
          // 
          // tsbSewing
          // 
          this.tsbSewing.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbSewing.Image = ((System.Drawing.Image)(resources.GetObject("tsbSewing.Image")));
          this.tsbSewing.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbSewing.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbSewing.Name = "tsbSewing";
          this.tsbSewing.Size = new System.Drawing.Size(31, 20);
          this.tsbSewing.Text = "シューイング";
          this.tsbSewing.Click += new System.EventHandler(this.tsbSewing_Click);
          // 
          // toolStripSeparator17
          // 
          this.toolStripSeparator17.Name = "toolStripSeparator17";
          this.toolStripSeparator17.Size = new System.Drawing.Size(31, 6);
          // 
          // tsbFuse
          // 
          this.tsbFuse.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbFuse.Image = ((System.Drawing.Image)(resources.GetObject("tsbFuse.Image")));
          this.tsbFuse.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbFuse.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbFuse.Name = "tsbFuse";
          this.tsbFuse.Size = new System.Drawing.Size(31, 20);
          this.tsbFuse.Text = "フューズ";
          this.tsbFuse.Click += new System.EventHandler(this.tsbFuse_Click);
          // 
          // tsbCut
          // 
          this.tsbCut.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCut.Image = ((System.Drawing.Image)(resources.GetObject("tsbCut.Image")));
          this.tsbCut.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCut.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCut.Name = "tsbCut";
          this.tsbCut.Size = new System.Drawing.Size(31, 20);
          this.tsbCut.Text = "カット";
          this.tsbCut.Click += new System.EventHandler(this.tsbCut_Click);
          // 
          // tsbCommon
          // 
          this.tsbCommon.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbCommon.Image = ((System.Drawing.Image)(resources.GetObject("tsbCommon.Image")));
          this.tsbCommon.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbCommon.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbCommon.Name = "tsbCommon";
          this.tsbCommon.Size = new System.Drawing.Size(31, 20);
          this.tsbCommon.Text = "コモン";
          this.tsbCommon.Click += new System.EventHandler(this.tsbCommon_Click);
          // 
          // tsbIntersect
          // 
          this.tsbIntersect.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbIntersect.Image = ((System.Drawing.Image)(resources.GetObject("tsbIntersect.Image")));
          this.tsbIntersect.ImageScaling = System.Windows.Forms.ToolStripItemImageScaling.None;
          this.tsbIntersect.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbIntersect.Name = "tsbIntersect";
          this.tsbIntersect.Size = new System.Drawing.Size(31, 20);
          this.tsbIntersect.Text = "インターセクション";
          this.tsbIntersect.Click += new System.EventHandler(this.tsbIntersect_Click);
          // 
          // toolStripSeparator16
          // 
          this.toolStripSeparator16.Name = "toolStripSeparator16";
          this.toolStripSeparator16.Size = new System.Drawing.Size(31, 6);
          // 
          // tsbInfo
          // 
          this.tsbInfo.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbInfo.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.miVolume,
            this.miCog,
            this.miBndbox});
          this.tsbInfo.Image = ((System.Drawing.Image)(resources.GetObject("tsbInfo.Image")));
          this.tsbInfo.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbInfo.Name = "tsbInfo";
          this.tsbInfo.Size = new System.Drawing.Size(31, 20);
          this.tsbInfo.Text = "toolStripSplitButton1";
          // 
          // miVolume
          // 
          this.miVolume.Name = "miVolume";
          this.miVolume.Size = new System.Drawing.Size(154, 22);
          this.miVolume.Text = "ボリューム(&V)";
          this.miVolume.Click += new System.EventHandler(this.miVolume_Click);
          // 
          // miCog
          // 
          this.miCog.Image = ((System.Drawing.Image)(resources.GetObject("miCog.Image")));
          this.miCog.Name = "miCog";
          this.miCog.Size = new System.Drawing.Size(154, 22);
          this.miCog.Text = "重心位置(&G)";
          this.miCog.Click += new System.EventHandler(this.miCog_Click);
          // 
          // miBndbox
          // 
          this.miBndbox.Image = ((System.Drawing.Image)(resources.GetObject("miBndbox.Image")));
          this.miBndbox.Name = "miBndbox";
          this.miBndbox.Size = new System.Drawing.Size(154, 22);
          this.miBndbox.Text = "範囲(&B)";
          this.miBndbox.Click += new System.EventHandler(this.miBndbox_Click);
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
          // toolStripSeparator3
          // 
          this.toolStripSeparator3.Name = "toolStripSeparator3";
          this.toolStripSeparator3.Size = new System.Drawing.Size(6, 25);
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
          // tsbRender
          // 
          this.tsbRender.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbRender.Enabled = false;
          this.tsbRender.Image = ((System.Drawing.Image)(resources.GetObject("tsbRender.Image")));
          this.tsbRender.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbRender.Name = "tsbRender";
          this.tsbRender.Size = new System.Drawing.Size(23, 22);
          this.tsbRender.Text = "レンダービュー";
          // 
          // tsbNew
          // 
          this.tsbNew.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbNew.Image = ((System.Drawing.Image)(resources.GetObject("tsbNew.Image")));
          this.tsbNew.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbNew.Name = "tsbNew";
          this.tsbNew.Size = new System.Drawing.Size(23, 22);
          this.tsbNew.Text = "新規ビューアー";
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
          // toolStripPanel1
          // 
          this.toolStripPanel1.Dock = System.Windows.Forms.DockStyle.Top;
          this.toolStripPanel1.Location = new System.Drawing.Point(0, 0);
          this.toolStripPanel1.Name = "toolStripPanel1";
          this.toolStripPanel1.Orientation = System.Windows.Forms.Orientation.Horizontal;
          this.toolStripPanel1.RowMargin = new System.Windows.Forms.Padding(3, 0, 0, 0);
          this.toolStripPanel1.Size = new System.Drawing.Size(1192, 0);
          // 
          // toolStripGeneral
          // 
          this.toolStripGeneral.Dock = System.Windows.Forms.DockStyle.None;
          this.toolStripGeneral.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
          this.toolStripGeneral.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsbNew,
            this.tsbOpen,
            this.tsbSave,
            this.tsbExit,
            this.toolStripSeparator3,
            this.tsbDump,
            this.tsbRender,
            this.toolStripSeparator1,
            this.tsbFit,
            this.tsbAxoView,
            this.tsbResetView,
            this.tsbHlr,
            this.toolStripSeparator12,
            this.tsbClipPlane,
            this.tsbSectionClipper,
            this.toolStripSeparator2,
            this.tsbDisplayMode,
            this.tsbTransparency,
            this.toolStripSeparator10,
            this.tsbColor,
            this.tsbMaterial,
            this.toolStripSeparator13,
            this.tsbHelp,
            this.tsbVersion});
          this.toolStripGeneral.LayoutStyle = System.Windows.Forms.ToolStripLayoutStyle.HorizontalStackWithOverflow;
          this.toolStripGeneral.Location = new System.Drawing.Point(3, 0);
          this.toolStripGeneral.Name = "toolStripGeneral";
          this.toolStripGeneral.Size = new System.Drawing.Size(502, 25);
          this.toolStripGeneral.TabIndex = 15;
          // 
          // toolStripSeparator1
          // 
          this.toolStripSeparator1.Name = "toolStripSeparator1";
          this.toolStripSeparator1.Size = new System.Drawing.Size(6, 25);
          // 
          // toolStripSeparator12
          // 
          this.toolStripSeparator12.Name = "toolStripSeparator12";
          this.toolStripSeparator12.Size = new System.Drawing.Size(6, 25);
          // 
          // tsbClipPlane
          // 
          this.tsbClipPlane.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbClipPlane.Image = ((System.Drawing.Image)(resources.GetObject("tsbClipPlane.Image")));
          this.tsbClipPlane.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbClipPlane.Name = "tsbClipPlane";
          this.tsbClipPlane.Size = new System.Drawing.Size(23, 22);
          this.tsbClipPlane.Text = "クリッピング";
          this.tsbClipPlane.Click += new System.EventHandler(this.tsbClipPlane_Click);
          // 
          // tsbSectionClipper
          // 
          this.tsbSectionClipper.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbSectionClipper.Enabled = false;
          this.tsbSectionClipper.Image = ((System.Drawing.Image)(resources.GetObject("tsbSectionClipper.Image")));
          this.tsbSectionClipper.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbSectionClipper.Name = "tsbSectionClipper";
          this.tsbSectionClipper.Size = new System.Drawing.Size(23, 22);
          this.tsbSectionClipper.Text = "セクション";
          this.tsbSectionClipper.ToolTipText = "セクション";
          this.tsbSectionClipper.Click += new System.EventHandler(this.tsbSectionClipper_Click);
          // 
          // toolStripSeparator2
          // 
          this.toolStripSeparator2.Name = "toolStripSeparator2";
          this.toolStripSeparator2.Size = new System.Drawing.Size(6, 25);
          // 
          // toolStripSeparator13
          // 
          this.toolStripSeparator13.Name = "toolStripSeparator13";
          this.toolStripSeparator13.Size = new System.Drawing.Size(6, 25);
          // 
          // tsbHelp
          // 
          this.tsbHelp.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbHelp.Enabled = false;
          this.tsbHelp.Image = ((System.Drawing.Image)(resources.GetObject("tsbHelp.Image")));
          this.tsbHelp.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbHelp.Name = "tsbHelp";
          this.tsbHelp.Size = new System.Drawing.Size(23, 22);
          this.tsbHelp.Text = "ヘルプ";
          this.tsbHelp.ToolTipText = "ヘルプ";
          // 
          // tsbVersion
          // 
          this.tsbVersion.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
          this.tsbVersion.Image = ((System.Drawing.Image)(resources.GetObject("tsbVersion.Image")));
          this.tsbVersion.ImageTransparentColor = System.Drawing.Color.Magenta;
          this.tsbVersion.Name = "tsbVersion";
          this.tsbVersion.Size = new System.Drawing.Size(23, 22);
          this.tsbVersion.Text = "バージョン情報";
          this.tsbVersion.ToolTipText = "バージョン情報";
          this.tsbVersion.Click += new System.EventHandler(this.tsbVersion_Click);
          // 
          // toolStripContainer1
          // 
          // 
          // toolStripContainer1.ContentPanel
          // 
          this.toolStripContainer1.ContentPanel.Controls.Add(this.splitContainer1);
          this.toolStripContainer1.ContentPanel.Size = new System.Drawing.Size(1159, 716);
          this.toolStripContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
          // 
          // toolStripContainer1.LeftToolStripPanel
          // 
          this.toolStripContainer1.LeftToolStripPanel.Controls.Add(this.toolStripMain);
          this.toolStripContainer1.Location = new System.Drawing.Point(0, 0);
          this.toolStripContainer1.Name = "toolStripContainer1";
          this.toolStripContainer1.Size = new System.Drawing.Size(1192, 741);
          this.toolStripContainer1.TabIndex = 7;
          this.toolStripContainer1.Text = "toolStripContainer1";
          // 
          // toolStripContainer1.TopToolStripPanel
          // 
          this.toolStripContainer1.TopToolStripPanel.Controls.Add(this.toolStripGeneral);
          // 
          // splitContainer1
          // 
          this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
          this.splitContainer1.Location = new System.Drawing.Point(0, 0);
          this.splitContainer1.Name = "splitContainer1";
          // 
          // splitContainer1.Panel1
          // 
          this.splitContainer1.Panel1.Controls.Add(this.splitContainer2);
          // 
          // splitContainer1.Panel2
          // 
          this.splitContainer1.Panel2.Controls.Add(this.propertyGrid1);
          this.splitContainer1.Size = new System.Drawing.Size(1159, 716);
          this.splitContainer1.SplitterDistance = 1003;
          this.splitContainer1.TabIndex = 0;
          // 
          // splitContainer2
          // 
          this.splitContainer2.Dock = System.Windows.Forms.DockStyle.Fill;
          this.splitContainer2.Location = new System.Drawing.Point(0, 0);
          this.splitContainer2.Name = "splitContainer2";
          this.splitContainer2.Orientation = System.Windows.Forms.Orientation.Horizontal;
          // 
          // splitContainer2.Panel1
          // 
          this.splitContainer2.Panel1.Controls.Add(this.splitContainer3);
          // 
          // splitContainer2.Panel2
          // 
          this.splitContainer2.Panel2.Controls.Add(this.myTerm);
          this.splitContainer2.Size = new System.Drawing.Size(1003, 716);
          this.splitContainer2.SplitterDistance = 611;
          this.splitContainer2.TabIndex = 0;
          // 
          // splitContainer3
          // 
          this.splitContainer3.Dock = System.Windows.Forms.DockStyle.Fill;
          this.splitContainer3.Location = new System.Drawing.Point(0, 0);
          this.splitContainer3.Name = "splitContainer3";
          // 
          // splitContainer3.Panel1
          // 
          this.splitContainer3.Panel1.Controls.Add(this.splitContainer4);
          this.splitContainer3.Size = new System.Drawing.Size(1003, 611);
          this.splitContainer3.SplitterDistance = 334;
          this.splitContainer3.TabIndex = 0;
          this.splitContainer3.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer3_Paint);
          // 
          // splitContainer4
          // 
          this.splitContainer4.Dock = System.Windows.Forms.DockStyle.Fill;
          this.splitContainer4.Location = new System.Drawing.Point(0, 0);
          this.splitContainer4.Name = "splitContainer4";
          this.splitContainer4.Orientation = System.Windows.Forms.Orientation.Horizontal;
          // 
          // splitContainer4.Panel1
          // 
          this.splitContainer4.Panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.splitContainer4_Panel1_Paint);
          this.splitContainer4.Size = new System.Drawing.Size(334, 611);
          this.splitContainer4.SplitterDistance = 301;
          this.splitContainer4.TabIndex = 0;
          // 
          // myTerm
          // 
          this.myTerm.BackColor = System.Drawing.Color.DarkGray;
          this.myTerm.Dock = System.Windows.Forms.DockStyle.Fill;
          this.myTerm.Location = new System.Drawing.Point(0, 0);
          this.myTerm.Name = "myTerm";
          this.myTerm.Padding = new System.Windows.Forms.Padding(1, 1, 2, 2);
          this.myTerm.Size = new System.Drawing.Size(1003, 101);
          this.myTerm.TabIndex = 0;
          // 
          // propertyGrid1
          // 
          this.propertyGrid1.Dock = System.Windows.Forms.DockStyle.Fill;
          this.propertyGrid1.Location = new System.Drawing.Point(0, 0);
          this.propertyGrid1.Name = "propertyGrid1";
          this.propertyGrid1.Size = new System.Drawing.Size(152, 716);
          this.propertyGrid1.TabIndex = 0;
          // 
          // MainForm
          // 
          this.AccessibleRole = System.Windows.Forms.AccessibleRole.Application;
          this.AllowDrop = true;
          this.AutoScaleBaseSize = new System.Drawing.Size(5, 12);
          this.ClientSize = new System.Drawing.Size(1192, 741);
          this.Controls.Add(this.toolStripContainer1);
          this.Controls.Add(this.toolStripPanel1);
          this.Controls.Add(this.toolStripPanel2);
          this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
          this.IsMdiContainer = true;
          this.Name = "MainForm";
          this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
          this.Text = "siren";
          this.Load += new System.EventHandler(this.MainForm_Load);
          this.Paint += new System.Windows.Forms.PaintEventHandler(this.MainForm_Paint);
          this.Shown += new System.EventHandler(this.MainForm_Shown);
          this.DragDrop += new System.Windows.Forms.DragEventHandler(this.MainForm_DragDrop);
          this.DragEnter += new System.Windows.Forms.DragEventHandler(this.MainForm_DragEnter);
          this.Resize += new System.EventHandler(this.MainForm_Resize);
          this.toolStripMain.ResumeLayout(false);
          this.toolStripMain.PerformLayout();
          this.toolStripGeneral.ResumeLayout(false);
          this.toolStripGeneral.PerformLayout();
          this.toolStripContainer1.ContentPanel.ResumeLayout(false);
          this.toolStripContainer1.LeftToolStripPanel.ResumeLayout(false);
          this.toolStripContainer1.TopToolStripPanel.ResumeLayout(false);
          this.toolStripContainer1.TopToolStripPanel.PerformLayout();
          this.toolStripContainer1.ResumeLayout(false);
          this.toolStripContainer1.PerformLayout();
          this.splitContainer1.Panel1.ResumeLayout(false);
          this.splitContainer1.Panel2.ResumeLayout(false);
          this.splitContainer1.ResumeLayout(false);
          this.splitContainer2.Panel1.ResumeLayout(false);
          this.splitContainer2.Panel2.ResumeLayout(false);
          this.splitContainer2.ResumeLayout(false);
          this.splitContainer3.Panel1.ResumeLayout(false);
          this.splitContainer3.ResumeLayout(false);
          this.splitContainer4.ResumeLayout(false);
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
        private ToolStripButton tsbResetView;
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
        private ToolStripButton tsbOpen;
        private ToolStripButton tsbSave;
        private ToolStripButton tsbExit;
        private ToolStripButton tsbDump;
        private ToolStripButton tsbCopy;
        private ToolStripButton tsbDelete;
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
        private ToolStripSeparator toolStripSeparator9;
        private ToolStripButton tsbCompound;
        private ToolStripSeparator toolStripSeparator11;
        private ToolStripSeparator toolStripSeparator3;
        private ToolStripButton tsbFuse;
        private ToolStripButton tsbCut;
        private ToolStripButton tsbCommon;
        private ToolStripButton tsbIntersect;
        private ToolStripSeparator toolStripSeparator16;
        private ToolStripSplitButton tsbInfo;
        private ToolStripMenuItem miVolume;
        private ToolStripMenuItem miCog;
        private ToolStripMenuItem miBndbox;
        private ToolStripButton tsbPlane;
        private ToolStripButton tsbRender;
        private ToolStripButton tsbVertex;
        private ToolStripButton tsbLine;
        private ToolStripButton tsbPolyline;
        private ToolStripButton tsbCurve;
        private ToolStripButton tsbLoft;
        private ToolStripSeparator toolStripSeparator17;
        private ToolStripSplitButton tsbExplode;
        private ToolStripMenuItem miExCompound;
        private ToolStripMenuItem miExSolid;
        private ToolStripMenuItem miExShell;
        private ToolStripMenuItem miExFace;
        private ToolStripMenuItem miExWire;
        private ToolStripMenuItem miExEdge;
        private ToolStripMenuItem miExVertex;
        private ToolStripPanel toolStripPanel1;
        private ToolStrip toolStripGeneral;
        private ToolStripButton tsbNew;
        private ToolStripSeparator toolStripSeparator1;
        private ToolStripButton tsbOffset;
        private ToolStripButton tsbSewing;
        private ToolStripButton tsbMirror;
        private ToolStripContainer toolStripContainer1;
        private SplitContainer splitContainer1;
        private SplitContainer splitContainer2;
        private SplitContainer splitContainer3;
        private SplitContainer splitContainer4;
        private PropertyGrid propertyGrid1;
        public term myTerm;
        private ToolStripButton tsbClipPlane;
        private ToolStripButton tsbSectionClipper;
        private ToolStripSeparator toolStripSeparator12;
        private ToolStripSeparator toolStripSeparator2;
        private ToolStripSeparator toolStripSeparator13;
        private ToolStripButton tsbHelp;
        private ToolStripButton tsbVersion;

    }
}
