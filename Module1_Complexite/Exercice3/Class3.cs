using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercice3
{//
    // [0,1,2,3,4,5]       int index = 0 ; i < 6
    // [1,2,3] [3,4,5]
    public class Class3
    {
        public static (int[],int[]) Split(int[] array)
        {
            int length = array.Length;
            if(length % 2 == 0)
            {
                int[] leftArray = new int[length /2];
                int[] rightArray = new int[length /2];
                for (int index = 0; index < length / 2; index++)
                {
                    leftArray[index] = array[index];
                    rightArray[index] = array[index * 2];
                }
                return (leftArray, rightArray);
            }
            else
            {
                int[] leftArray = new int[length / 2];
                int[] rightArray = new int[length / 2 + 1];
                for (int index = 0; index < length / 2; index++)
                {
                    leftArray[index] = array[index];
                    rightArray[index] = array[index * 2];
                    rightArray[rightArray.Length - 1] = array[length - 1];
                }
                return (leftArray, rightArray);
            }
        }
    }
}
