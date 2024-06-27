#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "BlackJackMains.h"
#include "Partie.h"

class FenetreConsole
{
public:
    FenetreConsole(Partie p_partie) ;
    std::string DemandeNomPartie();
    int RenvoieChoix();
    int RenvoieChoix(int& montant);
    void AfficherLesMains(Main& p_mainMaison, Main& p_mainJouer);
    void AfficherResultat(const int& p_resultatMain);
    void AfficherMenu();
    char AttendPourEntree();
    int JouerMain(int cartesATirer);
    int JouerMain();
    void JouerPartie(int p_monaie);
    void JouerPartie();
    void Show();
    void SauveGarder(std::string nom);
    void Charger();
    void SauveGarderMontant();
    void SauveGarderMontant(const std::string& p_nomFichier);
    void ChargerMontant(const std::string& p_nomFichier);
    void ChargerLesParties();    
    void SauveGarderLesParties();
    void SauveGarderLesParties(const std::string& p_nomFichier);
    void AfficherLesParties();
private:
    int montantParties;
    std::string lesParties[5];
    BlackJackMains m_lesMains;
    Partie m_partie;
};
