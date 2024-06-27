#pragma once
#include "ListeChainee.h"
#include "Carte.h"

class Main
{
public:
    friend class BlackJackMains;
    friend class FenetreJouer;
    friend class FenetreGUI;
    void Trier();
    void Tirer(Carte p_carte);
    void InitialiserMain();
    void ChoisirMinAs();
    void AfficherLesCartesPremierTenu();
    void AfficherLesCartes();
    int TrouvePoints() const { return this->m_points; };
    ListeChainee<Carte> TrouveListe()const;
    friend std::ostream& operator<<(std::ostream& out, const Main& main);
    friend std::istream& operator>>(std::istream& in, Main& main);
private:
    int m_points;
    ListeChainee<Carte> m_main;
};

