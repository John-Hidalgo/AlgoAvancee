# include "Ronde.h"
# include "Liste.h"
# include <iostream>
#include <string>
using namespace std;
void Ronde::EvaluerProposition()
{
    this->malPlacee = 0;
    this->bienPlacee = 0;
    for (int i = 0; i < m_plions;i++)
    {
        if (this->m_proposition.obtenir(i) == this->m_codeSecret.obtenir(i))
        {
            this->bienPlacee++;
        }
        else if (this->m_codeSecret.Contient(this->m_proposition.obtenir(i)))
        {
            this->malPlacee++;
        }
    }
}
void Ronde::AfficherCouleurs()
{
    int longuer = this->m_couleurs.size();
    for (int i = 0;i < longuer - 1;i++)
    {
        cout << this->m_couleurs[i] << ", ";
    }
    cout << this->m_couleurs[longuer - 1] << " }" << endl;
}
void Ronde::DemandePourSecrete()
{
    bool verifier = true;
    string code;
    do
    {
        cout << "Veuillez entrer votre code secret de couleurs." << endl;
        cout << "Sachez q'il fait " << m_plions << " caractères et il lui faut provenir de la liste de couleurs suivante avec répétitions : " << endl;
        cout << "{ ";
        AfficherCouleurs();
        cin >> code;
        if (code.size() != m_plions)
        {
            verifier = false;
        }
        if (verifier)
        {
            for (int i = 0;i < code.size();i++)
            {
                string temp(1, code[i]);
                if (!strstr(this->m_couleurs.c_str(), temp.c_str()))
                {
                    verifier = false;
                }
            }
        }
        system("CLS");
    } while (!verifier);
    this->m_codeSecret.RemplirParChaine(code);
}
void Ronde::DemandePourProposition()
{
    if (this->m_proposition.nombreElements() > 0)
    {
        for (int i = 0;i < m_plions;i++)
        {
            m_proposition.supprimerFin();
        }
    }
    bool verifier = true;
    string proposition;
    do
    {
        cout << "Veuillez entrer votre proposition de couleurs." << endl;
        cout << "Sachez q'il faut faire " << m_plions << " caractères et il viens de la liste de couleurs suivante avec répétitions : " << endl;
        cout << "{ ";
        AfficherCouleurs();
        cin >> proposition;
        if (proposition.size() != m_plions)
        {
            verifier = false;
        }
        if (verifier)
        {
            for (int i = 0;i < proposition.size();i++)
            {
                string temp(1, proposition[i]);
                if (!strstr(this->m_couleurs.c_str(), temp.c_str()))
                {

                    verifier = false;
                }
            }
        }
        system("CLS");
    } while (!verifier);
    this->m_proposition.RemplirParChaine(proposition);
}
void Ronde::FaireCodeParOrdinateur()
{
}
void Ronde::FairePropositionsParOrdinatuer()
{
}
void Ronde::ConstruireIndex()
{
    for (int i = 0;i < m_plions;i++)
    {
        m_propIndex.ajouterFin(0);
    }
}
void Ronde::MisANouveauIndex()
{
    for (int i = 0;i < m_plions;i++)
    {
        m_propIndex.Affecter(i, 0);
    }
}
bool Ronde::FaireProposition()
{
    DemandePourProposition();
    //MisANouveauIndex();
    EvaluerProposition();
    RegistrerHistorique();
    cout << "Bien placée : " << TrouveBonnePlacee();
    cout << "  Mal placée : " << TrouveMalPlacee() << endl;
    return bienPlacee == m_plions;
}
bool Ronde::JouerRonde(int p_coups)
{
    int compteur = 0;
    bool resultat = false;
    ConstruireIndex();
    DemandePourSecrete();
    while (compteur < p_coups)
    {
        if (FaireProposition())
        {
            resultat = true;
            compteur = p_coups;
        }
        else
        {
            compteur++;
            AfficherChoix(p_coups);
        }
    }
    return resultat;
}
void Ronde::AfficherChoix(int p_coups)
{
    string choix;
    bool verifier = true;
    do
    {
        cout << "1 - Historique" << endl;
        cout << "2 - Revenir en arrière" << endl;
        cout << "3 - Continuer" << endl;
        cout << "4 - Terminer" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        if (choix == "1")
        {
            system("CLS");
            cout << "Historique:" << endl;
            AfficherHistorique(p_coups);
            cin.get();
            verifier = false;
        }
        else if (choix == "2")
        {
            if (p_coups > 1)
            {
                p_coups--;
                EffacerHistorique();
            }
            break;
        }
        else if (choix == "3")
        {
            break;
        }
        else
        {
            verifier = false;
            system("CLS");
        }
    } while (!verifier);
    system("CLS");
}
void Ronde::AfficherHistorique(int p_coups)
{
    int j = 0;
    int k = 0;
    for (int i = 0; i < m_historique.nombreElements();i++)
    {
        cout << m_historique.obtenir(i);
        j++;
        if (j % p_coups == 0)
        {
            cout << " Bien Placée : " << m_historiqueBienPlacee.obtenir(k);
            cout << " Mal Placée : " << m_historiqueMalPlacee.obtenir(k);
            cout << endl;
            k++;
        }
    }
}
void Ronde::EffacerHistorique()
{
    for (int i = 0;i < this->m_plions;i++)
    {
        this->m_historique.supprimerFin();
    }
    this->m_historiqueBienPlacee.supprimerFin();
    this->m_historiqueMalPlacee.supprimerFin();
}
void Ronde::RegistrerHistorique()
{
    for (int i = 0;i < m_plions;i++)
    {
        this->m_historique.ajouterFin(m_proposition.obtenir(i));
    }
    this->m_historiqueBienPlacee.ajouterFin(this->bienPlacee);
    this->m_historiqueMalPlacee.ajouterFin(this->malPlacee);
}
Ronde::Ronde(Liste<char> p_proposition, Liste<char> p_codeSecret, Liste<int> p_codeIndex, int p_plions) :
    m_proposition(p_proposition), m_codeSecret(p_codeSecret), m_propIndex(p_codeIndex), m_plions(p_plions)
{
}
int Ronde::TrouveBonnePlacee()
{
    return this->bienPlacee;
}
int Ronde::TrouveMalPlacee()
{
    return this->malPlacee;
}