#include "RondeJouer.h"

RondeJouer::RondeJouer()
{
	IRonde::bienPlacee = 0; IRonde::malPlacee = 0;IRonde::m_pions = 0;
}
int RondeJouer::JouerRonde(int p_coups)
{
    DemandePourSecrete();
    int compteur = 0;
    int tentatives = 0;
    bool resultat = false;
    while (compteur < p_coups)
    {
        if (FaireProposition())
        {
            resultat = true;
            tentatives++;
            compteur = p_coups;
        }
        else
        {
            compteur++;
            tentatives++;
            BoucleRonde(tentatives,compteur);
        }
    }
    if (resultat)
    {
        m_afficher.MessageReussi();
        string choix;
        choix = _getch();
        system("CLS");
    }
    else
    {
        tentatives = p_coups + 1;
        string choix;
        m_afficher.MessageEchec();
        choix = _getch();
        system("CLS");
    }
    return tentatives;
}


