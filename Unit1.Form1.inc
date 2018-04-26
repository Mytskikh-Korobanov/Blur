procedure InitializeComponent;
    begin
        self.pictureBox1 := new System.Windows.Forms.PictureBox();
        self.button1 := new System.Windows.Forms.Button();
        self.openFileDialog1 := new System.Windows.Forms.OpenFileDialog();
        self.pictureBox2 := new System.Windows.Forms.PictureBox();
        self.pictureBox3 := new System.Windows.Forms.PictureBox();
        self.label1 := new System.Windows.Forms.Label();
        self.label2 := new System.Windows.Forms.Label();
        self.label3 := new System.Windows.Forms.Label();
        self.trackBar1 := new System.Windows.Forms.TrackBar();
        self.label4 := new System.Windows.Forms.Label();
        (System.ComponentModel.ISupportInitialize(self.pictureBox1)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.pictureBox2)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.pictureBox3)).BeginInit();
        (System.ComponentModel.ISupportInitialize(self.trackBar1)).BeginInit();
        self.SuspendLayout();
        // 
        // pictureBox1
        // 
        self.pictureBox1.Location := new System.Drawing.Point(12, 12);
        self.pictureBox1.Name := 'pictureBox1';
        self.pictureBox1.Size := new System.Drawing.Size(272, 237);
        self.pictureBox1.SizeMode := System.Windows.Forms.PictureBoxSizeMode.StretchImage;
        self.pictureBox1.TabIndex := 0;
        self.pictureBox1.TabStop := false;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(275, 315);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(75, 23);
        self.button1.TabIndex := 1;
        self.button1.Text := 'Открыть';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // openFileDialog1
        // 
        self.openFileDialog1.FileName := 'openFileDialog1';
        // 
        // pictureBox2
        // 
        self.pictureBox2.Location := new System.Drawing.Point(322, 12);
        self.pictureBox2.Name := 'pictureBox2';
        self.pictureBox2.Size := new System.Drawing.Size(272, 237);
        self.pictureBox2.SizeMode := System.Windows.Forms.PictureBoxSizeMode.StretchImage;
        self.pictureBox2.TabIndex := 2;
        self.pictureBox2.TabStop := false;
        // 
        // pictureBox3
        // 
        self.pictureBox3.Location := new System.Drawing.Point(631, 12);
        self.pictureBox3.Name := 'pictureBox3';
        self.pictureBox3.Size := new System.Drawing.Size(272, 237);
        self.pictureBox3.SizeMode := System.Windows.Forms.PictureBoxSizeMode.StretchImage;
        self.pictureBox3.TabIndex := 3;
        self.pictureBox3.TabStop := false;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(82, 263);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(135, 23);
        self.label1.TabIndex := 4;
        self.label1.Text := 'Исходное изображение';
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(385, 263);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(149, 23);
        self.label2.TabIndex := 5;
        self.label2.Text := 'Монохромное изобращение';
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(702, 263);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(132, 23);
        self.label3.TabIndex := 6;
        self.label3.Text := 'Размытое изображение';
        // 
        // trackBar1
        // 
        self.trackBar1.Location := new System.Drawing.Point(668, 316);
        self.trackBar1.Minimum := 1;
        self.trackBar1.Name := 'trackBar1';
        self.trackBar1.Size := new System.Drawing.Size(104, 45);
        self.trackBar1.TabIndex := 7;
        self.trackBar1.Value := 1;
        self.trackBar1.Scroll += On_Scroll;
        // 
        // label4
        // 
        self.label4.Location := new System.Drawing.Point(528, 316);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(134, 23);
        self.label4.TabIndex := 8;
        self.label4.Text := 'Коэффициент размытия';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(915, 350);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.trackBar1);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.pictureBox3);
        self.Controls.Add(self.pictureBox2);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.pictureBox1);
        self.Name := 'Form1';
        self.Text := 'Размытие по Гауссу';
        (System.ComponentModel.ISupportInitialize(self.pictureBox1)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.pictureBox2)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.pictureBox3)).EndInit();
        (System.ComponentModel.ISupportInitialize(self.trackBar1)).EndInit();
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
