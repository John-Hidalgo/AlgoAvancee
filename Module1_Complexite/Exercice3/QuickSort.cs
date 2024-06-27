using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercice3
{
    public class QuickSort
    {
        private static void Swap(int[] array,int i,int j)
       {
            (array[i], array[j]) = (array[j], array[i]);
        }
        //private static int SwapByPivotLast(int[] array, int first, int initialPivotIndex)
        //{
        //    int pivot = array[initialPivotIndex]; 
        //    int lsPivot = first - 1;
        //    int gtPivot;
        //    for(gtPivot = first; gtPivot < initialPivotIndex; gtPivot++)
        //    {
        //        if (array[gtPivot] < pivot)
        //        {
        //            lsPivot++;
        //            Swap(array, gtPivot, lsPivot);
        //        }
        //    }
        //    Swap(array, lsPivot + 1, initialPivotIndex);
        //    return lsPivot + 1;
        //}
        //private static void PartitionLast(int[] array, int first, int initialPivotIndex)
        //{
        //    if(first < initialPivotIndex)
        //    {
        //        int pivotIndex = SwapByPivotLast(array, first, initialPivotIndex);
        //        PartitionLast(array, first, pivotIndex - 1);
        //        PartitionLast(array, pivotIndex + 1, initialPivotIndex);
        //    }
        //}
        //public static void PivotLast(int[] array)
        //{
        //    PartitionLast(array, 0, array.Length - 1);
        //}
        public static int partition(int[] a, int left, int right)
        {
            int pivot = a[left];
            while (left <= right)
            {
                while (a[left] < pivot)
                    left++;
                while (a[right] > pivot)
                    right--;
                if (left <= right)
                {
                    Swap(a, left, right);
                    left++;
                    right--;
                }
            }
            //PrintValues(a, pivot);
            return left;
        }
        public static void recursiveQuickSort(int[] a, int i, int j)
        {
            int idx = partition(a, i, j);
            if (i < idx - 1)
            {
                recursiveQuickSort(a, i, idx - 1);
            }
            if (j > idx)
            {
                recursiveQuickSort(a, idx, j);
            }
        }
        public static void PivotFirst(int[] array)
        {
            recursiveQuickSort(array, 0, array.Length - 1);
        }
        public static void PrintValues(int[] array, int pivot)
        {
            Console.Write("{");
            for (int i = 0; i < array.Length -1;i++)
            {
                Console.Write(array[i] + ", ");
            }
            Console.Write(array[array.Length - 1] + "}");
            Console.Write(pivot);
            Console.WriteLine();
        }
        public static void QuickSort1(int[] array,int left,int right)
        {
            if (left < right)
            {
                int pivot = array[left];
                int first = left, last = right;
                while (first < right)
                {
                    while(first < last && array[last] > pivot)
                    {
                        --last;
                    }
                    array[first] = array[last];
                    while (first < last && array[first] <= pivot)
                    {
                        ++first;  
                    }
                    array[last] = array[first];
                }
                array[first] = pivot;
                QuickSort1(array, left, first);
                QuickSort1(array, first + 1, right);
            }
        }
    }
}
