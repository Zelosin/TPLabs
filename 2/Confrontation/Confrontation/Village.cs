using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Confrontation
{
    class Village : Township
    {
        public int ShopCount;
        public override void output()
        {
            base.output();
            Console.WriteLine("A count of shops: " + this.ShopCount);
        }

        public void input()
        {
            base.input();
            Console.Write("Enter a count of shops: ");
            ShopCount = Int32.Parse(Console.ReadLine());
        }

        public static bool operator <=(Village pSampleVillage, int pParam)
        {
            if ((pSampleVillage.Name.Length <= pParam))
                return true;
            else
                return false;
        }

        public static bool operator >=(Village pSampleVillage, int pParam)
        {
            if ((pSampleVillage.Name.Length >= pParam))
                return true;
            else
                return false;
        }

        public static bool operator <=(Village pSampleVillage, string pParam)
        {
            if (pSampleVillage.Name.Length < pParam.Length)
                return true;
            if (pSampleVillage.Name.Length >= 5 && pParam.Length >= 5)
            {
                if (pSampleVillage.Name.Substring(
                    pSampleVillage.Name.Length - 5).Equals(
                        pParam.Substring(pParam.Length - 5)
                    ))
                    return true;
                else
                    return false;
            }
            return false;
        }

        public static bool operator >=(Village pSampleVillage, string pParam)
        {
            if (pSampleVillage.Name.Length > pParam.Length)
                return true;
            if (pSampleVillage.Name.Length >= 5 && pParam.Length >= 5)
            {
                if (pSampleVillage.Name.Substring(
                    pSampleVillage.Name.Length - 5).Equals(
                        pParam.Substring(pParam.Length - 5)
                    ))
                    return true;
                else
                    return false;
            }
            return false;
        }

        public static bool operator >=(Village pSampleVillage, Village pParam)
        {
            if (pSampleVillage.Name.Length > pParam.Name.Length)
                return true;
            if (pSampleVillage.Name.Length >= 5 && pParam.Name.Length >= 5)
            {
                if (pSampleVillage.Name.Substring(
                    pSampleVillage.Name.Length - 5).Equals(
                        pParam.Name.Substring(pParam.Name.Length - 5)
                    ))
                    return true;
                else
                    return false;
            }
            return false;
        }

        public static bool operator <=(Village pSampleVillage, Village pParam)
        {
            if (pSampleVillage.Name.Length < pParam.Name.Length)
                return true;
            if (pSampleVillage.Name.Length >= 5 && pParam.Name.Length >= 5)
            {
                if (pSampleVillage.Name.Substring(
                    pSampleVillage.Name.Length - 5).Equals(
                        pParam.Name.Substring(pParam.Name.Length - 5)
                    ))
                    return true;
                else
                    return false;
            }
            return false;
        }

        static public Village operator &(Village pSampleVillage, int pParam){
            pSampleVillage.Name = pSampleVillage.Name.Substring(0, 6) + pParam + pSampleVillage.Name.Substring(6);
            return pSampleVillage;
        }

        static public Village operator &(Village pSampleVillage, string pParam)
        {
            pSampleVillage.Name = pSampleVillage.Name.Substring(0, 6) + pParam +pSampleVillage.Name.Substring(6);
            return pSampleVillage;
        }

        static public Village operator &(Village pSampleVillage, Village pParam)
        {
            pSampleVillage.Name = pSampleVillage.Name.Substring(0, 6) + pParam.Name + pSampleVillage.Name.Substring(6);
            return pSampleVillage;
        }
    }
}