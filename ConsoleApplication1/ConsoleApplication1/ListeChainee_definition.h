#pragma once
#include "ListeChainee.h"






template<typename T>
class Noeud
{
private:
    T _valeur;
    Noeud* _suivant;
private:
    Noeud()
        :_valeur(0), _suivant(nullptr)
    {
    }
    Noeud(const int& p_valeur)
        :Noeud()
    {
        this->_valeur = p_valeur;
    }
    Noeud(const int& p_valeur, Noeud* p_anterior)
        :Noeud()
    {
        this->_valeur = p_valeur;
        p_anterior->_suivant = p_valeur;
    }
    T ObtenirValeur();
    Noeud* ObtenirSuivant();
};
