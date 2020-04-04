using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Confrontation {

    class Program{
    static void Main(string[] args){

            Village SampleVillage = new Village();
            SampleVillage.input();

            Village SecondVillageSample = new Village();
            SecondVillageSample.input();

            Console.WriteLine(SampleVillage <= 5);
            Console.WriteLine(SampleVillage <= "sdzxc");
            Console.WriteLine(SampleVillage <= SecondVillageSample);

            Console.WriteLine((SampleVillage & 5).Name);
            Console.WriteLine((SampleVillage & "Test").Name);
            Console.WriteLine((SampleVillage & SecondVillageSample).Name);

            Console.Read();
           
        }
    }
}
