using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Confrontation
{
    class Township : Locality
    {
        public int SchoolCount;
        public override void output()
        {
            base.output();
            Console.WriteLine("A count of schools: " + this.SchoolCount);
        }

        public void input()
        {
            base.input();
            Console.Write("Enter a count of schools: ");
            SchoolCount = Int32.Parse(Console.ReadLine());
        }

    }
}
