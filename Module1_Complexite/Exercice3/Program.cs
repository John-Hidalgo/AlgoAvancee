namespace Exercice3
{
    internal class Program
    {
        private static List<int[]> lesTableaus = new List<int[]> {
            //GenererTableau((int)Math.Pow(2,1)),
            GenererTableau((int)Math.Pow(2, 10)),
            GenererTableau((int)Math.Pow(2,11)),
            GenererTableau((int)Math.Pow(2,12)),
            GenererTableau((int)Math.Pow(2,13)),
            GenererTableau((int)Math.Pow(2,14)),
            GenererTableau((int)Math.Pow(2,15)),
            GenererTableau((int)Math.Pow(2,16)),
            GenererTableau((int)Math.Pow(2,17)),
            GenererTableau((int)Math.Pow(2,18)),
            GenererTableau((int)Math.Pow(2,19)),
            GenererTableau((int)Math.Pow(2,20)),
            GenererTableau((int)Math.Pow(2,21)),
            GenererTableau((int)Math.Pow(2,22)),
            //GenererTableau((int)Math.Pow(2,23)),
            //GenererTableau((int)Math.Pow(2,24)),
            //GenererTableau((int)Math.Pow(2,26)),
            //GenererTableau((int)Math.Pow(2,27)),
            //GenererTableau((int)Math.Pow(2,28)),
            //GenererTableau((int)Math.Pow(2,29)),
            //GenererTableau((int)Math.Pow(2,30)),
            //GenererTableau((int)Math.Pow(2,31)),
            //GenererTableau((int)Math.Pow(2,32)),
            //GenererTableau((int)Math.Pow(2,33)),
            //GenererTableau((int)Math.Pow(2,34)),
            //GenererTableau((int)Math.Pow(2,35))
            };
        private static List<int[]> lesTableaus2 = new List<int[]> {
            //GenererTableau((int)Math.Pow(2,1)),
            GenererTableau((int)Math.Pow(2, 10)),
            GenererTableau((int)Math.Pow(2,11)),
            GenererTableau((int)Math.Pow(2,12)),
            GenererTableau((int)Math.Pow(2,13)),
            GenererTableau((int)Math.Pow(2,14)),
            GenererTableau((int)Math.Pow(2,15)),
            GenererTableau((int)Math.Pow(2,16)),
            GenererTableau((int)Math.Pow(2,17)),
            GenererTableau((int)Math.Pow(2,18)),
            GenererTableau((int)Math.Pow(2,19)),
            GenererTableau((int)Math.Pow(2,20)),
            GenererTableau((int)Math.Pow(2,21)),
            GenererTableau((int)Math.Pow(2,22)),
            GenererTableau((int)Math.Pow(2,23)),
            GenererTableau((int)Math.Pow(2,24)),
            GenererTableau((int)Math.Pow(2,25)),
            GenererTableau((int)Math.Pow(2,26)),
            GenererTableau((int)Math.Pow(2,27)),
            //GenererTableau((int)Math.Pow(2,28)),
            //GenererTableau((int)Math.Pow(2,29)),
            //GenererTableau((int)Math.Pow(2,30)),
            //GenererTableau((int)Math.Pow(2,31)),
            //GenererTableau((int)Math.Pow(2,32)),
            //GenererTableau((int)Math.Pow(2,33)),
            //GenererTableau((int)Math.Pow(2,34)),
            //GenererTableau((int)Math.Pow(2,35))
            };
        static void Main(string[] args)
        {
            int[] ar = new int[10]{ 11, 5, 4, 1, 98, 8, 2, 90, 20, 16 };
            int[] arr = { 10, 7, 9, 8, 1, 5 };
            //QuickSort.PivotFirst(arr);
            QuickSort1(ar);
            Array.Sort(arr);
            QuickSort.PrintValues(ar, 0);
            //foreach(var x in arr)
            //{
            //    Console.WriteLine(x);
            //}
            //RandomizedQsort.QuickSort(arr);
            //RandomizedQsort.printArray(arr);
            //foreach (var tab in lesTableaus2)
            //{
            //    Array.Sort(tab);
            //    RandomizedQsort.QuickSort(tab);
            //    Console.WriteLine("{0}", Tester(tab, 1, QuickSort.PivotFirst).ToString());
            //    / RandomizedQsort.QuickSort(tab);
            //    Console.WriteLine("resorting");
            //}
            //foreach (var tab in lesTableaus)
            //{
            //    //Array.Sort(tab);
            //    Console.WriteLine("sorted by C# at : {0} ms", Tester(tab, 1, QuickSort.PivotLast).ToString());
            //}
            //int[] arr = null;
            //Array.Sort(arr);
            //RandomizedQsort.Partition(arr,0,1);

        }
        public static void swap(int[] arr, int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        public static int partition(int[] arr, int low, int high)
        {
            
            int pivot = arr[high];
            int i = (low - 1);
            QuickSort.PrintValues(arr, pivot);
            Console.WriteLine("Index of the pivot is currently: {0}", high);
            Console.WriteLine("Let's sort it according to {0}", pivot);

            for (int j = low; j < high; j++)
            {

                // If current element is smaller than the pivot
                if (arr[j] < pivot)
                {

                    // Increment index of smaller element
                    i++;
                    swap(arr, i, j);
                }
            }
            //QuickSort.PrintValues(arr, pivot);
            //Console.WriteLine("Now the index of the pivot will be {0} So we put the pivot in the right place",i+1);
            swap(arr, i + 1, high);
            QuickSort.PrintValues(arr, pivot);
            Console.WriteLine("Now all the elements to the left of {0} ar strictly less than it", pivot);
            return (i + 1);
        }
        public static void quickSort(int[] arr, int low, int high)
        {
            Console.WriteLine("{0} : {1}", low, high);
            if (low < high)
            {

                // pi is partitioning index, arr[p]
                // is now at right place
                int pi = partition(arr, low, high);

                // Separately sort elements before
                // and after partition index

                    quickSort(arr, low, pi - 1);
                    //Console.WriteLine("lower half of first pivot sorted");
                

                    quickSort(arr, pi + 1, high);
                    //Console.WriteLine("Calling quickSort on upper half");
                
                //QuickSort.PrintValues(arr, pi);
                
                
            }
        }
        public static void Quicksort(int[] arr)
        {
            int longeur = arr.Length;
            quickSort(arr, 0, longeur - 1);
        }
        public static int SortByPivot(int[] array, int left, int right)
        {
            int pivot = array[left];
            int j = right + 1;
            for (int i = right;i >= left; i--)
            {
                if(array[i] > pivot)
                {
                    j--;
                    swap(array, i, j);  
                }
            }
            swap(array, left, j - 1);
            return j - 1;
        }
        public static void Partition(int[] array, int left, int right)
        {
            if (left < right)
            {
                int pindex = SortByPivot(array, left, right);
                Partition(array, left, pindex - 1);
                Partition(array, pindex + 1, right);
            }
        }
        public static void QuickSort1(int[] array)
        {
            Partition(array, 0, array.Length - 1);
            
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
        public static double Tester(int[] tableau, int montant, Action<int[]> fonction)
        {
            var test = new System.Diagnostics.Stopwatch();
            List<int> leTemps = new List<int>();
            for (int i = 0; i < montant; i++)
            {
                test.Start();
                fonction.Invoke(tableau);
                test.Stop();
                leTemps.Add((int)test.ElapsedTicks);
            }
            return leTemps.Average();
        }
    }

}