using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace WpfApp1
{
    internal class Street
    {
        public string StreetName { get; private set; }
        public List<House> HouseInfo { get; private set; }
        public int Count { get; private set; }
        public Street(string streetname)
        {
            StreetName = streetname;
            HouseInfo = new List<House>();
            Count = 0;
        }
        public void AddHouse(int number)
        {
            HouseInfo.Add(new House(number));
            Count++;
        }
        public void RemoveHouse(int number)
        {
            if (HouseInfo.Count > 0)
            {
                foreach (House house in HouseInfo)
                {
                    if (house.Number == number)
                    { 
                        HouseInfo.Remove(house);
                        Count--;
                    }
                }
            }
        }
        public void AddApartment(int number, int index, int quantity)
        {
            if (HouseInfo.Count > 0)
            {
                foreach(House house in HouseInfo)
                {
                    if(house.Number == number)
                    {
                        house.Apartment[index] = quantity;
                        break;
                    }
                }
            }
        }
        public void RemoveApartment(int number, int index)
        {
            if (HouseInfo.Count > 0)
            {
                foreach (House house in HouseInfo)
                {
                    if (house.Number == number)
                    {
                        house.Apartment[index] = 0;
                        break;
                    }
                }
            }
        }
        public int SumOneApartment(int HouseNumber)
        {
            if (HouseInfo.Count > 0)
            {
                foreach (House house in HouseInfo)
                {
                    if (HouseNumber == house.Number)
                    {
                        int sum = 0;
                        for (int i = 0; i < house.Apartment.Length; i++)
                        {
                            sum += house.Apartment[i] * (i +1);
                        }
                        return sum;
                    }
                }
            }
            return 0;
        }
        public int SumAllApartment()
        {
            if (HouseInfo.Count > 0)
            {
                int sum = 0;
                foreach (House house in HouseInfo)
                {
                    for (int i = 0; i < house.Apartment.Length; i++)
                    {
                        sum += house.Apartment[i] * (i + 1);
                    }
                }
                return sum;
            }
            return 0;
        }
    }
}
