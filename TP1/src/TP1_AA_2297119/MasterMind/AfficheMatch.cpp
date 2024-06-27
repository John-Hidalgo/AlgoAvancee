#include "AfficheMatch.h"

void AfficheMatch::Couleurs(Liste<int> p_couleurs)
{
	int longuer = p_couleurs.nombreElements();
	if (longuer < 0)
	{
		throw std::invalid_argument("La taille du tableau n'est pas valide");
	}
	for (int i = 0;i < longuer;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p_couleurs.obtenir(i));
		std::cout << (char)254u;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void AfficheMatch::Choix()
{

	cout << "Bienvenue chez Mastermind" << endl;
	cout << endl;
	cout << "1 - Sélectionnez pour jouer contre un autre joueur." << endl;
	cout << "2 - Sélectionnez pour jouer contre le PC." << endl;
	cout << "3 - Quitter." << endl;
}
void AfficheMatch::GuiderCouleurs(const int p_montant)
{
	cout << "Veuillez choisir " << p_montant << " couleurs dans la liste ci-dessous répétitions interdites." << endl;
	cout << "Faites défiler les couleurs disponibles avec les touches" << endl;
	cout << "directionnelles et choisissez avec la touche entrée." << endl;
}
void AfficheMatch::GuiderJouer1(int p_jouer1, int p_jouer2)
{
	cout << "Le joueur 1 entrera son code, appuyez sur Entrée." << endl;
	cout << "Score: Jouer 1 : " << p_jouer1;
	cout << "   Jouer 2 : " << p_jouer2;
}
void AfficheMatch::GuiderJouer2(int p_jouer1, int p_jouer2)
{
	cout << "Le joueur 2 entrera son code, appuyez sur Entrée." << endl;
	cout << "Score: Jouer 1 : " << p_jouer1;
	cout << "   Jouer 2 : " << p_jouer2;
}
void AfficheMatch::AnnoncerGangnant(int p_jouer1[], int p_jouer2[])
{
	cout << "Score: Jouer 1 : " << p_jouer1[0];
	cout << "   Jouer 2 : " << p_jouer2[0] << endl;
	if (p_jouer1[0] == p_jouer2[0])
	{
		cout << "le score est une égalité.";
	}
	else
	{
		cout << "Jouer " << Max(p_jouer1, p_jouer2) << " gagne!" << endl;
	}
}
