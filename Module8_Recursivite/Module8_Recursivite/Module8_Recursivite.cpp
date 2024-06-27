// Module8_Recursivite.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Exercice4.h"

#include <iostream>


void Fibonacci(int n, int values[], int index = 0) 
{
    if (index > n) {
        return;
    }

    if (index == 0) 
    {
        values[index] = 0;
    }
    else if (index == 1) 
    {
        values[index] = 1;
    }
    else 
    {
        values[index] = values[index - 1] + values[index - 2];
    }
    Fibonacci(n, values, index + 1);
}
void PrintFibonacciArray(int fibArray[], int n)
{
    for (int i = 0; i <= n; ++i)
    {
        std::cout << fibArray[i] << " ";
    }
    std::cout << std::endl;
}
void Fibonacci(const int n)
{
    int* values = new int[n + 1];
    Fibonacci(n, values);
    PrintFibonacciArray(values, n);
    delete[] values;
    values = nullptr;
}

void Afficher(int n) 
{
    if (n > 0)
    {
        std::cout << n << std::endl;
        Afficher(n - 1);
    } 
    std::cout << n << std::endl;
}

int Factorial(int n, int product)
{
    if (n == 0)
    {
        return product;
        
    }
    return Factorial(n - 1, n * product);
}
int Factorial(int n)
{
    if (n > 1)
    {
        return Factorial(n, 1);
    }
}

int main() 
{
    std::cout << Factorial(10);
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
