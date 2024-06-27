#pragma once

#include <vector>
//TinyGUISFMLLib
#include "Window/Window.h"
#include "Component/Label.h"
#include "Component/Button.h"
//TinyGUISFMLLib
#include "ListeChainee.h"
#include "Carte.h"
#include "Jeu.h"
#include "Main.h"
#include "BlackJackMains.h"
#include "Partie.h"
class FenetreGUI : public TGUIWSFML::Window::Window
{
public:
	FenetreGUI(Partie partie);
	~FenetreGUI();
	void AfficherMenu();
	void AfficherLesMains();
	void Demander();
	void Arreter();
	void AfficherPoints();
	void AfficherArgent();
	void AfficherGagnant();
	void AfficherPartie();
	void AfficherFentes();
	void PrendNom(int indice);
	void AfficherParties();
	void SauveGarder(int& nom);
	void Charger(int& choix);
	void SauveGarderMontant();
	void SauveGarderMontant(const std::string& p_nomFichier);
	void ChargerMontant(const std::string& p_nomFichier);
	void ChargerLesParties();
	void SauveGarderLesParties();
	void SauveGarderLesParties(const std::string& p_nomFichier);
	virtual void componentsInitialization();
private:
	TGUIWSFML::Component::Label* m_logo;
	TGUIWSFML::Component::Label* m_carte1;
	TGUIWSFML::Component::Label* m_carte2;
	TGUIWSFML::Component::Label* m_carte3;
	TGUIWSFML::Component::Label* m_carte4;
	TGUIWSFML::Component::Label* m_carte5;
	TGUIWSFML::Component::Label* m_carte6;
	TGUIWSFML::Component::Label* m_carte7;
	TGUIWSFML::Component::Label* m_carte8;
	TGUIWSFML::Component::Label* m_carte9;
	TGUIWSFML::Component::Label* m_carte10;
	TGUIWSFML::Component::Label* m_carte11;
	TGUIWSFML::Component::Label* m_carte12;
	TGUIWSFML::Component::Label* m_carte13;
	TGUIWSFML::Component::Label* m_carte14;
	TGUIWSFML::Component::Label* m_pointsJouer;
	TGUIWSFML::Component::Label* m_argentJouer;
	TGUIWSFML::Component::Button* m_jouerPartie;
	TGUIWSFML::Component::Button* m_chargerPartie;
	TGUIWSFML::Component::Button* m_sauveGarderPartie;
	TGUIWSFML::Component::Button* m_revenirMenu;
	TGUIWSFML::Component::Button* m_quitter;
	TGUIWSFML::Component::Button* m_demander;
	TGUIWSFML::Component::Button* m_arreter;
	TGUIWSFML::Component::Button* m_partie1;
	TGUIWSFML::Component::Button* m_partie2;
	TGUIWSFML::Component::Button* m_partie3;
	TGUIWSFML::Component::Button* m_partie4;
	TGUIWSFML::Component::Button* m_partie5;
	TGUIWSFML::Component::Button* m_fente1;
	TGUIWSFML::Component::Button* m_fente2;
	TGUIWSFML::Component::Button* m_fente3;
	TGUIWSFML::Component::Button* m_fente4;
	TGUIWSFML::Component::Button* m_fente5;
	int montantParties;
	std::string lesParties[5];
	BlackJackMains m_lesMains;
	Partie m_partie;
};


