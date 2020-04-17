using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Confrontation {

    class Program{
    static void Main(string[] args){

            InputInterface inputInterface;
            OutputAbstract outputAbstract;


            Locality SampleLocality = new Locality();
             inputInterface = SampleLocality;
             inputInterface.input();
             outputAbstract = SampleLocality;
             outputAbstract.output();
             
            Village SampleCity = new Village();
            inputInterface = SampleCity;
            inputInterface.input();
            outputAbstract = SampleCity;
            outputAbstract.output();


            Console.Read();
           
        }
    }
}
