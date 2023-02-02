using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Navigation;

namespace WpfApp1
{
    internal class House
    {
        public House(int HouseNumber, int ID, House NextHouse = null)
        {
            this.NextHouse = NextHouse;
            this.ID = ID;
            this.HouseNumber = HouseNumber;
        }

        public House NextHouse
        {
            get { return this.NextHouse; }
            set { this.NextHouse = value; }
        }
        public int ID
        {
            get { return this.ID; }
            set { this.ID = value; }
        }
        private static int SIZE = 5;
        private int[] apartments = new int[SIZE];
        public int HouseNumber
        {
            get { return this.HouseNumber; }
            set { this.HouseNumber = value; }
        }
        public int GetApartmnet(int index)
        {
            return this.apartments[index];
        }
        public void SetApartment(int data, int index)
        {
            this.apartments[index] = data;
        }
        public void DelApartment(int index)
        {
            this.apartments[index] = 0;
        }
        public int SumResidents()
        {
            int sum = 0;
            foreach (int resident in this.apartments) { sum += resident; }
            return sum;
        }
    }
}
