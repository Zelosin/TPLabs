using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Confrontation {

    class Program{

        delegate void InputDelegate();
        delegate void OutputDelegate();
        static void Main(string[] args){

            City FirstSampleCity = new City();
            City SecondSampleCity = new City();
            City ThirdSampleCity = new City();
            InputDelegate SampleInputDelegate = new InputDelegate(FirstSampleCity.input);
            OutputDelegate SampleOutputDelegate = new OutputDelegate(FirstSampleCity.output);
            SampleInputDelegate();
            SampleOutputDelegate();
            SampleInputDelegate += SecondSampleCity.input;
            SampleInputDelegate += ThirdSampleCity.input;
            SampleOutputDelegate += SecondSampleCity.output;
            SampleOutputDelegate += ThirdSampleCity.output;
            SampleInputDelegate();
            SampleOutputDelegate();
            SampleInputDelegate -= FirstSampleCity.input;
            SampleInputDelegate -= SecondSampleCity.input;
            SampleInputDelegate -= ThirdSampleCity.input;
            SampleOutputDelegate -= FirstSampleCity.output;
            SampleOutputDelegate -= SecondSampleCity.output;
            SampleOutputDelegate -= ThirdSampleCity.output;

            try{
                SampleInputDelegate();
            }
            catch (NullReferenceException){
                Console.WriteLine("Input delegate was ungrouped");
            }
            try{
                SampleOutputDelegate();
            }
            catch (NullReferenceException){
                Console.WriteLine("Output delegate was ungrouped");
            }

            Console.Read();
           
        }
    }
}
