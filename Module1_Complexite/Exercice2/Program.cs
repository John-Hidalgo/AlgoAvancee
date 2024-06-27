using System.Collections.Immutable;
using System.Globalization;
using System.Security.Cryptography.X509Certificates;
using static System.Net.Mime.MediaTypeNames;


namespace Exercice2
{
    internal class Program
    {
        
        private static List<int[]> lesTests = new List<int[]> {
            GenererTableau((int)Math.Pow(2,1)),
            GenererTableau((int)Math.Pow(2, 10)),
            GenererTableau((int)Math.Pow(2, 11)),
            GenererTableau((int)Math.Pow(2, 12)),
            GenererTableau((int)Math.Pow(2, 13)),
            GenererTableau((int)Math.Pow(2, 14)),
            GenererTableau((int)Math.Pow(2, 15)),
            GenererTableau((int)Math.Pow(2, 16)),
            GenererTableau((int)Math.Pow(2, 17)),
            GenererTableau((int)Math.Pow(2, 18)),
            GenererTableau((int)Math.Pow(2,19)),
            GenererTableau((int)Math.Pow(2,20)),
            GenererTableau((int)Math.Pow(2,21)),
            GenererTableau((int)Math.Pow(2,22)),
            GenererTableau((int)Math.Pow(2,23))
            };
        static void Main(string[] args)
        {
            //TesterTempsChercherClassiqueDuTableau(lesTests);
            //Console.WriteLine();
            //foreach (long[] test in lesTests) { Array.Sort(test); }
            //TesterTempsChercherDichotamiqueDuTableau(lesTests);
            long[] arr = new long[10]
            {
                1, 5, 4, 11, 20, 8, 2, 98, 90, 16
            };
            // 1,5,
            // 1,4,5
            //1,4,5,11,
            //1,4,5,11,20
            //1,4,5,11,8,20
            //1,4,5,11,8,2,20


            //foreach(var test in lesTests) { TriRapide(test); }
            //TriABulle(arr);
            //TriRapide(arr);

            //foreach(var tableau in lesTests)
            //    TriABulle(tableau,0);
            //Console.WriteLine("Sorted Values:");
            //for (int i = 0; i < arr.Length; i++)
            //    Console.Write(arr[i] + " ,");
            //    Console.WriteLine();
            //TesterTempsTrisABulle(lesTests);
            //TriRapide(arr);
            //foreach (var test in lesTests) { TriRapide(test); }
            TesterTempsTrisRapide(lesTests);

        }
        //public static void TesterTempsChercherClassiqueDuTableau(List<long[]> tableaus)
        //{
        //    foreach (var tableau in tableaus)
        //        TesterEtAfficher(tableau, LaMoyenneDuTests(tableau, 1000, RechercheClassique));   
        //}
        public static void TesterTempsChercherDichotamiqueDuTableau(List<int[]> tableaus)
        {
            foreach (var tableau in tableaus)
                TesterEtAfficher(tableau, LaMoyenneDuTests(tableau, 1000, RechercherDichotamique));
        }
        public static void TesterTempsTrisABulle(List<int[]> tableaus)
        {
            foreach (var tableau in tableaus)
                TesterEtAfficher(tableau, LaMoyenneDuTests(tableau,10,TriABulle));
        }
        public static void TesterTempsTrisRapide(List<int[]> tableaus)
        {
            foreach (var tableau in tableaus)
                TesterEtAfficher(tableau, LaMoyenneDuTests(tableau,1, TriRapide));
        }
        public static int[] GenererTableau(int p_longeur)
        {
            Random nombre = new Random();
            int[] monTableau = new int[p_longeur];
            for (int j = 0; j < p_longeur; j++)
            {
                monTableau[j] = nombre.Next(9999);//returns random integers < 10
            }
            return monTableau;
        }
        public static void TesterEtAfficher(int[]tableau, double moyenne)
        {
            Console.WriteLine(MesurerRecheche(tableau, moyenne).ToString());
        }
        public static (int,double) MesurerRecheche(int[] tableau,double moyenne)
        {
            return (tableau.Length,moyenne);
        }
        public static double LaMoyenneDuTests(int[] tableau, int montant, Func<int[], int, int> echantillion)
        {
            Random nombre = new Random();
            var test = new System.Diagnostics.Stopwatch();
            List<int> leTemps = new List<int>();
            for (int i = 0; i < montant; i++)
            {
                test.Start();
                echantillion.Invoke(tableau,nombre.Next(9999));
                test.Stop();
                leTemps.Add((int)test.ElapsedTicks);
            }
            return leTemps.Average();
        }
        public static int RechercherDichotamique(int[] tableau, int element)
        {
            return Array.BinarySearch(tableau, element);
        }
        public static int RechercheClassique(int[] p_tableau, int p_element)
        {
            int resultat = 0;
            foreach (var x in p_tableau)
            {
                if(p_element == x)
                {
                    resultat = 1;
                }
            }
            return resultat;
        }
        public static int TriABulle(int[] tableau,int dummy)
        {
            int i, j;
            int longeur = tableau.Length;   
            for(i = 0; i < longeur; i++)
            {
                for(j = 0; j < longeur - 1; j++)
                {
                    if (tableau[j] > tableau[j + 1])
                    {
                        (tableau[j], tableau[j + 1]) = (tableau[j + 1], tableau[j]);
                    }
                }
                longeur--;
            }
            return 0;
        }
        private static int Partition(int[] arr, int start, int end)
        {
            int p = arr[end];
            Array.BinarySearch
            //int i = start - 1;
            int i = start;
            for (int j = start + 1; j <= end - 1; j++)
            {
                if (arr[j] <= p)
                {
                    //i++;
                    (arr[i], arr[j]) = (arr[j], arr[j]);
                    i++;
                }
            }
            //(arr[end], arr[i + 1]) = (arr[i + 1], arr[end]);
            (arr[end], arr[i]) = (arr[i], arr[end]);
            return i + 1;
        }
        private static void QuickSortRecurrence(int[] arr, int start, int end)
        {
            int i;
            if (start < end)
            {
                i = Partition(arr, start, end);
                QuickSortRecurrence(arr, start, i - 1);
                QuickSortRecurrence(arr, i + 1, end);
            }
        }
        public static int TriRapide(int[] p_tableau,int muette)
        {
            int but = p_tableau.Length - 1 ;
            QuickSortRecurrence(p_tableau, 0, but);
            return 0;
        }
    }
}