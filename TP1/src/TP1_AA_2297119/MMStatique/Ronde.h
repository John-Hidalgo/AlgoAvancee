#pragma once
#include "Liste.h"
#include <string>
class Ronde
{
public:
	Ronde()
	{};
	Ronde(Liste<char> p_proposition, Liste<char> p_codeSecret, Liste<int> p_codeIndex, int p_plions);
	//~Ronde();
	void EvaluerProposition();
	void ConstruireIndex();
	void MisANouveauIndex();
	bool FaireProposition();
	bool JouerRonde(int p_coups);
	void RegistrerHistorique();
	int TrouveBonnePlacee();
	int TrouveMalPlacee();
	void DemandePourSecrete();
	void DemandePourProposition();
	void AfficherCouleurs();
	void FaireCodeParOrdinateur();
	void FairePropositionsParOrdinatuer();
	void AfficherChoix(int p_coups);
	void AfficherHistorique(int p_coups);
	void EffacerHistorique();

private:
	std::string m_couleurs = "VBJRMNOC";
	Liste<char> m_proposition;
	Liste<char> m_codeSecret;
	Liste<char> m_historique;
	Liste<int> m_propIndex;
	Liste<int> m_historiqueBienPlacee;
	Liste<int> m_historiqueMalPlacee;
	int m_plions;
	int bienPlacee = 0;
	int malPlacee = 0;
};