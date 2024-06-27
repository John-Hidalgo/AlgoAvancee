using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Exercice3
{
    class RandomizedQsort
    {
        public static void QuickSort(int[] arr)
        {
            Random rand = new Random();
            int pivotIndexChoice = rand.Next(arr.Length);
            Partition(arr, 0, pivotIndexChoice);
        }
        // this function calls partition with a pivot and position it calls itself 
        // until all the the partitions are all of the same value
        protected static void Partition(int[] arr, int low, int pivotIndexChoice)
        {
            if (low <= pivotIndexChoice)
            {
                int pivotIndex = SortByPivot(arr, low, pivotIndexChoice);
                Partition(arr, low, pivotIndex - 1);
                Partition(arr, pivotIndex + 1, pivotIndexChoice);
            }
        }
        // this function places the pivot at certain index and returns that integer
        // the placement is made in such a way that all values to the left are less than the pivot
        // and all to the right are greater than or equal
        protected static int SortByPivot(int[] arr, int low, int pivotIndex)
        {
            int pivot = arr[pivotIndex];
            int i = (low - 1); 
            for (int j = low; j < pivotIndex; j++)
            {
                if (arr[j] < pivot)
                {
                    i++;
                    (arr[j], arr[i]) = (arr[i], arr[j]);
                }
            }
            (arr[pivotIndex], arr[i + 1]) = (arr[i + 1], arr[pivotIndex]);
            return i + 1;
        }
        protected static void SortByPivot1(int[] arr,int low , int pivotIndex)
        {
            int pivot = arr[pivotIndex];
            int i = (low - 1);
            for (int j = low; j < pivotIndex; j++)
            {
                if (arr[j] < pivot)
                {
                    i++;
                    (arr[j], arr[i]) = (arr[i], arr[j]);
                }
            }
        }
        public static void printArray(int[] arr)
        {
            int n = arr.Length;
            for (int i = 0; i < n; ++i)
                Console.Write(arr[i] + " ");
            Console.WriteLine();
        }
    }
}
