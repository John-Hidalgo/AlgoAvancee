#include "Partie.h"

Partie::Partie(int p_monaie)
    :m_monaie(p_monaie)
{
    ;
}

void Partie::DeciderMise(int resultatMains, BlackJackMains& m_tourMains)
{
    if (resultatMains == -1)
    {
        this->m_monaie -= 10;
    }
    else if (resultatMains == 0)
    {

    }
    else if (resultatMains == 1 && m_tourMains.m_mainJouer.TrouvePoints() == 21)
    {
        this->m_monaie += 40;
    }
    else if (resultatMains == 1 && m_tourMains.m_mainJouer.TrouvePoints() < 21)
    {
        this->m_monaie += 20;
    }
}

void Partie::SauveGarder(int& montant)
{
    SauveGarderArgent("argent" + std::to_string(montant) + ".txt");
}

void Partie::SauveGarderArgent(const std::string& p_nomFichier)
{
    std::ofstream fichier(p_nomFichier);
    if (!fichier)
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier << m_monaie << " ";
    fichier.close();
}

void Partie::Charger(int& montant)
{
    ChargerArgent("argent" + std::to_string(montant) + ".txt");
}

void Partie::ChargerArgent(const std::string& p_nomFichier)
{
    std::ifstream fichier(p_nomFichier);
    if (!fichier) {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier >> m_monaie;
    fichier.close();
}
