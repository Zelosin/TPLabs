using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Confrontation
{
    class City : Locality
    {
        public bool isRegionCenter;
        public City() { }
        public City(String pName, String pRegion, bool pIsRegionName) {
            this.Name = pName;
            this.Region = pRegion;
            this.isRegionCenter = pIsRegionName;
        }

        public override void output()
        {
            base.output();
            Console.WriteLine("This is a region center: " + this.isRegionCenter);
        }

        public void input()
        {
            base.input();
            Console.Write("Is this a region center?: ");
            isRegionCenter = System.Convert.ToBoolean(Console.ReadLine());
        }

        public override string ToString()
        {
            output();
            return null;
        }
    }
}
