namespace siren
{
  partial class ClipForm
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null)) {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      this.tb_xmin = new System.Windows.Forms.TrackBar();
      this.tb_xmax = new System.Windows.Forms.TrackBar();
      this.tb_ymin = new System.Windows.Forms.TrackBar();
      this.tb_ymax = new System.Windows.Forms.TrackBar();
      this.tb_zmin = new System.Windows.Forms.TrackBar();
      this.tb_zmax = new System.Windows.Forms.TrackBar();
      this.label1 = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.label3 = new System.Windows.Forms.Label();
      this.label4 = new System.Windows.Forms.Label();
      this.label5 = new System.Windows.Forms.Label();
      this.cb_usecap = new System.Windows.Forms.CheckBox();
      this.btOk = new System.Windows.Forms.Button();
      ((System.ComponentModel.ISupportInitialize)(this.tb_xmin)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_xmax)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_ymin)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_ymax)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_zmin)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_zmax)).BeginInit();
      this.SuspendLayout();
      // 
      // tb_xmin
      // 
      this.tb_xmin.Location = new System.Drawing.Point(32, 35);
      this.tb_xmin.Maximum = 100;
      this.tb_xmin.Name = "tb_xmin";
      this.tb_xmin.Size = new System.Drawing.Size(200, 42);
      this.tb_xmin.TabIndex = 0;
      this.tb_xmin.TickFrequency = 10;
      this.tb_xmin.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.tb_xmin.Scroll += new System.EventHandler(this.tb_xmin_Scroll);
      // 
      // tb_xmax
      // 
      this.tb_xmax.Location = new System.Drawing.Point(238, 35);
      this.tb_xmax.Maximum = 100;
      this.tb_xmax.Name = "tb_xmax";
      this.tb_xmax.Size = new System.Drawing.Size(200, 42);
      this.tb_xmax.TabIndex = 1;
      this.tb_xmax.TickFrequency = 10;
      this.tb_xmax.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.tb_xmax.Scroll += new System.EventHandler(this.tb_xmax_Scroll);
      // 
      // tb_ymin
      // 
      this.tb_ymin.Location = new System.Drawing.Point(32, 83);
      this.tb_ymin.Maximum = 100;
      this.tb_ymin.Name = "tb_ymin";
      this.tb_ymin.Size = new System.Drawing.Size(200, 42);
      this.tb_ymin.TabIndex = 2;
      this.tb_ymin.TickFrequency = 10;
      this.tb_ymin.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.tb_ymin.Scroll += new System.EventHandler(this.tb_ymin_Scroll);
      // 
      // tb_ymax
      // 
      this.tb_ymax.Location = new System.Drawing.Point(238, 83);
      this.tb_ymax.Maximum = 100;
      this.tb_ymax.Name = "tb_ymax";
      this.tb_ymax.Size = new System.Drawing.Size(200, 42);
      this.tb_ymax.TabIndex = 3;
      this.tb_ymax.TickFrequency = 10;
      this.tb_ymax.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.tb_ymax.Scroll += new System.EventHandler(this.tb_ymax_Scroll);
      // 
      // tb_zmin
      // 
      this.tb_zmin.Location = new System.Drawing.Point(32, 131);
      this.tb_zmin.Maximum = 100;
      this.tb_zmin.Name = "tb_zmin";
      this.tb_zmin.Size = new System.Drawing.Size(200, 42);
      this.tb_zmin.TabIndex = 4;
      this.tb_zmin.TickFrequency = 10;
      this.tb_zmin.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.tb_zmin.Scroll += new System.EventHandler(this.tb_zmin_Scroll);
      // 
      // tb_zmax
      // 
      this.tb_zmax.Location = new System.Drawing.Point(238, 131);
      this.tb_zmax.Maximum = 100;
      this.tb_zmax.Name = "tb_zmax";
      this.tb_zmax.Size = new System.Drawing.Size(200, 42);
      this.tb_zmax.TabIndex = 5;
      this.tb_zmax.TickFrequency = 10;
      this.tb_zmax.TickStyle = System.Windows.Forms.TickStyle.TopLeft;
      this.tb_zmax.Scroll += new System.EventHandler(this.tb_zmax_Scroll);
      // 
      // label1
      // 
      this.label1.Location = new System.Drawing.Point(8, 45);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(18, 23);
      this.label1.TabIndex = 6;
      this.label1.Text = "X:";
      this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
      // 
      // label2
      // 
      this.label2.Location = new System.Drawing.Point(32, 9);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(200, 23);
      this.label2.TabIndex = 7;
      this.label2.Text = "Minimum";
      this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // label3
      // 
      this.label3.Location = new System.Drawing.Point(9, 93);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(18, 23);
      this.label3.TabIndex = 8;
      this.label3.Text = "Y:";
      this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
      // 
      // label4
      // 
      this.label4.Location = new System.Drawing.Point(238, 9);
      this.label4.Name = "label4";
      this.label4.Size = new System.Drawing.Size(200, 23);
      this.label4.TabIndex = 9;
      this.label4.Text = "Maximum";
      this.label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      // 
      // label5
      // 
      this.label5.Location = new System.Drawing.Point(8, 141);
      this.label5.Name = "label5";
      this.label5.Size = new System.Drawing.Size(18, 23);
      this.label5.TabIndex = 10;
      this.label5.Text = "Z:";
      this.label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
      // 
      // cb_usecap
      // 
      this.cb_usecap.AutoSize = true;
      this.cb_usecap.Location = new System.Drawing.Point(12, 179);
      this.cb_usecap.Name = "cb_usecap";
      this.cb_usecap.Size = new System.Drawing.Size(131, 16);
      this.cb_usecap.TabIndex = 12;
      this.cb_usecap.Text = "切断面を面として表示";
      this.cb_usecap.UseVisualStyleBackColor = true;
      // 
      // btOk
      // 
      this.btOk.DialogResult = System.Windows.Forms.DialogResult.Cancel;
      this.btOk.Location = new System.Drawing.Point(345, 179);
      this.btOk.Name = "btOk";
      this.btOk.Size = new System.Drawing.Size(93, 23);
      this.btOk.TabIndex = 13;
      this.btOk.Text = "&OK";
      this.btOk.UseVisualStyleBackColor = true;
      this.btOk.Click += new System.EventHandler(this.btOk_Click);
      // 
      // ClipForm
      // 
      this.AcceptButton = this.btOk;
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(453, 217);
      this.Controls.Add(this.btOk);
      this.Controls.Add(this.cb_usecap);
      this.Controls.Add(this.label5);
      this.Controls.Add(this.label4);
      this.Controls.Add(this.label3);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.tb_zmax);
      this.Controls.Add(this.tb_zmin);
      this.Controls.Add(this.tb_ymax);
      this.Controls.Add(this.tb_ymin);
      this.Controls.Add(this.tb_xmax);
      this.Controls.Add(this.tb_xmin);
      this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
      this.MaximizeBox = false;
      this.MinimizeBox = false;
      this.Name = "ClipForm";
      this.ShowIcon = false;
      this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
      this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
      this.Text = "クリッピング";
      this.TopMost = true;
      this.Load += new System.EventHandler(this.ClipForm_Load);
      this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.ClipForm_FormClosed);
      ((System.ComponentModel.ISupportInitialize)(this.tb_xmin)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_xmax)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_ymin)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_ymax)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_zmin)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.tb_zmax)).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TrackBar tb_xmin;
    private System.Windows.Forms.TrackBar tb_xmax;
    private System.Windows.Forms.TrackBar tb_ymin;
    private System.Windows.Forms.TrackBar tb_ymax;
    private System.Windows.Forms.TrackBar tb_zmin;
    private System.Windows.Forms.TrackBar tb_zmax;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label2;
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.Label label4;
    private System.Windows.Forms.Label label5;
    private System.Windows.Forms.CheckBox cb_usecap;
    private System.Windows.Forms.Button btOk;
  }
}