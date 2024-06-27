#pragma once
#include <random>
#include "ListeChainee.h"
#include "Carte.h"
class Jeu
{
public:
	friend class BlackJackMains;
	Carte Distribue();
	void ConstruireJoue();
	int TrouveRestant() const;
	Carte DistribueParValeur(const int& p_valeur);
	Carte DistribueAS();
	friend std::ostream& operator<<(std::ostream& out, const Jeu& jeu);
	friend std::istream& operator>>(std::istream& in, Jeu& jeu);
private:
	int m_restant;
	ListeChainee<Carte> m_jeu;
};


