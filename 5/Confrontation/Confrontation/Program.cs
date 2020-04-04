using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Confrontation {

    class Program{


        static Dictionary<int, City> mObjectCollection = new Dictionary<int, City>();
        static void Main(string[] args){

            City SampleCity = new City();
            SampleCity.input();


            mObjectCollection.Add(1, SampleCity);
            mObjectCollection.Add(2, SampleCity);
            WriteFile("test.txt", ref mObjectCollection);
            foreach (KeyValuePair<int, City> kvp in mObjectCollection)
                Console.WriteLine(string.Format("Key = {0} {1}", kvp.Key, kvp.Value));
            mObjectCollection.Clear();
            Console.WriteLine("Serialize...");
            ReadFile("test.txt", ref mObjectCollection);
            foreach (KeyValuePair<int, City> kvp in mObjectCollection)
                Console.WriteLine(string.Format("Key = {0} {1}", kvp.Key, kvp.Value));      

            Console.Read();
           
        }

        static void WriteFile(string FileName, ref Dictionary<int, City> pSampleCity){
            using (StreamWriter writer = File.CreateText(FileName)){
                foreach (KeyValuePair<int, City> entry in pSampleCity){
                    writer.WriteLine(entry.Key);
                    writer.WriteLine(entry.Value.Name);
                    writer.WriteLine(entry.Value.Region);
                    writer.WriteLine(entry.Value.isRegionCenter);
                }
            }
        }


        static void ReadFile(string FileName, ref Dictionary<int, City> pSampleCity)
        {
            using (StreamReader reader = File.OpenText(FileName))
            {
                while (!reader.EndOfStream){
                    pSampleCity.Add(Convert.ToInt32(reader.ReadLine()), 
                        new City(reader.ReadLine(), reader.ReadLine(), System.Convert.ToBoolean(reader.ReadLine())));
                }
            }
        }

    }
}
