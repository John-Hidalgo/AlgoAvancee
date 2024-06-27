#include "Match.h"
#include "FonctionsDaide.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <math.h>
using namespace std;

Liste<int> Match::ChoisirCouleurs(int p_montant)
{
	Liste<int>liste;
	for (int i = 1;i < 15;i++) 
	{
		liste.ajouterFin(i);
	}
	Liste<int> choix;
	int decallageX = 0;
	int pointeX = 0;
	int pointY = 0;
	m_afficher.GuiderCouleurs(p_montant);
	m_afficher.Couleurs(liste);
	AffectePointeXY(0, 3);
	while (decallageX < p_montant)
	{
		char Keys = _getch();
		//printf("Keys=%d\n", Keys);
		if (Keys == 77)
		{
			if (pointeX >= 0 && pointeX < 13)
			{
				pointeX++;
				AffectePointeXY(pointeX, 3);
			}
			else if (pointeX == 13)
			{
				pointeX = 13;
				AffectePointeXY(pointeX, 3);
			}
		}
		else if (Keys == 75)
		{
			if (pointeX > 0 && pointeX <= 14)
			{
				pointeX--;
				AffectePointeXY(pointeX, 3);
			}
			else if (pointeX == 0)
			{
				pointeX = 0;
				AffectePointeXY(pointeX, 3);
			}
		}
		else if (Keys == 13 && !choix.Contient(pointeX + 1))
		{
			AffectePointeXY(decallageX, 4);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), pointeX + 1);
			//cout << "\25";
			std::cout << (char)254u;
			AffectePointeXY(pointeX, 3);
			choix.ajouterFin(pointeX + 1);
			decallageX++;
		}
	}
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return choix;
}
void Match::MenuPrincipal()
{
	{
		Match muette;
		char choix;
		bool verifier = true;
		do
		{
			muette.m_afficher.Choix();
			choix = _getch();
			switch (choix)
			{
			case 49:
				system("CLS");
				verifier = true;
				break;
			case 50:
				system("CLS");
				verifier = true;
				break;
			case 51:
				system("CLS");
				cout << "Merci d'avoir joué au Mastermind." << endl;
				exit(0);
				break;
			default:
				system("CLS");
				verifier = false;
				break;
			}
		} while (!verifier);
		if (choix == 49)
		{
			{
				Match match = muette.ConstruireMatch(muette);
				match.JouerRondes();
			}
		}
		else if (choix == 50)
		{
			{
				Match match = muette.ConstruireMatchOrd(muette);
				match.JouerContreOrdinateur();
			}
		}
	}
	MenuPrincipal();
}
Match Match::ConstruireMatch(Match p_muette)
{
	const int rondes = LireEntierPositive("veuillez entrer le nombre de rondes a joue.");
	system("CLS");
	const int coups = LireEntierPositive("veuillez entrer le nombre de tentatives pour tenter de casser le code.");
	system("CLS");
	const int pions = LireEntierPositive("veuillez entrer la longueur du code.");
	system("CLS");
	const int montantCouleurs = LireEntierPositive("veuillez entrer combien du couleurs que vous voulez");
	system("CLS");
	const Liste<int> couleurs = p_muette.ChoisirCouleurs(montantCouleurs);
	Match match(rondes, coups, pions, couleurs);
	return match;
}
Match Match::ConstruireMatchOrd(Match p_muette)
{
	const int coups = LireEntierPositive("veuillez entrer le nombre de tentatives pour tenter de casser le code.");
	system("CLS");
	const int pions = LireEntierPositive("veuillez entrer la longueur du code.");
	system("CLS");
	const int montantCouleurs = LireEntierPositive("veuillez entrer combien du couleurs que vous voulez");
	system("CLS");
	const Liste<int> couleurs = p_muette.ChoisirCouleurs(montantCouleurs);
	Match match(coups, pions, couleurs);
	return match;
}
void Match::JouerRondes()
{
	for (int i = 0;i < m_rondes;i++)
	{
		if (i % 2 == 0)
		{
			char choix;
			bool verifier = false;
			do
			{
				m_afficher.GuiderJouer1(this->m_jouer1[0], this->m_jouer2[0]);
				choix = _getch();
				system("CLS");
				verifier = true;
			} while (!verifier);
			system("CLS");
		}
		else if (i % 2 == 1)
		{
			char choix;
			bool verifier = false;
			do
			{
				m_afficher.GuiderJouer2(this->m_jouer1[0], this->m_jouer2[0]);
				choix = _getch();
				system("CLS");
				verifier = true;
			} while (!verifier);
			system("CLS");
		}
		m_resultats.ajouterFin(m_rondesJouer[i].JouerRonde(TrouveCoups()));
		CalculerScore(i);
	}
	cout << endl;
	m_afficher.AnnoncerGangnant(this->m_jouer1,this->m_jouer2);
	delete[] m_rondesJouer;
	this->m_rondesJouer = nullptr;
	char commence = _getch();
	system("CLS");
	return;
}
void Match::JouerContreOrdinateur()
{
	this->m_rondeOrd.FaireCodeParOrdinateur();
	this->m_rondeOrd.JouerRonde(TrouveCoups());
}
void Match::CalculerScore(int p_ronde)
{
	if (p_ronde % 2 == 0)
	{
		if (m_resultats.obtenir(p_ronde) <= this->m_coups)
		{
			m_jouer2[0] += (pow(10, this->m_rondesJouer[p_ronde].TrouvePions()) / pow(1.618, this->m_resultats.obtenir(p_ronde) - 1));
		}
	}
	else if (p_ronde % 2 == 1 > 0)
	{
		if (m_resultats.obtenir(p_ronde) <= this->m_coups)
		{
			m_jouer1[0] += (pow(10, this->m_rondesJouer[p_ronde].TrouvePions()) / pow(1.618, this->m_resultats.obtenir(p_ronde) - 1));
		}
	}
}
Match::Match(int p_rondes,int p_coups, int p_pions, Liste<int> p_couleurs) :
	m_rondes(p_rondes * 2), m_coups(p_coups), m_rondesJouer(new RondeJouer[p_rondes * 2])
{
	for (int i = 0; i < m_rondes;i++)
	{
		m_rondesJouer[i].AffectePions(p_pions);
		m_rondesJouer[i].AffecteCouleurs(p_couleurs);
	}
}
Match::Match(const int p_coups, const int p_pions, const Liste<int> p_couleurs):
	m_rondes(0), m_coups(p_coups),m_rondesJouer(nullptr)
{
	m_rondeOrd.AffectePions(p_pions);
	m_rondeOrd.AffecteCouleurs(p_couleurs);
}
Match::Match():m_coups(0)
{
}
int Match::TrouveCoups() const { return m_coups; }