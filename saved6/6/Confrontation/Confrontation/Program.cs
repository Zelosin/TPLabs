using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Confrontation {

    class Program{

        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void InputCity(ref City CitySample);

        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void OutputCity(ref City CitySample);

        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void InputTownship(ref Township TownshipSample);

        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void OutputTownship(ref Township TownshipSample);

        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void InputVillage(ref Village VillageSample);

        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void OutputVillage(ref Village VillageSample);



        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int InputInt();
        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void OutputInt(int Param);


        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern int InputStr([MarshalAs(UnmanagedType.LPWStr)] StringBuilder dst);
        [DllImport("DLLdl.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        public static extern void OutputStr(string src);


        static void Main(string[] args){

            Locality SampleLocality = new Locality();
            StringBuilder BufferString = new StringBuilder(100);
            Console.WriteLine("Input a name of the region: ");
            InputStr(BufferString);
            SampleLocality.Name = BufferString.ToString();
            BufferString.Clear();
            Console.WriteLine("Input a regional center of the region: ");
            InputStr(BufferString);
            SampleLocality.Region = BufferString.ToString();
            BufferString.Clear();

            Console.WriteLine("Input a population of the region: ");
            SampleLocality.Population = InputInt();
            SampleLocality.output();


            City SampleCity = new City();
            InputCity(ref SampleCity);
            OutputCity(ref SampleCity);


            Township SampleTownship = new Township();
            InputTownship(ref SampleTownship);
            OutputTownship(ref SampleTownship);

            Village SampleVillage = new Village();
            InputVillage(ref SampleVillage);
            OutputVillage(ref SampleVillage);

            Console.Read();
        
        }


    }
}
