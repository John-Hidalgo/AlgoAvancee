#include "Carte.h"

Carte::Carte() : m_chemin(""), m_nom(""), m_enseigne(""), m_valeur(0) { ; }

Carte::Carte(const std::string p_chemin, const std::string p_nom, const std::string p_enseigne, const int p_valeurPourTrie, const int p_enseignePourTrie, const int p_valeur): Carte()
{
    this->m_chemin = p_chemin;
    this->m_nom = p_nom;
    this->m_enseigne = p_enseigne;
    this->m_valeurPourTrie = p_valeurPourTrie;
    this->m_enseignePourTrie = p_enseignePourTrie;
    this->m_valeur = p_valeur;
}

int Carte::TrouveValeur() const
{
    return this->m_valeur;
}

std::string Carte::TrouveChemin() const
{
    return this->m_chemin;
}

std::string Carte::TrouveEnseigne() const
{
    return this->m_enseigne;
}

std::string Carte::TrouveNome() const
{
    return this->m_nom;
}

bool Carte::operator==(const Carte& p_carte)
{
    if (this->m_nom == p_carte.m_nom && this->m_enseigne == p_carte.m_enseigne)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Carte::operator<(Carte p_carte)
{
    bool resultat = true;
    //std::cout << this->m_valeur << " < " << p_carte.m_valeur << std::endl;
    if (this->m_valeurPourTrie > p_carte.m_valeurPourTrie)
    {
        return false;
    }
    else if (this->m_valeurPourTrie == p_carte.m_valeurPourTrie)
    {
        if (this->m_enseignePourTrie > p_carte.m_enseignePourTrie)
        {
            return false;
        }
    }
    return resultat;
}

std::ostream& operator<<(std::ostream& out, const Carte& carte)
{
    out << carte.m_chemin << " "
        << carte.m_nom << " "
        << carte.m_enseigne << " "
        << carte.m_valeurPourTrie << " "
        << carte.m_enseignePourTrie << " "
        << carte.m_valeur;// << " ";
    //<< carte.m_restant;
    return out;
}

std::istream& operator>>(std::istream& in, Carte& carte)
{
    in >> carte.m_chemin
        >> carte.m_nom
        >> carte.m_enseigne
        >> carte.m_valeurPourTrie
        >> carte.m_enseignePourTrie
        >> carte.m_valeur;
    return in;
}
