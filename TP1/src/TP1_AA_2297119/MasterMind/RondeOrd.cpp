#include "RondeOrd.h" 

int RondeOrd::JouerRonde(int p_coups) 
{
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
        string choix;
        m_afficher.MessageReussi();
        choix = _getch();
        system("CLS");
    }
    else
    {
        string choix;
        m_afficher.MessageEchec();
        choix = _getch();
        system("CLS");
    }
    return tentatives;
}
void RondeOrd::FaireCodeParOrdinateur()
{
    //code pour generer les aleatoires pris de
//https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
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
    mt19937 gen(seed);
    int longuer = this->m_couleurs.nombreElements() - 1;
    uniform_int_distribution<unsigned> distrib(0, longuer);
    for (unsigned long j = 0; j < this->m_pions; ++j)
    {
        this->m_codeSecret.ajouterFin(this->m_couleurs.obtenir(distrib(gen)));
        //cout << this->m_codeSecret.obtenir(j) << endl;
    }
}
RondeOrd::RondeOrd()
{
    IRonde::bienPlacee = 0;IRonde::malPlacee = 0;IRonde::m_pions = 0;
}
