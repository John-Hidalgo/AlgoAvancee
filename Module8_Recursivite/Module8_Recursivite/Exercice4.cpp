#include "Exercice4.h"

int Rechercher(int* p_collection, int p_aChercher, int p_taille)
{
    int valeurDefault = -1;
    if (p_taille > 0)
    {
        if (p_aChercher == p_collection[p_taille])
        {
            return p_collection[p_taille];
        }
        else
        {
            Rechercher(p_collection, p_aChercher, p_taille - 1);
            
        }
    }
    return valeurDefault;
}

//int BoucleTableau(int p_tableau[], int p_debut, int p_fin)
//{
//    int valeur = 0;
//    if (p_debut < p_fin) 
//    {
//        valeur = p_tableau[p_debut];
//        BoucleTableau(p_tableau, p_debut++, p_fin);
//    }
//}
