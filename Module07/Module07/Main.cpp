#include <iostream>
#include "Liste.h"
#include <list>
template <typename T>
class Pile
{
public: 
    void Empiler(const T&);// ajoute un élément au sommet de la pile
    T Depiler(); //retire l'élément au sommet de la pile et le retourne
    T Sommet(); //retourne l'élément au sommet de la pile sans le retirer
    bool EstPileVide(); //indique si la pile est vide ou non
    int Taille(); //entier

    void operator~();
    void operator+(Pile);

    template <typename T>
    friend std::ostream& operator<<(std::ostream&, const Pile<T>&);
    
private:
    Liste<T> _valeurs;
};

int main()
{
    Liste<int> maliste;
    Liste<int> liste2;
    maliste.Ajouter(1);
    maliste.Ajouter(2);
    liste2.Inserer(0, 1);
    liste2.Inserer(1, 2);
    liste2.Inserer(2, 3);
    liste2.Retirer(0);
    maliste + 3;
    maliste = maliste + liste2;
    liste2[0] = 0;
    ~maliste;
    //std::cout << maliste;
    std::list<int> l;
    l.clear();

    Pile<int> pile;
    pile.Empiler(4);
    pile.Empiler(3);
    pile.Empiler(2);
    pile.Empiler(1);
    Pile<int> pile2;
    pile2.Empiler(4);
    pile2.Empiler(3);
    pile2.Empiler(2);
    pile2.Empiler(1);
    
    pile + pile2;
    std::cout << pile;

}


