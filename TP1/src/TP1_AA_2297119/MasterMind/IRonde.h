#pragma once
#include "AfficheRonde.h"
#include "FonctionsDaide.h"
#include <iostream>
#include <string>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
class IRonde
{
public :
	virtual int JouerRonde(int coups) = 0;

    void BoucleRonde(int& p_coups, int& p_tentatives);
    void DemandePourSecrete();
    void DemandePourProposition();
    bool FaireProposition();
    void EvaluerProposition();
    void EffacerHistorique();
    void RegistrerHistorique();
    int TrouvePions() const;
    int TrouveBonnePlacee() const;
    int TrouveMalPlacee() const;
    void AffecteCouleurs(Liste<int> p_liste);
    void AffectePions(const int& p_plions);

protected:
	AfficheRonde m_afficher;
	Liste<int> m_couleurs;
	Liste<int> m_proposition;
	Liste<int> m_codeSecret;
	Liste<int> m_historique;
	Liste<int> m_historiqueBienPlacee;
	Liste<int> m_historiqueMalPlacee;
	int m_pions;
	int bienPlacee;
	int malPlacee;
};

