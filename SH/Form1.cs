using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WpfApp1;

namespace Practic2
{
    public partial class Form1 : Form
    {
        Street street;
        public Form1()
        {
            InitializeComponent();
        }

        private void BSave_Click(object sender, EventArgs e)
        {
            if (TBStreet.Text != "" && TextStreet.Text == "Название улицы")
            {
                street = new Street(TBStreet.Text);
                TextStreet.Text = street.StreetName;
            }
            if (street != null)
            {
                if (TBHouse.Text != "" && TBindex.Text == "")
                {
                    street.AddHouse(int.Parse(TBHouse.Text));
                    UpdateApartList();
                }
                if (TBHouse.Text != "" && TBindex.Text != "")
                {
                    street.AddApartment(int.Parse(TBHouse.Text), int.Parse(TBindex.Text), int.Parse(TBSum.Text));
                    UpdateApartList();
                }
            }
            clearTB();
        }
        void clearTB()
        {
            TBHouse.Text = "";
            TBStreet.Text = "";
        }
        void UpdateApartList()
        {
            if (street.Count != 0)
            {
                int x = 15;
                int y = 70;
                const int Width = 50;
                const int LHeight = 55;
                const int Height = 70;
                ListBox lb;
                Label label;
                Label labelSum;
                for (int i = 0; i < street.Count; i++)
                {
                    House house = street.HouseInfo[i];
                    label = new Label();
                    label.Location = new Point((x + Width) * (i + 1) - 50, LHeight);
                    string widthS = house.Number.ToString();
                    label.Size = new Size(widthS.Length * 10, 13);
                    label.Text = house.Number.ToString();
                    labelSum = new Label();
                    labelSum.Location = new Point((x + Width) * (i + 1) - 50, LHeight + Height + 15);
                    labelSum.Size = new Size(20, 13);
                    labelSum.Text = street.SumOneApartment(i).ToString();
                    lb = new ListBox();
                    lb.Size = new Size(Width, Height);
                    lb.Location = new Point((x + Width) * (i + 1) - 50, y);
                    foreach (int apart in house.Apartment)
                    {
                        lb.Items.Add(apart);
                    }
                    this.Controls.Add(lb);
                    this.Controls.Add(labelSum);
                    this.Controls.Add(label);
                }
            }
        }
    }
}
