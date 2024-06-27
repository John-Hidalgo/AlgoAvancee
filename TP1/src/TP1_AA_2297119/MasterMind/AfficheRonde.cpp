#include "AfficheRonde.h"
#include "FonctionsDaide.h"
#include <conio.h>

void AfficheRonde::Choix()
{
    cout << "1 - Historique" << endl;
    cout << "2 - Revenir en arrière" << endl;
    cout << "3 - Continuer" << endl;
    cout << "4 - Terminer" << endl;
    cout << "Votre choix : ";
}
void AfficheRonde::MessageSecret(int p_pions)
{
    cout << "Veuillez votre entrer code secret de couleurs." << endl;
    cout << "Sachez q'il faut faire " << p_pions << " couleurs" << endl;
    cout << "faites défiler les couleurs disponibles avec les touches" << endl;
    cout << "directionnelles et choisissez avec la touche entrée." << endl;
}
void AfficheRonde::MessageProp(int p_pions)
{
    cout << "Veuillez entrer votre proposition de couleurs." << endl;
    cout << "Sachez q'il faut faire " << p_pions << " couleurs" << endl;
    cout << "faites défiler les couleurs disponibles avec les touches" << endl;
    cout << "directionnelles et choisissez avec la touche entrée." << endl;
}
void AfficheRonde::MessageReussi()
{
    cout << "Félicitations, vous avez décrypté le code." << endl;
    cout << "Appuyez sur n'importe quelle touche pour continuer" << endl;
}
void AfficheRonde::MessageEchec()
{
    cout << "Malheureusement, vous n'avez pas réussi à déchiffrer le code." << endl;
    cout << "Appuyez sur Entrée pour continuer";
}
void AfficheRonde::Couleurs(Liste<int> p_couleurs)
{
    int longuer = p_couleurs.nombreElements();
    if (longuer < 0)
    {
        throw std::invalid_argument("La taille du tableau n'est pas valide");
    }
    for (int i = 0;i < longuer;i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p_couleurs.obtenir(i));
        std::cout << (char)254u;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void AfficheRonde::BienMal(Liste<int> p_bien, Liste<int> p_mal, int index)
{
    if (index < 0)
    {
        throw std::invalid_argument("L'index n'est pas valide");
    }
    cout << " Bien Placée : " << p_bien.obtenir(index);
    cout << " Mal Placée : " << p_mal.obtenir(index);
    cout << endl;
}
void AfficheRonde::BienMal(int p_bien,int p_mal)
{
    if (p_bien < 0 || p_mal < 0)
    {
        throw std::invalid_argument("L'es entier ne sont pas valide");
    }
    cout << "Bien placée : " << p_bien;
    cout << "  Mal placée : " << p_mal << endl;
}
void AfficheRonde::Historique(Liste<int> p_historique, Liste<int> p_bien, Liste<int> p_mal, int p_coups)
{
    if (p_coups < 0)
    {
        throw std::invalid_argument("Les coups ne sont pas valides");
    }
    int longuer = p_historique.nombreElements();
    if (longuer < 0)
    {
        throw std::invalid_argument("La taille du tableau n'est pas valide");
    }
    cout << "Historique:" << endl;
    int j = 0;
    int k = 0;
    for (int i = 0; i < longuer;i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p_historique.obtenir(i));
        cout << (char)254u;
        j++;
        if (j % p_coups == 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            BienMal(p_bien, p_mal, k);
            k++;
        }
    }
    cout << endl;
    cout << "Appuyez sur n'importe quelle touche pour revenir au menu";
}
void AfficheRonde::SequenceCouleurs(Liste<int>& p_list, Liste<int> p_couleurs,int p_pions)
{
    int decallageX = 0;
    int pointeX = 0;
    int pointY = 0;
    Couleurs(p_couleurs);
    AffectePointeXY(0, 4);
    while (decallageX < p_pions)
    {
        char cle = _getch();
        //printf("cle=%d\n", cle);
        if (cle == 77)
        {
            if (pointeX >= 0 && pointeX < p_couleurs.nombreElements() - 1)
            {
                pointeX++;
                AffectePointeXY(pointeX, 4);
            }
            else if (pointeX == p_couleurs.nombreElements() - 1)
            {
                pointeX = p_couleurs.nombreElements() - 1;
                AffectePointeXY(pointeX, 4);
            }
        }
        else if (cle == 75)
        {
            if (pointeX > 0 && pointeX <= p_couleurs.nombreElements() - 1)
            {
                pointeX--;
                AffectePointeXY(pointeX, 4);
            }
            else if (pointeX == 0)
            {
                pointeX = 0;
                AffectePointeXY(pointeX, 4);
            }
        }
        else if (cle == 13)
        {
            AffectePointeXY(decallageX, 5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), p_couleurs.obtenir(pointeX));
            //cout << "\25";
            cout << (char)254u;
            AffectePointeXY(pointeX, 4);
            p_list.ajouterFin(p_couleurs.obtenir(pointeX));
            decallageX++;
        }
    }
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


