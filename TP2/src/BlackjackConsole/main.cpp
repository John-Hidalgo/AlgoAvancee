#include <iostream>
#include <conio.h>
//BlackjackLib
#include "ListeChainee.h"
#include "Carte.h"
#include "Jeu.h"
#include "BlackJackMains.h"
#include "Partie.h"
#include "MaClasse.h"
//

#include "FenetreConsole.h"
//
#include <Windows.h>

int main()
{
    Partie partie = Partie(100);
    FenetreConsole console(partie);
    console.Show();
    return 0;
}


//int main() {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Set the background color to blue
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
//    // Print some text with the new background color
//    std::cout << "  " ;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN);
//    // Print some text with the new background color
//    std::cout << "  " ;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN);
//    // Print some text with the new background color
//    std::cout << "  ";
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_INTENSITY);
//    // Print some text with the new background color
//    std::cout << "  ";
//
//    // Reset the console color to its default
//    SetConsoleTextAttribute(hConsole, 7);
//
//    return 0;
//}
