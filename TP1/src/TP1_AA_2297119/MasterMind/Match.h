#pragma once
#include "AfficheMatch.h"
#include "RondeJouer.h"
#include "RondeOrd.h"

class Match
{
public:
	Match(const int p_rondes ,const int p_coups,const int p_pions,const Liste<int> p_couleurs);
	Match(const int p_coups, const int p_pions, const Liste<int> p_couleurs);
	Match();
	~Match()
	{
		if (this->m_rondesJouer)
		{
			delete[] m_rondesJouer;
			this->m_rondesJouer = nullptr;
		}
	};
	Match ConstruireMatch(Match p_muette);
	Match ConstruireMatchOrd(Match p_muette);
	void JouerRondes();
	void JouerContreOrdinateur();
	void CalculerScore(int p_ronde);
	static void MenuPrincipal();
	Liste<int> ChoisirCouleurs(int p_montant);
	int TrouveCoups() const;
private:
	int m_jouer1[2]{ 0,1 };
	int m_jouer2[2]{ 0,2 };
	 
	int m_rondes;
	int m_coups;
	Liste<char> m_couleursText;
	Liste<int> m_couleurs;
	RondeJouer* m_rondesJouer;
	//RondeJouer m_rondes[4];
	RondeOrd m_rondeOrd;
	Liste<int> m_resultats;
	AfficheMatch m_afficher;
};
