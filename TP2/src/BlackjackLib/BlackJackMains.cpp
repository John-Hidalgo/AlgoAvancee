#include "BlackJackMains.h"

BlackJackMains::BlackJackMains() : m_cartesATirer(7)
{
    ;
}

int BlackJackMains::ComparerMains()
{
    if (m_mainJouer.TrouvePoints() > 21)
    {
        return -1;
    }
    else if (m_mainCroupier.TrouvePoints() == 21 || m_mainJouer.TrouvePoints() < m_mainCroupier.TrouvePoints() && m_mainCroupier.TrouvePoints() < 21)
    {
        return -1;
    }
    else if (m_mainJouer.TrouvePoints() == m_mainCroupier.TrouvePoints())
    {
        return 0;
    }
    else if (m_mainJouer.TrouvePoints() == 21 || m_mainJouer.TrouvePoints() > m_mainCroupier.TrouvePoints())
    {
        return 1;
    }
    else if (m_mainJouer.TrouvePoints() < m_mainCroupier.TrouvePoints() && m_mainCroupier.TrouvePoints() > 21)
    {
        return 1;
    }
}


int BlackJackMains::TrouveATirer() const
{
    return m_cartesATirer;
}

void BlackJackMains::PourTesterLesMains(const int& p_valeur1, const int& p_valeur2)
{
    m_mainCroupier.Tirer(m_cartes.DistribueParValeur(p_valeur1));
    m_mainCroupier.AfficherLesCartes();
    m_mainJouer.Tirer(m_cartes.DistribueParValeur(p_valeur2));
    m_mainJouer.AfficherLesCartes();
}

void BlackJackMains::PourTesterAsTirer()
{
    m_mainCroupier.Tirer(m_cartes.DistribueAS());
    m_mainJouer.Tirer(m_cartes.DistribueAS());
}

void BlackJackMains::Demander()
{
    if (this->m_cartes.TrouveRestant() == 0)
    {
        m_cartes.ConstruireJoue();
    }
    if (this->m_cartesATirer == 0)
    {
        std::cout << "no draws left";
    }
    this->m_mainCroupier.Tirer(m_cartes.Distribue());
    this->m_mainJouer.Tirer(m_cartes.Distribue());
}

void BlackJackMains::SauveGarder(int& montant)
{
    std::ofstream fichier("parties.txt");
    if (!fichier)
    {
        std::cerr << "Impossible D'ouvrir le fichier." << std::endl;
        return;
    }
    SauveGarderATirer("tirer" + std::to_string(montant) + ".txt");
    SauveGarderJoue("joue" + std::to_string(montant) + ".txt");
    SauveGarderMaison("maison" + std::to_string(montant) + ".txt");
    SauveGarderJouer("jouer" + std::to_string(montant) + ".txt");
}
void BlackJackMains::SauveGarderATirer(const std::string& p_nomFichier)
{
    std::ofstream fichier(p_nomFichier);
    if (!fichier)
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier << m_cartesATirer << " ";
    fichier.close();
}
void BlackJackMains::SauveGarderJoue(const std::string& p_nomFichier)
{
    std::ofstream fichier(p_nomFichier);
    if (!fichier)
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier << m_cartes << " ";
    fichier.close();
}
void BlackJackMains::SauveGarderMaison(const std::string& p_nomFichier)
{
    std::ofstream fichier(p_nomFichier);
    if (!fichier)
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier << m_mainCroupier << " ";
    fichier.close();
}
void BlackJackMains::SauveGarderJouer(const std::string& p_nomFichier)
{
    std::ofstream fichier(p_nomFichier);
    if (!fichier)
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier << m_mainJouer << " ";
    fichier.close();
}
void BlackJackMains::Charger(int& montant)
{
    ChargerATirer("tirer" + std::to_string(montant) + ".txt");
    ChargerJoue("joue" + std::to_string(montant) + ".txt");
    ChargerMaison("maison" + std::to_string(montant) + ".txt");
    ChargerJouer("jouer" + std::to_string(montant) + ".txt");
}
void BlackJackMains::ChargerATirer(const std::string& p_nomFichier)
{
    std::ifstream fichier(p_nomFichier);
    if (!fichier) 
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier >> m_cartesATirer;
    fichier.close();
}

void BlackJackMains::ChargerJoue(const std::string& p_nomFichier)
{
    std::ifstream fichier(p_nomFichier);
    if (!fichier) 
    {
        std::cerr << "Impossible D'ouvrir le fichier." << std::endl;
        return;
    }
    fichier >> m_cartes;
    fichier.close();
}
void BlackJackMains::ChargerMaison(const std::string& p_nomFichier)
{
    std::ifstream fichier(p_nomFichier);
    if (!fichier) 
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier >> m_mainCroupier;
    fichier.close();
}
void BlackJackMains::ChargerJouer(const std::string& p_nomFichier)
{
    std::ifstream fichier(p_nomFichier);
    if (!fichier) 
    {
        std::cerr << "Impossible D'ouvrir le fichier" << std::endl;
        return;
    }
    fichier >> m_mainJouer;
    fichier.close();
}