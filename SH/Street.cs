using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp1
{
    internal class Street
    {
        public Street(string nameStreet)
        {
            NameStreet = nameStreet;
            house = null;
            Count = 0;
        }

        public string NameStreet { get; private set; }
        private House house { get; set; }
        public int Count { get; private set; }

        public void AddHouse(int Number)
        {
            if (house == null)
            {
                this.Count++;
                house = new House(Number, this.Count);
            }
            else
            {
                this.Count++;
                House current = this.house;
                while (current.NextHouse != null)
                {
                    current = current.NextHouse;
                }
                current.NextHouse = new House(Number, this.Count);
            }
        }
        public void RemoveHouse(int index)
        {
            if (index >= 0 && index <= this.Count)
            {
                House current = this.house;
                while (current.NextHouse.ID != index)
                {
                    current = current.NextHouse;
                }
                House toDel = current.NextHouse;
                current.NextHouse = toDel.NextHouse;
                toDel.NextHouse = null;
                this.Count--;
                CheckOrderID();
            }
        }
        private void CheckOrderID()
        {
            House current = this.house;
            for (int i = 0; i < Count; i++)
            {
                if (current.ID == i + 1)
                {
                    current = current.NextHouse;
                }
                else
                {
                    current.ID = current.ID - 1;
                    current = current.NextHouse;
                }
            }
        }
        public int SumResidentInStreet()
        {
            House current = this.house;
            int sum = 0;
            for (int i = 0; i < this.Count; i++)
            {
                sum += current.SumResidents();
                current = current.NextHouse;
            }
            return sum;
        }
    }
}
