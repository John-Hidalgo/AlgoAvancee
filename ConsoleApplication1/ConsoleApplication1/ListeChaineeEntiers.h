#pragma once
#include <cstddef>
#include <string>
#include <iostream>
class ListeChaineeEntiers
{
public:
    class Noeud
    {
    private:
        int _valuer;
        Noeud* _suivant;
    public:
        friend class ListeChaineeEntiers;
        Noeud()
            :_valuer(NULL), _suivant(nullptr)
        {
        }
        Noeud(const int& p_valeur)
            :Noeud()
        {
            this->_valuer = p_valeur;
            std::string s;

        }
        Noeud(const int& p_valeur, Noeud* p_anterior)
            :Noeud()
        {
            this->_valuer = p_valeur;
            p_anterior->_suivant = this;
        }
        int ObtenirValeur() { return this->_valuer; };
        Noeud* ObtenirSuivant() { return this->_suivant; };
    };
    ListeChaineeEntiers();
    void ajouterFin(const int& p_valeur);
    void ajouterDebut(const int& p_valuer);
    void supprimerFin();
    void supprimerDebut();
    void parcourir(void (*p_fonction)(const int&));
    int& operator[](const int& p_indice)
    {
        if (p_indice > this->nombreDelements - 1)
        {
            throw std::exception();
        }
        Noeud* p = this->premier;
        int i = 0;
        while (i < p_indice)
        {
            p = p->_suivant;
            i++;
        }
        return p->_valuer;
    }
    friend std::ostream& operator<<(std::ostream& p_cout, const ListeChaineeEntiers& n);
public:
    Noeud* premier;
    Noeud* dernier;
    int nombreDelements;
};

void ListeChaineeEntiers::parcourir(void (*p_fonction)(const int&))
{
    Noeud* p = this->premier;
    for (int i = 0; i < this->nombreDelements - 1; i++)
    {
        p = p->_suivant;
        p_fonction(p->ObtenirValeur());
    }
}

std::ostream& operator<<(std::ostream& p_cout, const ListeChaineeEntiers& p_liste)
{
    ListeChaineeEntiers::Noeud* p = p_liste.premier;
    auto liste = p_liste;
    //liste.parcourir(liste.premier->ObtenirValeur());
    p_cout << "{";
    while (p->ObtenirSuivant() != nullptr)
    {
        p_cout << p->ObtenirValeur() << ", ";
        p = p->ObtenirSuivant();
    }
    p_cout << p->ObtenirValeur() << "}" << std::endl;
    return p_cout;
}
ListeChaineeEntiers::ListeChaineeEntiers()
    : premier(nullptr), dernier(nullptr), nombreDelements(0)
{
    //std::cout << "parameterless constructor called" << std::endl;
}
void ListeChaineeEntiers::ajouterFin(const int& p_valuer)
{
    if (nombreDelements == 0)
    {
        //std::cout << "list was empty and added element at the beginning" << std::endl;
        this->premier = new Noeud(p_valuer);
        this->dernier = this->premier;
    }
    else
    {
        //std::cout << "list was non-empty and added element at the beginning" << std::endl;
        Noeud* p = this->premier;
        for (int i = 0; i < this->nombreDelements - 1;i++)
        {
            p = p->_suivant;
        }
        this->dernier = new Noeud(p_valuer, p);

    }
    this->nombreDelements++;
}
void ListeChaineeEntiers::ajouterDebut(const int& p_valuer)
{
    if (nombreDelements == 0)
    {
        //std::cout << "list was empty and added element at the beginning" << std::endl;
        this->premier = new Noeud(p_valuer);
        this->dernier = premier;
        this->nombreDelements++;
    }
    else
    {
        //std::cout << "list was non-empty and added element at the beginning" << std::endl;
        this->premier = new Noeud(p_valuer, this->premier);
        this->nombreDelements++;
    }
}
void ListeChaineeEntiers::supprimerFin()
{
    if (nombreDelements == 0)
    {

    }
    else
    {
        Noeud* p = this->premier;
        for (int i = 0; i < this->nombreDelements - 2;i++)
        {
            p = p->_suivant;
        }
        p->_suivant = nullptr;
        delete this->dernier;
        //this->dernier = nullptr;
        this->dernier = p;
        //std::cout << this->dernier->ObtenirValeur();
    }
    this->nombreDelements--;
}
void ListeChaineeEntiers::supprimerDebut()
{
    if (nombreDelements == 0)
    {

    }
    else
    {
        Noeud* p = this->premier->_suivant;
        delete this->premier;
        this->premier = nullptr;
        this->premier = p;
    }
}

