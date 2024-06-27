#include <iostream>
//#include <Windows.h>
#include <direct.h>
#include "demo01/Demo01.h"
#include "MaClasse.h"
#include "Partie.h"
#include "FenetreGUI.h"

//Partie partie = Partie(100);
//FenetreGUI GUI(partie);
//GUI.show();

int main()
{
	Partie partie = Partie(100);
	FenetreGUI GUI(partie);
	GUI.show();
}

