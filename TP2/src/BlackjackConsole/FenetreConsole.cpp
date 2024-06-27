#include "FenetreConsole.h"

FenetreConsole::FenetreConsole(Partie p_partie) :m_partie(100), montantParties(0)
{
	p_partie = m_partie;
}

std::string FenetreConsole::DemandeNomPartie()
{
    std::cout << "Veuillez entrer le nom de votre fichier d'enregistrement" << std::endl;
    std::string nom;
    std::cin >> nom;
    return nom;
}

int FenetreConsole::RenvoieChoix()
{
    AfficherLesMains(this->m_lesMains.m_mainCroupier, this->m_lesMains.m_mainJouer);
    std::cout << "1. Demander      2. S'arreter      3. Sauvegarder      4. Menu Principal" << std::endl;
    char choix = AttendPourEntree();
    if (choix == '1' || choix == '2' || choix == '3' || choix == '4')
    {
        system("cls");
        return choix - '0';
    }
    else
    {
        system("cls");
        return RenvoieChoix();
    }
}

int FenetreConsole::RenvoieChoix(int& montant)
{
    char choix = AttendPourEntree();

    if (choix - 0 >= 1 || choix - 0 <= montant)
    {
        system("cls");
        return choix - '0';
    }
    else
    {
        system("cls");
        return RenvoieChoix();
    }
}

void FenetreConsole::AfficherLesMains(Main& p_mainMaison, Main& p_mainJouer)
{
    if (this->m_lesMains.m_cartesATirer > 0)
    {
        std::cout << "les cartes Du Maison: " << std::endl;
        p_mainMaison.AfficherLesCartesPremierTenu();

        std::cout << std::endl;
        std::cout << "Votre cartes : " << std::endl;
        p_mainJouer.AfficherLesCartes();
    }
    else if (this->m_lesMains.m_cartesATirer == 7)
    {
        ;
    }
    else
    {
        system("cls");
        std::cout << "les cartes Du Maison: " << std::endl;
        p_mainMaison.AfficherLesCartes();

        std::cout << std::endl;
        std::cout << "Votre cartes : " << std::endl;
        p_mainJouer.AfficherLesCartes();
    }
}

void FenetreConsole::AfficherResultat(const int& p_resultatMain)
{
    if (p_resultatMain == -1)
    {
        std::cout << "Malheuresement vouz avez perdu votre mise" << std::endl;
    }
    else if (p_resultatMain == 0)
    {
        std::cout << "Vous etes egale avec la maison vous recupere votre mise" << std::endl;
    }
    else if (p_resultatMain == 1)
    {
        std::cout << "Blackjack! Félicitations, vous avez quadruplé votre mise." << std::endl;
    }
    else if (p_resultatMain == 2)
    {
        std::cout << "Vous avez battu la maison! Votre mise a été doublée." << std::endl;
    }
}

void FenetreConsole::AfficherMenu()
{
    system("cls");
    std::cout << "=========================" << std::endl;
    std::cout << "      Blackjack Menu     " << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "1. Jouer Blackjack" << std::endl;
    std::cout << "2. Charger une partie" << std::endl;
    std::cout << "3. Quitter" << std::endl;
    std::cout << "=========================" << std::endl;
}

char FenetreConsole::AttendPourEntree()
{
    return _getch();
}

int FenetreConsole::JouerMain(int cartesATirer)
{
    if (cartesATirer == 0)
    {
        return this->m_lesMains.ComparerMains();
    }
    if (this->m_lesMains.m_mainJouer.TrouvePoints() > 21)
    {
        return -1;
    }
    int decisionJouer = RenvoieChoix();
    if (decisionJouer == 1)
    {
        this->m_lesMains.Demander();
        int resultat = this->m_lesMains.ComparerMains();
        JouerMain(cartesATirer - 1);
    }
    else if (decisionJouer == 2)
    {
        AfficherLesMains(this->m_lesMains.m_mainCroupier, this->m_lesMains.m_mainJouer);
        this->m_lesMains.m_cartesATirer = 0;
    }
    else if (decisionJouer == 3)
    {
        std::string nom = DemandeNomPartie();
        SauveGarder(nom);
    }
    else if (decisionJouer == 4)
    {
        Show();
    }
    return this->m_lesMains.ComparerMains();
}

int FenetreConsole::JouerMain()
{
    this->m_lesMains.m_mainJouer.InitialiserMain();
    this->m_lesMains.m_mainCroupier.InitialiserMain();
    this->m_lesMains.m_cartesATirer = 7;
    return JouerMain(this->m_lesMains.m_cartesATirer);
}

void FenetreConsole::JouerPartie(int p_monaie)
{
    int resultatMain = JouerMain();
    AfficherLesMains(this->m_lesMains.m_mainCroupier, this->m_lesMains.m_mainJouer);
    this->m_partie.DeciderMise(resultatMain, this->m_lesMains);
    std::cout << "Il vous reste " + std::to_string(this->m_partie.m_monaie) + " piastre" << std::endl;
    if (p_monaie == 0)
    {
        this->m_partie.m_monaie = 100;
        std::cout << "Malheureusement, vous n'avez plus d'argent à miser." << std::endl;
        std::cout << "Appuyez sur n'importe quelle touche pour continuer." << std::endl;
        _getch();
        system("cls");
        Show();
        return;
    }
    if (resultatMain == -1)
    {
        AfficherResultat(-1);
        JouerPartie(p_monaie - 10);
    }
    else if (resultatMain == 0)
    {
        AfficherResultat(0);
        JouerPartie(p_monaie);
    }
    else if (resultatMain == 1 && m_lesMains.m_mainJouer.TrouvePoints() == 21)
    {
        AfficherResultat(1);
        JouerPartie(p_monaie + 40);
    }
    else if (resultatMain == 1 && m_lesMains.m_mainJouer.TrouvePoints() < 21)
    {
        AfficherResultat(2);
        JouerPartie(p_monaie + 20);
    }
}

void FenetreConsole::JouerPartie()
{
    std::cout << "Il vous reste " + std::to_string(this->m_partie.m_monaie) + " piastre" << std::endl;
    JouerPartie(this->m_partie.m_monaie);
}

void FenetreConsole::Show()
{
    int choix;
    do
    {
        AfficherMenu();
        char cle = AttendPourEntree();
        switch (cle)
        {
        case '1':
            choix = 1;
            break;
        case '2':
            choix = 2;
            break;
        case '3':
            choix = 3;
            break;
        default:
            choix = -1;
        }

        switch (choix)
        {
        case 1:
            std::cout << "\nDemmarage..." << std::endl;
            std::cout << "Appuyez sur n'importe quelle touche pour continuer." << std::endl;
            _getch();
            system("cls");
            JouerPartie();
            break;
        case 2:
            Charger();
            std::cout << "\nDemmarage..." << std::endl;
            std::cout << "Appuyez sur n'importe quelle touche pour continuer." << std::endl;
            _getch();
            system("cls");
            JouerPartie();
            break;
        case 3:
            std::cout << "\nMerci d'avoir joué au blackjack." << std::endl;
            exit(0);
            break;
        default:

            break;
        }
    } while (choix != 3);
}

void FenetreConsole::SauveGarder(std::string nom)
{
    
    std::ifstream fichier("parties.txt");
    if (!fichier)
    {
        this->montantParties = 0;
    }
    else
    {
        ChargerMontant("parties.txt");
        ChargerLesParties();
    }
    if (this->montantParties < 5)
    {
        lesParties[this->montantParties] = nom;
        m_lesMains.SauveGarder(this->montantParties);
        m_partie.SauveGarder(this->montantParties);
        this->montantParties++;
    }
    else if (this->montantParties == 5)
    {
        lesParties[0] = nom;
        m_lesMains.SauveGarder(this->montantParties);
        m_partie.SauveGarder(this->montantParties);
    }
    SauveGarderLesParties();
    SauveGarderMontant();
}

void FenetreConsole::Charger()
{
    std::ifstream fichier("parties.txt");
    if (!fichier)
    {
        this->montantParties = 0;
    }
    else
    {
        ChargerMontant("parties.txt");
        ChargerLesParties();
        AfficherLesParties();
        int choix = RenvoieChoix(this->montantParties);
        m_lesMains.Charger(choix);
        m_partie.Charger(choix);
    }
}

void FenetreConsole::SauveGarderMontant()
{
    SauveGarderMontant("parties.txt");
}

void FenetreConsole::SauveGarderMontant(const std::string& p_nomFichier)
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

void FenetreConsole::ChargerMontant(const std::string& p_nomFichier)
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

void FenetreConsole::ChargerLesParties()
{
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

void FenetreConsole::SauveGarderLesParties()
{
    SauveGarderLesParties("lesParties.txt");
}

void FenetreConsole::SauveGarderLesParties(const std::string& p_nomFichier)
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

void FenetreConsole::AfficherLesParties()
{
    if (!lesParties->empty())
    {
        int i = 1;
        for (int j = 0; j < this->montantParties; j++)
        {
            std::cout << std::to_string(j + 1) + lesParties[j] << std::endl;
        }
    }
    else
    {
        std::cout << "Aucune Parties Sauvegarder";
    }
}
