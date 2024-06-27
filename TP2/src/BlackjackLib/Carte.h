#pragma once
#include <string> 
#include <iostream>
#include <string>
#include <fstream>
class Carte
{
public:
	Carte();
    Carte(const std::string p_chemin, const std::string p_nom, const std::string p_enseigne, const int p_valeurPourTrie, const int p_enseignePourTrie, const int p_valeur);
    int TrouveValeur() const;
    std::string TrouveChemin() const;
    std::string TrouveEnseigne() const;
    std::string TrouveNome() const;
    bool operator==(const Carte& p_carte);
    bool operator<(Carte p_carte);
    friend std::ostream& operator<<(std::ostream& out, const Carte& carte);
    friend std::istream& operator>>(std::istream& in, Carte& carte);
private:
    std::string m_chemin;
    std::string m_nom;
    std::string m_enseigne;
    int m_valeurPourTrie;
    int m_enseignePourTrie;
    int m_valeur;
};

