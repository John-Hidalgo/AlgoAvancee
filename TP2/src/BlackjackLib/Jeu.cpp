#include "Jeu.h"
#include <chrono>

Carte Jeu::Distribue()
{
    std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count() +
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()
        ).count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(0, this->m_restant - 1);
    Carte x = this->m_jeu.SupprimerAEtRenvoie(distrib(gen));
    this->m_restant--;
    return x;
}

void Jeu::ConstruireJoue()
{
    if (this->m_jeu.Taille() > 0)
    {
        this->m_jeu.Vider();
    }

    Carte hearts_ace =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "As", "Coeur", 14, 1, 11);
    m_jeu.AjouterFin(hearts_ace);
    Carte diamonds_ace =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "As", "Carreau", 14, 2, 11);
    m_jeu.AjouterFin(diamonds_ace);
    Carte clubs_ace =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "As", "Trefle", 14, 3, 11);
    m_jeu.AjouterFin(clubs_ace);
    Carte spades_ace =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "As", "Pique", 14, 4, 11);
    m_jeu.AjouterFin(spades_ace);

    Carte hearts_2 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_2", "Deux", "Coeur", 2, 1, 2);
    m_jeu.AjouterFin(hearts_2);
    Carte diamonds_2 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_2", "Deux", "Carreau", 2, 2, 2);
    m_jeu.AjouterFin(diamonds_2);
    Carte clubs_2 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_2", "Deux", "Trefle", 2, 3, 2);
    m_jeu.AjouterFin(diamonds_2);
    Carte spades_2 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_2", "Deux", "Pique", 2, 4, 2);
    m_jeu.AjouterFin(spades_2);


    Carte hearts_3 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_3", "Trois", "Coeur", 3, 1, 3);
    m_jeu.AjouterFin(hearts_3);
    Carte diamonds_3 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_3", "Trois", "Carreau", 3, 2, 3);
    m_jeu.AjouterFin(diamonds_3);
    Carte clubs_3 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_3", "Trois", "Trefle", 3, 3, 3);
    m_jeu.AjouterFin(clubs_3);
    Carte spades_3 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_3", "Trois", "Pique", 3, 4, 3);
    m_jeu.AjouterFin(spades_3);


    Carte hearts_4 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_4", "Quatre", "Coeur", 4, 1, 4);
    m_jeu.AjouterFin(hearts_4);
    Carte spades_4 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_4", "Quatre", "Pique", 4, 4, 4);
    m_jeu.AjouterFin(spades_4);
    Carte clubs_4 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_4", "Quatre", "Trefle", 4, 3, 4);
    m_jeu.AjouterFin(clubs_4);
    Carte diamonds_4 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_4", "Quatre", "Carreau", 4, 2, 4);
    m_jeu.AjouterFin(diamonds_4);


    Carte hearts_5 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_5", "Cinque", "Coeur", 5, 1, 5);
    m_jeu.AjouterFin(hearts_5);
    Carte spades_5 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_5", "Cinque", "Pique", 5, 4, 5);
    m_jeu.AjouterFin(spades_5);
    Carte clubs_5 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_5", "Cinque", "Trefle", 5, 3, 5);
    m_jeu.AjouterFin(clubs_5);
    Carte diamonds_5 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_5", "Cinque", "Carreau", 5, 2, 5);
    m_jeu.AjouterFin(diamonds_5);


    Carte hearts_6 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_6", "Six", "Coeur", 6, 1, 6);
    m_jeu.AjouterFin(hearts_6);
    Carte diamonds_6 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_6", "Six", "Carreau", 6, 2, 6);
    m_jeu.AjouterFin(diamonds_6);
    Carte clubs_6 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_6", "Six", "Trefle", 6, 3, 6);
    m_jeu.AjouterFin(clubs_6);
    Carte spades_6 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_6", "Six", "Pique", 6, 4, 6);
    m_jeu.AjouterFin(spades_6);


    Carte hearts_7 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_7", "Sept", "Coeur", 7, 1, 7);
    m_jeu.AjouterFin(hearts_7);
    Carte diamonds_7 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_7", "Sept", "Carreau", 7, 2, 7);
    m_jeu.AjouterFin(diamonds_7);
    Carte clubs_7 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_7", "Sept", "Trefle", 7, 3, 7);
    m_jeu.AjouterFin(clubs_7);
    Carte spades_7 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_7", "Sept", "Pique", 7, 4, 7);
    m_jeu.AjouterFin(spades_7);


    Carte hearts_8 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_8", "Huit", "Coeur", 8, 1, 8);
    m_jeu.AjouterFin(hearts_8);
    Carte diamonds_8 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_8", "Huit", "Carreau", 8, 2, 8);
    m_jeu.AjouterFin(diamonds_8);
    Carte clubs_8 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_8", "Huit", "Trefle", 8, 3, 8);
    m_jeu.AjouterFin(clubs_8);
    Carte spades_8 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_8", "Huit", "Pique", 8, 4, 8);
    m_jeu.AjouterFin(spades_8);


    Carte hearts_9 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_9", "Neuf", "Coeur", 9, 1, 9);
    m_jeu.AjouterFin(hearts_9);
    Carte diamonds_9 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_9", "Neuf", "Carreau", 9, 2, 9);
    m_jeu.AjouterFin(diamonds_9);
    Carte clubs_9 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_9", "Neuf", "Trefle", 9, 3, 9);
    m_jeu.AjouterFin(clubs_9);
    Carte spades_9 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_9", "Neuf", "Pique", 9, 4, 9);
    m_jeu.AjouterFin(spades_9);


    Carte hearts_10 =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_10", "Dix", "Coeur", 10, 1, 10);
    m_jeu.AjouterFin(hearts_10);
    Carte diamonds_10 =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_10", "Dix", "Carreau", 10, 2, 10);
    m_jeu.AjouterFin(diamonds_10);
    Carte clubs_10 =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_10", "Dix", "Trefle", 10, 3, 10);
    m_jeu.AjouterFin(clubs_10);
    Carte spades_10 =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_10", "Dix", "Pique", 10, 4, 10);
    m_jeu.AjouterFin(spades_10);


    Carte hearts_jack =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_jack", "Valet", "Coeur", 11, 1, 11);
    m_jeu.AjouterFin(hearts_jack);
    Carte spades_jack =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_jack", "Valet", "Pique", 11, 4, 11);
    m_jeu.AjouterFin(spades_jack);
    Carte clubs_jack =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_jack", "Valet", "Trefle", 11, 3, 11);
    m_jeu.AjouterFin(clubs_jack);
    Carte diamonds_jack =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_jack", "Valet", "Carreau", 11, 2, 11);
    m_jeu.AjouterFin(diamonds_jack);


    Carte hearts_king =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_queen", "Dame", "Coeur", 12, 1, 11);
    m_jeu.AjouterFin(hearts_king);
    Carte diamonds_king =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_queen", "Dame", "Carreau", 12, 2, 11);
    m_jeu.AjouterFin(diamonds_king);
    Carte clubs_king =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_queen", "Dame", "Trefle", 12, 3, 11);
    m_jeu.AjouterFin(clubs_king);
    Carte spades_king =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_queen", "Dame", "Pique", 12, 4, 11);
    m_jeu.AjouterFin(spades_king);


    Carte hearts_queen =
        Carte("svg_playing_cards/fronts/png_96_dpi/hearts_king", "Roi", "Coeur", 13, 1, 11);
    m_jeu.AjouterFin(hearts_queen);
    Carte diamonds_queen =
        Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_king", "Roi", "Carreau", 13, 2, 11);
    m_jeu.AjouterFin(diamonds_queen);
    Carte clubs_queen =
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_king", "Roi", "Trefle", 13, 3, 11);
    m_jeu.AjouterFin(clubs_queen);
    Carte spades_queen =
        Carte("svg_playing_cards/fronts/png_96_dpi/spades_king", "Roi", "Pique", 13, 4, 11);
    m_jeu.AjouterFin(spades_queen);

    m_restant = 52;
}

int Jeu::TrouveRestant() const
{
    return this->m_restant;
}

Carte Jeu::DistribueParValeur(const int& p_valeur)
{
    ConstruireJoue();
    return m_jeu.Obtenir(4 * (p_valeur - 1));
}

Carte Jeu::DistribueAS()
{
    ConstruireJoue();
    return m_jeu.Obtenir(0);
}

std::ostream& operator<<(std::ostream& out, const Jeu& joue)
{
    out << joue.m_restant << " "
        << joue.m_jeu;
    return out;
}

std::istream& operator>>(std::istream& in, Jeu& joue)
{
    in >> joue.m_restant
        >> joue.m_jeu;
    return in;
}
