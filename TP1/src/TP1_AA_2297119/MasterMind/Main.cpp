// MasterMind.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Liste.h"
#include "Match.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include "Liste.h"
using namespace std;

int main()
{
    //Match::MenuPrincipal();
    WORD pink = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;

    Liste<WORD> listeCouleurs;
    listeCouleurs.ajouterFin(pink);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),listeCouleurs.obtenir(0));
    cout << "><";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    Match m;
    //m.ChoisirCouleurs(5);
    //cout << (char)254u;
    //     colors:
    //     0 = Black
    //     1 = Blue
    //     2 = Green
    //     3 = Cyan
    //     4 = Red
    //     5 = Magenta
    //     6 = Yellow
    //     7 = LightGray
    //     8 = DarkGray
    //     9 = LightBlue
    //     10 = LightGreen
    //     11 = LightCyan
    //     12 = LightRe
    //     13 = LightMagenta
    //     14 = LightYellow
    //     15 = White
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

