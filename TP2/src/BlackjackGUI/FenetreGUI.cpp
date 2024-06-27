#include "FenetreGUI.h"

FenetreGUI::FenetreGUI(Partie partie)
	: Window(1550, 1000, "BlackJack"),
	m_logo(nullptr),
	m_carte1(nullptr),
	m_carte2(nullptr),
	m_carte3(nullptr),
	m_carte4(nullptr),
	m_carte5(nullptr),
	m_carte6(nullptr),
	m_carte7(nullptr),
	m_carte8(nullptr),
	m_carte9(nullptr),
	m_carte10(nullptr),
	m_carte11(nullptr),
	m_carte12(nullptr),
	m_carte13(nullptr),
	m_carte14(nullptr),
	m_pointsJouer(nullptr),
	m_argentJouer(nullptr),
	m_jouerPartie(nullptr),
	m_chargerPartie(nullptr),
	m_sauveGarderPartie(nullptr),
	m_revenirMenu(nullptr),
	m_quitter(nullptr),
	m_demander(nullptr),
	m_arreter(nullptr),
	m_partie1(nullptr),
	m_partie2(nullptr),
	m_partie3(nullptr),
	m_partie4(nullptr),
	m_partie5(nullptr),
	m_fente1(nullptr),
	m_fente2(nullptr),
	m_fente3(nullptr),
	m_fente4(nullptr),
	m_fente5(nullptr),
	montantParties(0),
	m_partie(100)
{
	this->m_partie = partie;
}
FenetreGUI::~FenetreGUI()
{
	this->m_components.clear();
	delete this->m_logo;
	this->m_logo;
	delete this->m_carte1;
	this->m_carte1 = nullptr;
	delete this->m_carte2;
	this->m_carte2 = nullptr;
	delete this->m_carte3;
	this->m_carte3 = nullptr;
	delete this->m_carte4;
	this->m_carte4 = nullptr;
	delete this->m_carte5;
	this->m_carte5 = nullptr;
	delete this->m_carte6;
	this->m_carte6 = nullptr;
	delete this->m_carte7;
	this->m_carte7 = nullptr;
	delete this->m_carte8;
	this->m_carte8 = nullptr;
	delete this->m_carte9;
	this->m_carte9 = nullptr;
	delete this->m_carte10;
	this->m_carte10 = nullptr;
	delete this->m_carte11;
	this->m_carte11 = nullptr;
	delete this->m_carte12;
	this->m_carte12 = nullptr;
	delete this->m_carte13;
	this->m_carte3 = nullptr;
	delete this->m_carte14;
	this->m_carte14 = nullptr;
	delete this->m_pointsJouer;
	this->m_pointsJouer = nullptr;
	delete this->m_jouerPartie;
	this->m_jouerPartie = nullptr;
	delete this->m_argentJouer;
	this->m_argentJouer = nullptr;
	delete this->m_chargerPartie;
	this->m_chargerPartie = nullptr;
	delete this->m_sauveGarderPartie;
	this->m_sauveGarderPartie = nullptr;
	delete this->m_revenirMenu;
	this->m_revenirMenu = nullptr;
	delete this->m_quitter;
	this->m_quitter = nullptr;
	delete this->m_demander;
	this->m_demander = nullptr;
	delete this->m_arreter;
	this->m_arreter = nullptr;
	delete this->m_partie1;
	this->m_partie1 = nullptr;
	delete this->m_partie2;
	this->m_partie2 = nullptr;
	delete this->m_partie3;
	this->m_partie3 = nullptr;
	delete this->m_partie4;
	this->m_partie4 = nullptr;
	delete this->m_partie5;
	this->m_partie5 = nullptr;
	delete this->m_fente1;
	this->m_fente1 = nullptr;
	delete this->m_fente2;
	this->m_fente2 = nullptr;
	delete this->m_fente3;
	this->m_fente3 = nullptr;
	delete this->m_fente4;
	this->m_fente4 = nullptr;
	delete this->m_fente5;
	this->m_fente5 = nullptr;
}
void FenetreGUI::AfficherMenu()
{
	this->m_components.clear();
	this->addComponent(this->m_logo);
	this->addComponent(this->m_jouerPartie);
	this->addComponent(this->m_chargerPartie);
	this->addComponent(this->m_quitter);
}
void FenetreGUI::AfficherLesMains()
{
	TGUIWSFML::Component::Label* cartesJouer[7] =
	{ this->m_carte1 ,this->m_carte2, this->m_carte3 ,this->m_carte4, this->m_carte5, this->m_carte6, this->m_carte7 };
	TGUIWSFML::Component::Label* cartesMaison[7] =
	{ this->m_carte8 ,this->m_carte9, this->m_carte10 ,this->m_carte11, this->m_carte12, this->m_carte13, this->m_carte14 };

	if (this->m_lesMains.m_mainJouer.m_main.Taille() == 1)
	{
		cartesJouer[0]->backgroundTexture(texture(this->m_lesMains.m_mainJouer.m_main.Obtenir(0).TrouveChemin()));
		for (int i = 1; i < 7;i++)
		{
			cartesJouer[i]->backgroundTexture(texture("svg_playing_cards/fronts/png_96_dpi/blank"));
			cartesJouer[i]->backgroundTexture(cartesJouer[i]->currentBackgroundTexture());
		}
	}
	else
	{
		this->m_lesMains.m_mainJouer.Trier();
		for (int i = 0; i < this->m_lesMains.m_mainJouer.m_main.Taille();i++)
		{
			cartesJouer[i]->backgroundTexture(texture(this->m_lesMains.m_mainJouer.m_main.Obtenir(i).TrouveChemin()));
		}
	}

	if (this->m_lesMains.m_mainJouer.m_main.Taille() == 0)
	{
		for (int i = 0; i < 7;i++)
		{
			cartesMaison[i]->backgroundTexture(texture("svg_playing_cards/fronts/png_96_dpi/blank"));
		}
	}
	else if (this->m_lesMains.m_mainJouer.m_main.Taille() == 1)
	{
		cartesMaison[0]->backgroundTexture(texture("svg_playing_cards/backs/png_96_dpi/blue"));
		this->m_lesMains.m_mainCroupier.Trier();
		for (int i = 1; i < 7;i++)
		{
			cartesMaison[i]->backgroundTexture(texture("svg_playing_cards/fronts/png_96_dpi/blank"));
		}
	}
	else if (this->m_lesMains.TrouveATirer() == 0 || this->m_lesMains.m_mainJouer.TrouvePoints() >= 21)
	{
		this->m_lesMains.m_mainCroupier.Trier();
		for (int i = 0; i < this->m_lesMains.m_mainCroupier.m_main.Taille();i++)
		{
			cartesMaison[i]->backgroundTexture(texture(this->m_lesMains.m_mainCroupier.m_main.Obtenir(i).TrouveChemin()));
		}
	}
	else
	{
		cartesMaison[0]->backgroundTexture(texture("svg_playing_cards/backs/png_96_dpi/blue"));
		for (int i = 1; i < this->m_lesMains.m_mainCroupier.m_main.Taille();i++)
		{

			cartesMaison[i]->backgroundTexture(texture(this->m_lesMains.m_mainCroupier.m_main.Obtenir(i).TrouveChemin()));
		}
	}

}
void FenetreGUI::Demander()
{
	this->m_lesMains.Demander();
	AfficherPoints();
	AfficherArgent();
	if (this->m_lesMains.TrouveATirer() == 0 || this->m_lesMains.m_mainJouer.TrouvePoints() >= 21)
	{
		AfficherGagnant();
		AfficherLesMains();
		this->m_lesMains.m_mainJouer.InitialiserMain();
		this->m_lesMains.m_mainCroupier.InitialiserMain();
		this->m_lesMains.m_cartesATirer = 7;
	}
	else
	{
		AfficherLesMains();
	}
	if (this->m_partie.m_monaie == 0)
	{
		this->m_lesMains.m_mainJouer.InitialiserMain();
		this->m_lesMains.m_mainCroupier.InitialiserMain();
		this->m_lesMains.m_cartesATirer = 7;
		AfficherMenu();
		this->m_partie.m_monaie = 100;
	}
}
void FenetreGUI::Arreter()
{
	this->m_lesMains.m_cartesATirer = 0;
	AfficherLesMains();
	AfficherGagnant();
	this->m_lesMains.m_mainJouer.InitialiserMain();
	this->m_lesMains.m_mainCroupier.InitialiserMain();
	this->m_lesMains.m_cartesATirer = 7;
}
void FenetreGUI::AfficherGagnant()
{
	int resultatMain = this->m_lesMains.ComparerMains();
	this->m_partie.DeciderMise(resultatMain, this->m_lesMains);
	if (resultatMain == -1)
	{
		this->m_pointsJouer->text("Points: " + std::to_string(this->m_lesMains.m_mainJouer.TrouvePoints()) +
			" Malheuresement vouz avez perdu votre mise. "
			+ "Il vous reste " + std::to_string(this->m_partie.m_monaie) +" $");
	}
	else if (resultatMain == 0)
	{
		this->m_pointsJouer->text("Points: " + std::to_string(this->m_lesMains.m_mainJouer.TrouvePoints()) +
			" Vous etes egale avec la maison vous recupere votre mise. "
			+ "Il vous reste " + std::to_string(this->m_partie.m_monaie)+ " $");
	}
	else if (resultatMain == 1 && m_lesMains.m_mainJouer.TrouvePoints() == 21)
	{
		this->m_pointsJouer->text("Points: " + std::to_string(this->m_lesMains.m_mainJouer.TrouvePoints()) +
			" Blackjack! Félicitations, vous avez quadruplé votre mise. "
			+ "Il vous reste " + std::to_string(this->m_partie.m_monaie) + " $");
	}
	else if (resultatMain == 1 && m_lesMains.m_mainJouer.TrouvePoints() < 21)
	{
		this->m_pointsJouer->text("Points: " + std::to_string(this->m_lesMains.m_mainJouer.TrouvePoints()) +
			" Vous avez battu la maison! Votre mise a été doublée. "
			+ "Il vous reste " + std::to_string(this->m_partie.m_monaie) + " $");
	}
}
void FenetreGUI::AfficherPoints()
{
	if (this->m_lesMains.m_mainJouer.TrouvePoints() > 0)
	{
		this->m_pointsJouer->text("Points: " + std::to_string(this->m_lesMains.m_mainJouer.TrouvePoints()));
	}
}
void FenetreGUI::AfficherArgent()
{
	this->m_argentJouer->text("Votre Argent: " + std::to_string(this->m_partie.m_monaie) + " $");
}
void FenetreGUI::AfficherPartie()
{
	AfficherLesMains();
	AfficherPoints();
	AfficherArgent();
	TGUIWSFML::Component::Button* parties[5] =
	{ this->m_partie1,this->m_partie2 ,this->m_partie3 ,this->m_partie4 ,this->m_partie5 };
	for (auto x : parties)
	{
		auto i = std::find(this->m_components.begin(), this->m_components.end(), x);
		if (i != this->m_components.end())
		{
			this->m_components.erase(i);
		}
	}
	auto i = std::find(this->m_components.begin(), this->m_components.end(), this->m_jouerPartie);
	if (i != this->m_components.end())
	{
		this->m_components.erase(i);
	}
	auto j = std::find(this->m_components.begin(), this->m_components.end(), this->m_chargerPartie);
	if (j != this->m_components.end())
	{
		this->m_components.erase(j);
	}
	auto k = std::find(this->m_components.begin(), this->m_components.end(), this->m_logo);
	if (k != this->m_components.end())
	{
		this->m_components.erase(k);
	}
	auto p = std::find(this->m_components.begin(), this->m_components.end(), this->m_revenirMenu);
	if (p != this->m_components.end())
	{
		this->m_components.erase(p);
	}
	auto q = std::find(this->m_components.begin(), this->m_components.end(), this->m_sauveGarderPartie);
	if (q != this->m_components.end())
	{
		this->m_components.erase(q);
	}
	auto r = std::find(this->m_components.begin(), this->m_components.end(), this->m_quitter);
	if (r != this->m_components.end())
	{
		this->m_components.erase(r);
	}
	this->addComponent(this->m_carte1);
	this->addComponent(this->m_carte2);
	this->addComponent(this->m_carte3);
	this->addComponent(this->m_carte4);
	this->addComponent(this->m_carte5);
	this->addComponent(this->m_carte6);
	this->addComponent(this->m_carte7);
	this->addComponent(this->m_pointsJouer);
	this->addComponent(this->m_argentJouer);
	this->addComponent(this->m_carte8);
	this->addComponent(this->m_carte9);
	this->addComponent(this->m_carte10);
	this->addComponent(this->m_carte11);
	this->addComponent(this->m_carte12);
	this->addComponent(this->m_carte13);
	this->addComponent(this->m_carte14);
	this->addComponent(this->m_demander);
	this->addComponent(this->m_arreter);
	this->addComponent(this->m_revenirMenu);
	this->addComponent(this->m_sauveGarderPartie);
	this->addComponent(this->m_quitter);
	this->addComponent(this->m_pointsJouer);
	this->m_demander->text("Demander");
	this->m_demander->left(0);
	this->m_demander->width(50);
	this->m_demander->height(15);
	this->m_arreter->text("Arreter");
	this->m_arreter->left(150);
	this->m_arreter->width(50);
	this->m_arreter->height(15);
	this->m_revenirMenu->text("Menu Principal");
	this->m_revenirMenu->left(650);
	this->m_revenirMenu->width(80);
	this->m_revenirMenu->height(30);
	this->m_sauveGarderPartie->text("Sauvegarder");
	this->m_sauveGarderPartie->left(660);
	this->m_sauveGarderPartie->width(80);
	this->m_sauveGarderPartie->height(30);
}
void FenetreGUI::AfficherFentes()
{
	TGUIWSFML::Component::Button* fentes[5] =
	{ this->m_fente1,this->m_fente2 ,this->m_fente3 ,this->m_fente4 ,this->m_fente5 };
	for (auto x : fentes)
	{
		auto i = std::find(this->m_components.begin(), this->m_components.end(), x);
		if (i != this->m_components.end())
		{
			this->m_components.erase(i);
		}
	}
	for (auto x : fentes)
	{
		this->addComponent(x);
	}
	auto i = std::find(this->m_components.begin(), this->m_components.end(), this->m_jouerPartie);
	if (i != this->m_components.end())
	{
		this->m_components.erase(i);
	}
	auto j = std::find(this->m_components.begin(), this->m_components.end(), this->m_chargerPartie);
	if (j != this->m_components.end())
	{
		this->m_components.erase(j);
	}
	auto k = std::find(this->m_components.begin(), this->m_components.end(), this->m_quitter);
	if (k != this->m_components.end())
	{
		this->m_components.erase(k);
	}
	auto l = std::find(this->m_components.begin(), this->m_components.end(), this->m_revenirMenu);
	if (l != this->m_components.end())
	{
		this->m_components.erase(l);
	}
	auto m = std::find(this->m_components.begin(), this->m_components.end(), this->m_sauveGarderPartie);
	if (m != this->m_components.end())
	{
		this->m_components.erase(m);
	}
	ChargerLesParties();
	int n = 0;
	for (std::string x : this->lesParties)
	{
		fentes[n]->text(x);
		fentes[n]->left(700);
		fentes[n]->width(80);
		fentes[n]->height(30);
		n++;
	}
}
void FenetreGUI::PrendNom(int indice)
{
	m_fente1->text("");
	std::string nomfichier;
	std::cin >> nomfichier;
	m_fente1->text(nomfichier);
	lesParties[indice] = nomfichier;
}
void FenetreGUI::AfficherParties()
{
	TGUIWSFML::Component::Button* parties[5] =
	{ this->m_partie1,this->m_partie2 ,this->m_partie3 ,this->m_partie4 ,this->m_partie5 };
	for (auto x : parties)
	{
		auto i = std::find(this->m_components.begin(), this->m_components.end(), x);
		if (i != this->m_components.end())
		{
			this->m_components.erase(i);
		}
	}
	for (auto x : parties)
	{
		this->addComponent(x);
	}
	auto i = std::find(this->m_components.begin(), this->m_components.end(), this->m_jouerPartie);
	if (i != this->m_components.end())
	{
		this->m_components.erase(i);
	}
	auto j = std::find(this->m_components.begin(), this->m_components.end(), this->m_chargerPartie);
	if (j != this->m_components.end())
	{
		this->m_components.erase(j);
	}
	auto k = std::find(this->m_components.begin(), this->m_components.end(), this->m_quitter);
	if (k != this->m_components.end())
	{
		this->m_components.erase(k);
	}
	ChargerLesParties();
	int m = 0;
	for (std::string x : this->lesParties)
	{
		parties[m]->text(x);
		parties[m]->left(700);
		parties[m]->width(80);
		parties[m]->height(30);
		m++;
	}
}
void FenetreGUI::SauveGarder(int& nom)
{
	std::ifstream fichier("parties.txt");
	if (!fichier)
	{
		this->montantParties = 0;
	}
	else
	{
		ChargerMontant("parties.txt");
	}
	m_lesMains.SauveGarder(nom);
	m_partie.SauveGarder(nom);
	SauveGarderLesParties();
	SauveGarderMontant();
	TGUIWSFML::Component::Button* fentes[5] =
	{ this->m_fente1,this->m_fente2 ,this->m_fente3 ,this->m_fente4 ,this->m_fente5 };
	for (auto x : fentes)
	{
		auto i = std::find(this->m_components.begin(), this->m_components.end(), x);
		if (i != this->m_components.end())
		{
			this->m_components.erase(i);
		}
	}
	this->addComponent(this->m_revenirMenu);
	this->addComponent(this->m_sauveGarderPartie);
	this->addComponent(this->m_quitter);
	AfficherPartie();
}
void FenetreGUI::Charger(int& choix)
{
	std::ifstream fichier("parties.txt");
	if (!fichier)
	{
		this->montantParties = 0;
	}
	else
	{
		ChargerMontant("parties.txt");
		m_lesMains.Charger(choix);
		m_partie.Charger(choix);
	}
}
void FenetreGUI::SauveGarderMontant()
{
	SauveGarderMontant("parties.txt");
}
void FenetreGUI::SauveGarderMontant(const std::string& p_nomFichier)
{
	std::ofstream fichier(p_nomFichier);
	if (!fichier)
	{
		std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
		return;
	}
	fichier << montantParties << " ";
	fichier.close();
}
void FenetreGUI::ChargerMontant(const std::string& p_nomFichier)
{
	std::ifstream fichier(p_nomFichier);
	if (!fichier)
	{
		std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
		return;
	}
	fichier >> montantParties;
	fichier.close();
}
void FenetreGUI::ChargerLesParties()
{
	if (lesParties->empty())
	{

	}
	std::ifstream fichier("lesParties.txt");
	if (!fichier)
	{
		std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
		return;
	}
	for (size_t i = 0; i < 5; ++i)
	{
		std::getline(fichier, lesParties[i]);
	}
	fichier.close();
}
void FenetreGUI::SauveGarderLesParties()
{
	SauveGarderLesParties("lesParties.txt");
}
void FenetreGUI::SauveGarderLesParties(const std::string& p_nomFichier)
{
	std::ofstream fichier(p_nomFichier);
	if (!fichier)
	{
		std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
		return;
	}
	for (int i = 0; i < 5;i++)
	{
		fichier << lesParties[i] << std::endl;
	}
	fichier.close();
}
inline void FenetreGUI::componentsInitialization()
{
	this->m_logo = new TGUIWSFML::Component::Label(1, 1, 1550, 1000, "");
	this->m_logo->backgroundTexture(texture("svg_playing_cards/other/png_96_dpi/blackjack2"));
	this->addComponent(this->m_logo);
	this->m_carte1 = new TGUIWSFML::Component::Label(10, 350, 210, 300, "");
	this->m_carte2 = new TGUIWSFML::Component::Label(225, 350, 210, 300, "");
	this->m_carte3 = new TGUIWSFML::Component::Label(445, 350, 210, 300, "");
	this->m_carte4 = new TGUIWSFML::Component::Label(665, 350, 210, 300, "");
	this->m_carte5 = new TGUIWSFML::Component::Label(885, 350, 210, 300, "");
	this->m_carte6 = new TGUIWSFML::Component::Label(1105, 350, 210, 300, "");
	this->m_carte7 = new TGUIWSFML::Component::Label(1325, 350, 210, 300, "");
	this->m_pointsJouer = new TGUIWSFML::Component::Label(10, 315, 50, 20, "");
	this->addComponent(this->m_pointsJouer);
	this->m_argentJouer = new TGUIWSFML::Component::Label(10, 850, 50, 20, "");
	this->addComponent(this->m_argentJouer);
	this->m_carte8 = new TGUIWSFML::Component::Label(10, 1, 210, 300, "");
	this->m_carte9 = new TGUIWSFML::Component::Label(225, 1, 210, 300, "");
	this->m_carte10 = new TGUIWSFML::Component::Label(445, 1, 210, 300, "");
	this->m_carte11 = new TGUIWSFML::Component::Label(665, 1, 210, 300, "");
	this->m_carte12 = new TGUIWSFML::Component::Label(885, 1, 210, 300, "");
	this->m_carte13 = new TGUIWSFML::Component::Label(1105, 1, 210, 300, "");
	this->m_carte14 = new TGUIWSFML::Component::Label(1325, 1, 210, 300, "");
	this->m_jouerPartie = new TGUIWSFML::Component::Button(650, 750, 80, 30, "Jouer BlackJack");
	this->addComponent(this->m_jouerPartie);
	this->m_jouerPartie->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			AfficherPartie();
		});
	this->m_revenirMenu = new TGUIWSFML::Component::Button(-10, 750, 0, 0, "");
	this->addComponent(this->m_revenirMenu);
	this->m_revenirMenu->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			AfficherMenu();
		});
	this->m_chargerPartie = new TGUIWSFML::Component::Button(635, 800, 80, 30, "Charger Une Partie");
	this->addComponent(this->m_chargerPartie);
	this->m_chargerPartie->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			AfficherParties();
		});
	this->m_sauveGarderPartie = new TGUIWSFML::Component::Button(-10, 800, 0, 0, "");
	this->addComponent(m_sauveGarderPartie);
	this->m_sauveGarderPartie->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			AfficherFentes();
		});
	this->m_quitter = new TGUIWSFML::Component::Button(680, 850, 80, 30, "Quitter");
	this->addComponent(this->m_quitter);
	this->m_quitter->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			exit(0);
		});
	this->m_demander = new TGUIWSFML::Component::Button(-10, 700, 0, 0, "");
	this->addComponent(this->m_demander);
	this->m_demander->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			Demander();
		});
	this->m_arreter = new TGUIWSFML::Component::Button(-10, 700, 0, 0, "");
	this->addComponent(this->m_arreter);
	this->m_arreter->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			Arreter();
		});
	this->m_partie1 = new TGUIWSFML::Component::Button(-10, 700, 0, 0, "");
	this->addComponent(this->m_partie1);
	this->m_partie1->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 1;
			Charger(i);
			AfficherPartie();
		});
	this->m_partie2 = new TGUIWSFML::Component::Button(-10, 750, 0, 0, "");
	this->addComponent(this->m_partie2);
	this->m_partie2->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 2;
			Charger(i);
			AfficherPartie();
		});
	this->m_partie3 = new TGUIWSFML::Component::Button(-10, 800, 0, 0, "");
	this->addComponent(this->m_partie3);
	this->m_partie3->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 3;
			Charger(i);
			AfficherPartie();
		});
	this->m_partie4 = new TGUIWSFML::Component::Button(-10, 850, 0, 0, "");
	this->addComponent(this->m_partie4);
	this->m_partie4->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 4;
			Charger(i);
			AfficherPartie();
		});
	this->m_partie5 = new TGUIWSFML::Component::Button(-10, 900, 0, 0, "");
	this->addComponent(this->m_partie5);
	this->m_partie5->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 5;
			Charger(i);
			AfficherPartie();
		});

	this->m_fente1 = new TGUIWSFML::Component::Button(-10, 700, 0, 0, "");
	this->addComponent(this->m_fente1);
	this->m_fente1->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 1;
			PrendNom(0);
			SauveGarder(i);
		});
	this->m_fente2 = new TGUIWSFML::Component::Button(-10, 750, 0, 0, "");
	this->addComponent(this->m_fente2);
	this->m_fente2->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 2;
			PrendNom(1);
			SauveGarder(i);
		});
	this->m_fente3 = new TGUIWSFML::Component::Button(-10, 800, 0, 0, "");
	this->addComponent(this->m_fente3);
	this->m_fente3->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 3;
			PrendNom(2);
			SauveGarder(i);
		});
	this->m_fente4 = new TGUIWSFML::Component::Button(-10, 850, 0, 0, "");
	this->addComponent(this->m_fente4);
	this->m_fente4->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 4;
			PrendNom(3);
			SauveGarder(i);
		});
	this->m_fente5 = new TGUIWSFML::Component::Button(-10, 900, 0, 0, "");
	this->addComponent(this->m_fente5);
	this->m_fente5->addMouseClickHandler([&](const TGUIWSFML::Event::MouseEvent& me)
		{
			int i = 5;
			PrendNom(4);
			SauveGarder(i);
		});
	ChargerLesParties();
}

;
