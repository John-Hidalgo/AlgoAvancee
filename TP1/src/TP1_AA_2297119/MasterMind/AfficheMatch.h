#pragma once
#include "FonctionsDaide.h"
#include "IAfficher.h"
#include <windows.h>
using namespace std;
class AfficheMatch : public IAfficher
{
public:
    void IAfficher::Couleurs(Liste<char> p_couleurs) 
    {
		int longuer = p_couleurs.nombreElements();
		if (longuer < 0)
		{
			throw std::invalid_argument("La taille du tableau n'est pas valide");
		}
		for (int i = 0;i < longuer;i++)
		{
			std::cout << p_couleurs.obtenir(i);
		}
    };
    void IAfficher::Couleurs(const Liste<int> p_couleurs);
    void IAfficher::Choix();

    void GuiderCouleurs(const int p_montant);
    void GuiderJouer1(int p_jouer1, int p_jouer2);
    void GuiderJouer2(int p_jouer1, int p_jouer2);
    void AnnoncerGangnant(int p_jouer1[], int p_jouer2[]);

private:

};
