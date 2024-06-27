#include "FonctionsDaide.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
int LireEntierPositive(std::string message)
{
	std::string entier;
	std::string advertissement = "";
	bool verifier = true;
	do
	{
		bool validerChaine = true;
		std::cout << message << std::endl;
		std::cout << advertissement << std::endl;
		std::cin >> entier;
		for (int i = 0;i < entier.size();i++)
		{
			if (!isdigit(entier[i]))
			{
				validerChaine = false;
				advertissement = "Il vous faut saisir un entier positive";
			}
			else if (stoi(entier) == 0)
			{
				validerChaine = false;
				advertissement = "Il vous faut saisir un entier pair";
			}
		}
		if (!validerChaine) 
		{
			verifier = false;
			system("CLS");
		}
		else 
		{
			verifier = true;
		}
	} while (!verifier);
	return stoi(entier); //j- '0';
}
int LireEntierPositivePair(std::string message)
{
	std::string entier;
	std::string advertissement = "";
	bool verifier = true;
	do
	{
		bool validerChaine = true;
		std::cout << message << std::endl;
		std::cout << advertissement << std::endl;
		std::cin >> entier;
		for (int i = 0;i < entier.size();i++)
		{
			if (!isdigit(entier[i]))
			{
				validerChaine = false;
				advertissement = "Il vous faut saisir un entier pair";
			}
			if (stoi(entier) % 2 > 0)
			{
				validerChaine = false;
				advertissement = "Il vous faut saisir un entier pair";
			}
		}
		if (!validerChaine)
		{
			verifier = false;
			system("CLS");
		}
		else
		{
			verifier = true;
		}
	} while (!verifier);
	return stoi(entier); //j- '0';
}
void AffectePointeXY(int p_x, int p_y)
{
	COORD coord{};
	coord.X = p_x; coord.Y = p_y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return;
}
int Max(int p_tab1[],int p_tab2[])
{
	if (p_tab1[0] > p_tab2[0])
	{
		return p_tab1[1];
	}
	return p_tab2[1];
}

