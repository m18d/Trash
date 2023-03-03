using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp1
{
    public class House
    {
        public House(int number)
        {
            Number = number;
            Apartment = new int[5];
        }

        public int Number { get; private set; }
        public int[] Apartment { get; set; }
    }
}
