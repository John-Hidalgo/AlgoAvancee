#include "Main.h"


void Main::Trier()
{
    this->m_main.TrierAscendant();
}

void Main::Tirer(Carte p_carte)
{
    this->m_main.AjouterDebut(p_carte);
    this->m_points += p_carte.TrouveValeur();
    if (this->m_points > 21 && p_carte.TrouveNome() == "As")
    {
        this->m_points -= 10;
    }
}

void Main::InitialiserMain()
{
    if (this->m_main.Taille() > 0)
    {
        this->m_main.Vider();
    }
    this->m_points = 0;
}

void Main::ChoisirMinAs()
{
	if (this->m_main.Obtenir(this->m_main.Taille() - 1).TrouveNome() == "As")
	{
		this->m_points -= 10;
	}
}

void Main::AfficherLesCartesPremierTenu()
{
    if (this->m_main.Taille() > 0)
    {
        this->m_main.TrierAscendant();
        std::cout << "carte maison tenu" << std::endl;
        for (int i = 1; i < m_main.Taille();i++)
        {
            std::cout << m_main.Obtenir(i).TrouveNome() << " du " << m_main.Obtenir(i).TrouveEnseigne() << std::endl;
        }
    }
}

void Main::AfficherLesCartes()
{
    this->m_main.TrierAscendant();
    std::cout << " points: " << m_points << std::endl;
    if (this->m_main.Taille() > 0)
    {
        for (Carte x : m_main)
        {
            std::cout << x.TrouveNome() << " du " << x.TrouveEnseigne() << std::endl;
        }
    }
}

ListeChainee<Carte> Main::TrouveListe() const
{
    return this->m_main;
}

std::ostream& operator<<(std::ostream& out, const Main& main)
{
    out << main.m_points << " "
        << main.m_main;
    return out;
}

std::istream& operator>>(std::istream& in, Main& main)
{
    in >> main.m_points
        >> main.m_main;
    //main.m_main.AfficherListe();
    return in;
}
