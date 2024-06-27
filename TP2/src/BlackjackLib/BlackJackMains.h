#pragma once
#include "Jeu.h"
#include "Main.h"


class BlackJackMains
{
public:
    friend class Partie;
    friend class FenetreConsole;
    friend class FenetreGUI;
    BlackJackMains();
    int ComparerMains();
    void Demander();
    int TrouveATirer() const;
    void PourTesterLesMains(const int& p_valeur1, const int& p_valeur2);
    void PourTesterAsTirer();
    void SauveGarder(int& montant);
    void SauveGarderATirer(const std::string& p_nomFichier);
    void SauveGarderJoue(const std::string& p_nomFichier);
    void SauveGarderMaison(const std::string& p_nomFichier);
    void SauveGarderJouer(const std::string& p_nomFichier);
    void Charger(int& montant);
    void ChargerATirer(const std::string& p_nomFichier);
    void ChargerJoue(const std::string& p_nomFichier);
    void ChargerMaison(const std::string& p_nomFichier);
    void ChargerJouer(const std::string& p_nomFichier);
public:
    int m_cartesATirer;
    Jeu m_cartes;
    Main m_mainCroupier;
    Main m_mainJouer;
};
