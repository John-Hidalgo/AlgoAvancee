#pragma once
#include "IAfficher.h"
#include "Liste.h"
#include <windows.h>
using namespace std;
class AfficheRonde : public IAfficher
{
public:
    void IAfficher::Couleurs(const Liste<char> p_couleurs) {};
    void IAfficher::Couleurs(const Liste<int> p_couleurs);
    void IAfficher::Choix();
    void Historique(const Liste<int> p_historique, Liste<int> p_bien, Liste<int> p_mal, int p_coups);
    void BienMal(Liste<int> p_bien, Liste<int> p_mal, int index);
    void BienMal(int p_bien, int p_mal);
    void MessageSecret(int p_pions);
    void MessageProp(int p_pions);
    void MessageReussi();
    void MessageEchec();
    void SequenceCouleurs(Liste<int>& p_list, Liste<int> p_couleurs,int p_pions);

private:

};

