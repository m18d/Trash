namespace Practic2
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.BSave = new System.Windows.Forms.Button();
            this.TBStreet = new System.Windows.Forms.TextBox();
            this.TextStreet = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.TBHouse = new System.Windows.Forms.TextBox();
            this.TBindex = new System.Windows.Forms.TextBox();
            this.TBSum = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(42, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Улица:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 187);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(91, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Название улицы";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(114, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Информация о улице";
            // 
            // BSave
            // 
            this.BSave.Location = new System.Drawing.Point(12, 340);
            this.BSave.Name = "BSave";
            this.BSave.Size = new System.Drawing.Size(169, 23);
            this.BSave.TabIndex = 3;
            this.BSave.Text = "Save";
            this.BSave.UseVisualStyleBackColor = true;
            this.BSave.Click += new System.EventHandler(this.BSave_Click);
            // 
            // TBStreet
            // 
            this.TBStreet.Location = new System.Drawing.Point(106, 184);
            this.TBStreet.Name = "TBStreet";
            this.TBStreet.Size = new System.Drawing.Size(100, 20);
            this.TBStreet.TabIndex = 4;
            // 
            // TextStreet
            // 
            this.TextStreet.AutoSize = true;
            this.TextStreet.Location = new System.Drawing.Point(60, 27);
            this.TextStreet.Name = "TextStreet";
            this.TextStreet.Size = new System.Drawing.Size(91, 13);
            this.TextStreet.TabIndex = 5;
            this.TextStreet.Text = "Название улицы";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(9, 213);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(90, 13);
            this.label4.TabIndex = 6;
            this.label4.Text = "Редактор домов";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(9, 235);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(70, 13);
            this.label5.TabIndex = 7;
            this.label5.Text = "Номер дома";
            // 
            // TBHouse
            // 
            this.TBHouse.Location = new System.Drawing.Point(106, 232);
            this.TBHouse.Name = "TBHouse";
            this.TBHouse.Size = new System.Drawing.Size(100, 20);
            this.TBHouse.TabIndex = 8;
            // 
            // TBindex
            // 
            this.TBindex.Location = new System.Drawing.Point(349, 184);
            this.TBindex.Name = "TBindex";
            this.TBindex.Size = new System.Drawing.Size(100, 20);
            this.TBindex.TabIndex = 9;
            // 
            // TBSum
            // 
            this.TBSum.Location = new System.Drawing.Point(349, 232);
            this.TBSum.Name = "TBSum";
            this.TBSum.Size = new System.Drawing.Size(100, 20);
            this.TBSum.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(252, 187);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(80, 13);
            this.label6.TabIndex = 11;
            this.label6.Text = "кол-во комнат";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(252, 235);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(65, 13);
            this.label7.TabIndex = 12;
            this.label7.Text = "количество";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(720, 375);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.TBSum);
            this.Controls.Add(this.TBindex);
            this.Controls.Add(this.TBHouse);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.TextStreet);
            this.Controls.Add(this.TBStreet);
            this.Controls.Add(this.BSave);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button BSave;
        private System.Windows.Forms.TextBox TBStreet;
        private System.Windows.Forms.Label TextStreet;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox TBHouse;
        private System.Windows.Forms.TextBox TBindex;
        private System.Windows.Forms.TextBox TBSum;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
    }
}

