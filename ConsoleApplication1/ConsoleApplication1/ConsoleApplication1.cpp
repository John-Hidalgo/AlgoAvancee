// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <random>
#include <chrono>
#include "ListeChainee.h"
#include <exception>
#include <iostream>
#include <string>
#include <conio.h> 


class IInterfaceUtilisateur
{
public:
    virtual ~IInterfaceUtilisateur() = default;
    //int (*RenvoieChoix)() = nullptr;
};

class Main
{
public:
    void Trier() { m_main.TrierAscendant(); };
    int TrouvePoints() const { return this->m_points; };
    void Tirer(Carte p_carte)
    {
        this->m_main.AjouterDebut(p_carte);
        this->m_points += p_carte.m_valeur;
    };
    void InitialiserMain()
    {
        if (this->m_main.Taille() > 0)
        {
            this->m_main.Vider();
        }
        this->m_points = 0;
    }
    void AfficherLesCartes()
    {
        this->m_main.TrierAscendant();
        std::cout << " points: " << m_points << std::endl;
        if (this->m_main.Taille() > 0)
        {
            for (Carte x : m_main)
            {
                std::cout << x.m_nom << " du " << x.m_enseigne << std::endl;
            }
        }

    };
private:
    ListeChainee<Carte> m_main;
    int m_points;
};

class Console : public IInterfaceUtilisateur
{
private:
    int size;
public:
    Console() {};
    Console(int s) : size(s)
    {
        ;
    };
    int RenvoieChoix() 
    {// 
        std::cout << "Promp for hit or stand" << std::endl;
        int x;std::cin >> x;
        system("cls"); 
        return x; 
    };
    void RecevoirLesMains(Main& p_mainMaison, Main& p_mainJouer)
    {
        p_mainMaison.AfficherLesCartes();
        p_mainJouer.AfficherLesCartes();
    };

    //void RenvoieMonaie(Partie partie)
    //{
    //    partie.
    //};
};
class Graphique : public IInterfaceUtilisateur
{
private:
    int size;
public:
    Graphique(){};
    Graphique(int s) : size(s) {};

    int RenvoieChoix() { int x;std::cin >> x;system("cls"); return x; };
    void RecevoirLesMains(Main& p_mainJouer, Main& p_mainMaison)
    {
        p_mainMaison.AfficherLesCartes();
        p_mainJouer.AfficherLesCartes();
    };
};

class Joue
{
public:
    Carte Deal()
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
        //std::cout << "randon number: " << distrib(gen) << std::endl;
        Carte x = this->m_joue.SupprimerAEtRenvoie(distrib(gen));
        this->m_restant--;
        //std::cout << " card dealt : " << x.m_nom << " du " << x.m_enseigne << std::endl;
        //AfficherLesCartes();
        return x;
    };
    void ConstruireJoue()
    {
        if (this->m_joue.Taille() > 0)
        {
            this->m_joue.Vider();
        }
        
        Carte hearts_ace =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "As", "Coeur", 14,1, 11);
        m_joue.AjouterFin(hearts_ace);
        Carte diamonds_ace =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "As", "Carreau", 14, 2, 11);
        m_joue.AjouterFin(diamonds_ace);
        Carte clubs_ace =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "As", "Trefle", 14, 3, 11);
        m_joue.AjouterFin(clubs_ace);
        Carte spades_ace =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "As", "Pique", 14, 4, 11);
        m_joue.AjouterFin(spades_ace);

        Carte hearts_2 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Deux", "Coeur", 2, 1, 2);
        m_joue.AjouterFin(hearts_2);
        Carte diamonds_2 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Deux", "Carreau", 2, 2, 2);
        m_joue.AjouterFin(diamonds_2);
        Carte clubs_2 = 
        Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Deux", "Trefle", 2, 3, 2);
        m_joue.AjouterFin(diamonds_2);
        Carte spades_2 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Deux", "Pique", 2, 4, 2);
        m_joue.AjouterFin(spades_2);


        Carte hearts_3 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Trois", "Coeur", 3, 1, 3);
        m_joue.AjouterFin(hearts_3);
        Carte diamonds_3 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Trois", "Carreau", 3, 2, 3);
        m_joue.AjouterFin(diamonds_3);
        Carte clubs_3 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Trois", "Trefle", 3, 3, 3);
        m_joue.AjouterFin(clubs_3);
        Carte spades_3 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Trois", "Pique", 3, 4, 3);
        m_joue.AjouterFin(spades_3);


        Carte hearts_4 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Quatre", "Coeur", 4, 1, 4);
        m_joue.AjouterFin(hearts_4);
        Carte spades_4 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Quatre", "Pique", 4, 4, 4);
        m_joue.AjouterFin(spades_4);
        Carte clubs_4 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Quatre", "Trefle", 4, 3, 4);
        m_joue.AjouterFin(clubs_4);
        Carte diamonds_4 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Quatre", "Carreau", 4, 2 , 4);
        m_joue.AjouterFin(diamonds_4);

        
        Carte hearts_5 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Cinque", "Coeur", 5, 1, 5);
        m_joue.AjouterFin(hearts_5);
        Carte spades_5 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Cinque", "Pique", 5, 4, 5);
        m_joue.AjouterFin(spades_5);
        Carte clubs_5 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Cinque", "Trefle", 5, 3, 5);
        m_joue.AjouterFin(clubs_5);
        Carte diamonds_5 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Cinque", "Carreau", 5, 2, 5);
        m_joue.AjouterFin(diamonds_5);


        Carte hearts_6 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Six", "Coeur", 6, 1, 6);
        m_joue.AjouterFin(hearts_6);
        Carte diamonds_6 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Six", "Carreau", 6, 2, 6);
        m_joue.AjouterFin(diamonds_6);
        Carte clubs_6 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Six", "Trefle", 6, 3, 6);
        m_joue.AjouterFin(clubs_6);
        Carte spades_6 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Six", "Pique", 6, 4, 6);
        m_joue.AjouterFin(spades_6);


        Carte hearts_7 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Sept", "Coeur", 7, 1, 7);
        m_joue.AjouterFin(hearts_7);
        Carte diamonds_7 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Sept", "Carreau", 7, 2, 7);
        m_joue.AjouterFin(diamonds_7);
        Carte clubs_7 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Sept", "Trefle", 7, 3, 7);
        m_joue.AjouterFin(clubs_7);
        Carte spades_7 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Sept", "Pique", 7, 4, 7);
        m_joue.AjouterFin(spades_7);


        Carte hearts_8 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Huit", "Coeur", 8, 1, 8);
        m_joue.AjouterFin(hearts_8);
        Carte diamonds_8 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Huit", "Carreau", 8, 2, 8);
        m_joue.AjouterFin(diamonds_8);
        Carte clubs_8 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Huit", "Trefle", 8, 3, 8);
        m_joue.AjouterFin(clubs_8);
        Carte spades_8 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Huit", "Pique", 8, 4, 8);
        m_joue.AjouterFin(spades_8);


        Carte hearts_9 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Neuf", "Coeur", 9, 1, 9);
        m_joue.AjouterFin(hearts_9);
        Carte diamonds_9 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Neuf", "Carreau", 9, 2, 9);
        m_joue.AjouterFin(diamonds_9);
        Carte clubs_9 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Neuf", "Trefle", 9, 3, 9);
        m_joue.AjouterFin(clubs_9);
        Carte spades_9 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Neuf", "Pique", 9, 4, 9);
        m_joue.AjouterFin(spades_9);


        Carte hearts_10 =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Dix", "Coeur", 10, 1, 10);
        m_joue.AjouterFin(hearts_10);
        Carte diamonds_10 =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Dix", "Carreau", 10, 2, 10);
        m_joue.AjouterFin(diamonds_10);
        Carte clubs_10 =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Dix", "Trefle", 10, 3, 10);
        m_joue.AjouterFin(clubs_10);
        Carte spades_10 =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Dix", "Pique", 10, 4, 10);
        m_joue.AjouterFin(spades_10);        

        
        Carte hearts_jack =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Valet", "Coeur", 11, 1, 11);
        m_joue.AjouterFin(hearts_jack);
        Carte spades_jack =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Valet", "Pique", 11, 4, 11);
        m_joue.AjouterFin(spades_jack);
        Carte clubs_jack =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Valet", "Trefle", 11, 3, 11);
        m_joue.AjouterFin(clubs_jack);
        Carte diamonds_jack =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Valet", "Carreau", 11, 2, 11);
        m_joue.AjouterFin(diamonds_jack);

        
        Carte hearts_king =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Dame", "Coeur", 12, 1, 11);
        m_joue.AjouterFin(hearts_king);
        Carte diamonds_king =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Dame", "Carreau", 12, 2, 11);
        m_joue.AjouterFin(diamonds_king);
        Carte clubs_king =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Dame", "Trefle", 12, 3, 11);
        m_joue.AjouterFin(clubs_king);
        Carte spades_king =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Dame", "Pique", 12, 4, 11);
        m_joue.AjouterFin(spades_king);


        Carte hearts_queen =
            Carte("svg_playing_cards/fronts/png_96_dpi/hearts_ace", "Roi", "Coeur", 13, 1, 11);
        m_joue.AjouterFin(hearts_queen);
        Carte diamonds_queen =
            Carte("svg_playing_cards/fronts/png_96_dpi/diamonds_ace", "Roi", "Carreau", 13, 2, 11);
        m_joue.AjouterFin(diamonds_queen);
        Carte clubs_queen =
            Carte("svg_playing_cards/fronts/png_96_dpi/clubs_ace", "Roi", "Trefle", 13, 3, 11);
        m_joue.AjouterFin(clubs_queen);
        Carte spades_queen =
            Carte("svg_playing_cards/fronts/png_96_dpi/spades_ace", "Roi", "Pique", 13, 4, 11);
        m_joue.AjouterFin(spades_queen);

        m_restant = 52;
    };


    void AfficherLesCartes()
    {
        std::cout << m_joue.Taille() << std::endl;
        if (m_joue.Taille() > 0)
        {
            for (Carte x : m_joue)
            {
                std::cout << x.m_nom << " du " << x.m_enseigne << std::endl;
            }
        }

    };

public:
    ListeChainee<Carte> m_joue;
    int m_restant;
};


class IMain 
{
    // need to find a way to implement strategy better have one function
    // maybe its impossible as a function pointer because I've gotta cast it 
    // cannot type check as in C# I might just not use a function pointer 
    // also I can't simply leave it as type IInterface and override because it's abstract
    virtual int DemanderJouer(int (Console::* RenvoieChoix)()) { return 0; };
    virtual int DemanderJouer(int (Graphique::* RenvoieChoix)()) { return 0; };
    virtual int JouerMain(int) = 0;
};

class BlackJackMain : public IMain
{
public:
    BlackJackMain(IInterfaceUtilisateur* p_ui)
        :m_cartesATirer(5), m_ui(p_ui)
    {
        m_cartes.ConstruireJoue();
    }
    int ComparerMains()
    {
        if (m_mainJouer.TrouvePoints() > 21)
        {
            return -1;
        }
        else if (m_mainCroupier.TrouvePoints() == 21 || m_mainJouer.TrouvePoints() < m_mainCroupier.TrouvePoints()  )
        {
            return - 1;
        }
        else if (m_mainJouer.TrouvePoints() == m_mainCroupier.TrouvePoints())
        {
            return 0;
        }
        else if(m_mainJouer.TrouvePoints() == 21 || m_mainJouer.TrouvePoints() > m_mainCroupier.TrouvePoints())
        {
            return 1;
        }
        else if (m_mainJouer.TrouvePoints() < m_mainCroupier.TrouvePoints() && m_mainCroupier.TrouvePoints() > 21)
        {
            return 1;
        }
        std::system("cls");
    };

    int DemanderJouer(int (Console::*RenvoieChoix)()) override
    {
        if (this->m_cartes.m_restant == 0)
        {
            m_cartes.ConstruireJoue();
        }
        Console* console = dynamic_cast<Console*>(this->m_ui);
        int resultatInterface = 0;
        if (RenvoieChoix)
        {
            if (console) {
                resultatInterface = (console->*RenvoieChoix)();
            }
        }
        return resultatInterface;
    };

    int JouerMain(int cartesATirer) override
    {
        if (cartesATirer == 0)
        {
            return ComparerMains();
        }
        if (this->m_mainJouer.TrouvePoints() > 21)
        {
            return - 1;
        }
        int decisionJouer = DemanderJouer(&Console::RenvoieChoix);
        Console* console = dynamic_cast<Console*>(this->m_ui);        
        if (decisionJouer == 1)
        {
            this->m_mainCroupier.Tirer(m_cartes.Deal());
            this->m_mainJouer.Tirer(m_cartes.Deal());
            int resultat = ComparerMains();
            if (console)
            {
                console->RecevoirLesMains(this->m_mainCroupier, this->m_mainJouer);
            }
            JouerMain(cartesATirer - 1);
        }
        else if (decisionJouer == 2)
        {
            this->m_cartesATirer = 0;
            if (console)
            {
                console->RecevoirLesMains(this->m_mainCroupier, this->m_mainJouer);
            }
        }

        return ComparerMains();
    }

    int JouerMain() 
    {
        std::cout << this->m_cartes.m_joue.Taille() << " cards remaining in the deck." << std::endl;
        //this->m_mainCroupier.AfficherLesCartes();
        //this->m_mainJouer.AfficherLesCartes();
        this->m_mainJouer.InitialiserMain();
        this->m_mainCroupier.InitialiserMain();
        this->m_cartesATirer = 5;
        return JouerMain(this->m_cartesATirer);
    }
    IInterfaceUtilisateur* m_ui;
    Joue m_cartes;
    Main m_mainCroupier;
    Main m_mainJouer;
    int m_cartesATirer;
};

class Partie
{
public:
    Partie(int p_monaie,BlackJackMain& p_tourMains, IInterfaceUtilisateur* p_ui)
        :m_monaie(p_monaie), m_tourMains(p_tourMains), m_ui(p_ui)
    {
        m_tourMains.m_cartes = p_tourMains.m_cartes;
        m_tourMains.m_mainCroupier = p_tourMains.m_mainCroupier;
        m_tourMains.m_mainJouer = p_tourMains.m_mainJouer;
    };
    void JouerPartie(int p_monaie)
    {
       
        std::cout << "You've got " << p_monaie << " remaining" << std::endl;
        int resultatMain = m_tourMains.JouerMain();
        //RenvoieResultat();
        std::cout << "result: " << resultatMain << std::endl;
        if (p_monaie == 0)
        {
            //RenvoieResultatsInterface();
            //RecevoirDeInterface();
            return;
        }
        if (resultatMain == -1)
        {
            std::cout << "Hand lost" << std::endl;
            JouerPartie(p_monaie - 10);
        }
        else if (resultatMain == 0)
        {
            std::cout << "Hand tied" << std::endl;
            JouerPartie(p_monaie);
        }
        else
        {
            std::cout << "Hand won" << std::endl;
            JouerPartie(p_monaie + 10);
        }
    };

public:
    int m_monaie;
    BlackJackMain m_tourMains;
    IInterfaceUtilisateur* m_ui;
};



//int main()
//{
//    Joue joue;
//    joue.ConstruireJoue();
//    joue.AfficherLesCartes();
//    Main main;
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.AfficherLesCartes();
//    std::cout << std::endl;
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.AfficherLesCartes();
//    std::cout << std::endl;
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.AfficherLesCartes();
//    std::cout << std::endl;
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.Tirer(joue.Deal());
//    main.AfficherLesCartes();
//    std::cout << std::endl;
//    joue.ConstruireJoue();
//    joue.AfficherLesCartes();
//    main.Tirer(joue.Deal());
//    
//    ListeChainee<Carte> l1;
//    ListeChainee<Carte> l2;
//
//    bool x = l1 != l2;
//
//    l1 = std::move(l2);
//
//    std::cout << x; 
//
//}




void displayMenu() {
    system("cls");
    std::cout << "=========================" << std::endl;
    std::cout << "      Blackjack Menu     " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Jouer Blackjack" << std::endl;
    std::cout << "2. Charger une partie" << std::endl;
    std::cout << "3. Quitter" << std::endl;
    std::cout << "=========================" << std::endl;
}

int main() {
    int choice;
    int monaie = 100;
    Console console = (10);
    BlackJackMain tourMains(&console);
    Partie partie(monaie,tourMains);
    do {
        displayMenu();

        char key = _getch();

        switch (key) {
        case '1':
            choice = 1;
            break;
        case '2':
            choice = 2;
            break;
        case '3':
            choice = 3;
            break;
        default:
            choice = -1; // Invalid choice
        }

        switch (choice) {
        case 1:
            std::cout << "\nDemmarage..." << std::endl;
            tourMains.m_cartes.ConstruireJoue();
            tourMains.m_cartes.AfficherLesCartes();
            _getch();
            system("cls");
            partie.JouerPartie(100);
            break;
        case 2:
            std::cout << "\nCharger..." << std::endl;
            // To complete if I've got time
            break;
        case 3:
            std::cout << "\nMerci d'avoir joué au blackjack." << std::endl;
            break;
        default:
            std::cout << "\nChoice Invalide." << std::endl;
            break;
        }

        if (choice != 3) {
            std::cout << "Press any key to continue...";
            _getch();

        }

    } while (choice != 3);

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
