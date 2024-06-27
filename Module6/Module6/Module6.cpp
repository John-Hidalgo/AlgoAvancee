// Module6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ListeEntiers.h"

class x
{
    int a;
    int b;
};
int main()
{
    ListEntiers liste;
    ListEntiers liste1;
    liste.Ajouter(1);
    liste.Ajouter(2);
    liste + 3;
    liste[2] = 4;
    ~liste;
    ListEntiers liste2 = ListEntiers(liste);
    std::cout << liste.Obtenir(0) << std::endl;
    std::cout << liste.Obtenir(1) << std::endl;
    std::cout << liste.Obtenir(2) << std::endl;
    liste += liste2;
    std::cout << liste[2] << std::endl;

    std::cout << liste;
    liste.Inserer(0, 5);
    liste.Inserer(0, 9);
    std::cout << liste;

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
