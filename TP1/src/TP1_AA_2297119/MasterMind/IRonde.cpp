#include "IRonde.h"
void IRonde::EvaluerProposition()
{
    this->malPlacee = 0;
    this->bienPlacee = 0;
    for (int i = 0; i < m_pions;i++)
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
void IRonde::EffacerHistorique()
{
    for (int i = 0;i < this->m_pions;i++)
    {
        this->m_historique.supprimerFin();
    }
    this->m_historiqueBienPlacee.supprimerFin();
    this->m_historiqueMalPlacee.supprimerFin();
}
void IRonde::RegistrerHistorique()
{
    for (int i = 0;i < m_pions;i++)
    {
        this->m_historique.ajouterFin(m_proposition.obtenir(i));
    }
    this->m_historiqueBienPlacee.ajouterFin(this->bienPlacee);
    this->m_historiqueMalPlacee.ajouterFin(this->malPlacee);
}
bool IRonde::FaireProposition()
{
    DemandePourProposition();
    EvaluerProposition();
    RegistrerHistorique();
    m_afficher.BienMal(TrouveBonnePlacee(), TrouveMalPlacee());
    return bienPlacee == m_pions;
}
void IRonde::DemandePourProposition()
{
    if (this->m_proposition.nombreElements() > 0)
    {
        for (int i = 0;i < m_pions;i++)
        {
            this->m_proposition.supprimerFin();
        }
    }
    m_afficher.MessageSecret(this->m_pions);
    m_afficher.SequenceCouleurs(this->m_proposition, this->m_couleurs, this->m_pions);
}
void IRonde::DemandePourSecrete()
{
    m_afficher.MessageSecret(this->m_pions);
    m_afficher.SequenceCouleurs(this->m_codeSecret, this->m_couleurs, this->m_pions);
}
void IRonde::BoucleRonde(int& p_coups, int& p_tentatives)
{
    string choix;
    bool verifier = true;
    do
    {
        this->m_afficher.Choix();
        char choix = _getch();
        if (choix == 49)
        {
            system("CLS");
            this->m_afficher.Historique(this->m_historique, this->m_historiqueBienPlacee, this->m_historiqueMalPlacee, this->m_pions);
            char jette = _getch();
            system("CLS");
            verifier = false;
        }
        else if (choix == 50)
        {
            if (p_tentatives > 1)
            {
                p_tentatives--;
                p_coups--;
                EffacerHistorique();
            }
            break;
        }
        else if (choix == 51)
        {
            break;
        }
        else if (choix == 52)
        {
            exit(0);
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
int IRonde::TrouvePions() const
{
    return this->m_pions;
}
int IRonde::TrouveBonnePlacee() const
{
    return this->bienPlacee;
}
int IRonde::TrouveMalPlacee() const
{
    return this->malPlacee;
}
void IRonde::AffectePions(const int& p_plions)
{
    this->m_pions = p_plions;
}
void IRonde::AffecteCouleurs(Liste<int> p_liste)
{
    for (int i = 0;i < p_liste.nombreElements();i++)
    {
        m_couleurs.ajouterFin(p_liste.obtenir(i));
    }
}