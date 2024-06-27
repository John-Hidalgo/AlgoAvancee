#pragma once
#include "BlackJackMains.h"

class Partie
{
public:
    friend class BlackJackMains;
    Partie(int p_monaie);
    void DeciderMise(int resultatMains, BlackJackMains& m_tourMains);
    void SauveGarder(int& montant);
    void SauveGarderArgent(const std::string& p_nomFichier);
    void Charger(int& montant);
    void ChargerArgent(const std::string& p_nomFichier);
public:
    int m_monaie;
};