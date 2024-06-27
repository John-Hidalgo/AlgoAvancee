#pragma once
#include <iostream>


class Carte
{
public:
    friend class Main;
    Carte() : m_chemin(""), m_nom(""), m_enseigne(""), m_valeurPourTrie(0),m_enseignePourTrie(0), m_valeur(0), m_restant(52){};
    Carte(const std::string p_chemin, const std::string p_nom, const std::string p_enseigne, const int p_valeurPourTrie, const int p_enseignePourTrie,const int p_valeur)
    {
        this->m_chemin = p_chemin;
        this->m_nom = p_nom;
        this->m_enseigne = p_enseigne;
        this->m_valeurPourTrie = p_valeurPourTrie;
        this->m_enseignePourTrie = p_enseignePourTrie;
        this->m_valeur = p_valeur;
    };
    int TrouveValeur() const { return m_valeur; }
    bool operator<(Carte p_carte)
    {
        bool resultat = true;
        //std::cout << this->m_valeur << " < " << p_carte.m_valeur << std::endl;
        if (this->m_valeurPourTrie >= p_carte.m_valeurPourTrie)
        {
            if (this->m_enseignePourTrie >= p_carte.m_enseignePourTrie)
            {
                return false;
            }
        }
        return resultat;
    };
    bool operator==(const Carte& p_carte)
    {
        if (this->m_nom == p_carte.m_nom && this->m_enseigne == p_carte.m_enseigne)
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    bool operator!=(const Carte& p_carte)
    {
        return !(*this == p_carte);
    };
public:
    std::string m_chemin;
    std::string m_nom;
    std::string m_enseigne;
    int m_valeurPourTrie;
    int m_enseignePourTrie;
    int m_valeur;
    int m_restant;
};

template<typename T>
class Noeud
{
public:
    T _valeur;
    Noeud<T>* _suivant;

    Noeud(T p_valeur)
        :_valeur(p_valeur), _suivant(nullptr)
    {
        ;
    };
    Noeud(T p_valeur, Noeud* p_anterior)
        :_valeur(p_valeur), _suivant(nullptr)
    {
        this->_valeur = p_valeur;
        p_anterior->_suivant = this;
    };
    Noeud(T p_valeur, Noeud*p_anterior, Noeud* p_suivant)
        :_valeur(p_valeur), _suivant(nullptr)
    {
        this->_valeur = p_valeur;
        p_anterior->_suivant = this;
        this->_suivant = p_suivant;
    };
};

template <typename T>
class ListeChainee
{
public:
    class Iterateur;
    ListeChainee();
    ListeChainee(const ListeChainee&);
    ListeChainee(ListeChainee&&);
    ~ListeChainee();

    void AjouterFin(T);
    void AjouterDebut(T);
    void AjouterA(int, T);
    void SupprimerFin();
    void SupprimerDebut();
    void SupprimerA(int);
    T SupprimerAEtRenvoie(int);
    void Vider(int p_taille);
    void Vider();
    void parcourir(void (*p_fonction)(const int&));
    void Trier(bool (*p_fonctionTri)(const int&, const int&));
    void TrierAscendant();
    T Obtenir(int);
    void Affecter(const int& p_indice,const T& p_valeur)
    {
        Noeud<T>* p = this->_premier;
        int i = 0;
        while (i < this->_taille - 1)
        {
            p = p->_suivant;
            i++;
        }
        p->_valeur = p_valeur;
    };
    int Taille() { return this->_taille; };
    Iterateur begin() { return this->_premier;};
    Iterateur end() { return this->_dernier->_suivant;};
    bool operator==(const ListeChainee& p_liste);
    bool operator!=(const ListeChainee& p_liste);
    ListeChainee<T>& operator=(const ListeChainee&);
    ListeChainee<T>& operator=(ListeChainee&&);

    T& operator[](const int& p_indice)
    {
        if (p_indice > this->_taille - 1)
        {
            throw std::exception();
        }
        Noeud<T>* p = this->_premier;
        int i = 0;
        while (i < p_indice)
        {
            p = p->_suivant;
            i++;
        }
        return p->_valeur;
    };
    void operator~()
    {
        int i = 0;
        int j = this->_taille - 1;
        while (i < j)
        {
            Echanger(i,j);
            i++;
            j--;
        }
    };
    template<typename T>
    friend std::ostream& operator<<(std::ostream& p_cout, const ListeChainee<T>& p_liste);

private:
    Noeud<T>* _premier;
    Noeud<T>* _dernier;
    int _taille;
    Noeud<T>* NoeudA(const int& p_indice)
    {
        Noeud<T>* p = this->_premier;
        if (p_indice < 0 || p_indice > this->_taille - 1) 
        {
            throw std::exception();
        }
        int i = 0;
        while (i < p_indice)
        {
            p = p->_suivant;
            i++;
        }
        return p;
    };
    void SupprimerNoeud(Noeud<T>* p_noeud, Noeud<T>* p_anterior);
    void Echanger(const int&, const int&);
    
};
template<typename T>
ListeChainee<T>::ListeChainee()
    :_premier(nullptr), _dernier(nullptr), _taille(0)
{
    std::cout << "parameterless constructor called" << std::endl;
}
template<typename T>
ListeChainee<T>::ListeChainee(const ListeChainee& p_ancienneListe)
    :ListeChainee()
{
    std::cout << "copy constructor called" << std::endl;
    Noeud<T>* x = p_ancienneListe._premier;
    if (p_ancienneListe._taille != 0)
    {
        for (int i = 0; i < p_ancienneListe._taille; i++);
        {
            AjouterFin(x->_valeur);
            x = x->_suivant;
        } 
    }
}
template<typename T>
ListeChainee<T>::ListeChainee(ListeChainee&& p_ancienneListe) 
    :_premier(p_ancienneListe._premier), _dernier(p_ancienneListe._dernier), _taille(p_ancienneListe._taille)
{
    std::cout << "move constructor called" << std::endl;
    p_ancienneListe = nullptr;
}
template<typename T>
ListeChainee<T>::~ListeChainee()
{
    Vider();
}
template<typename T>
void ListeChainee<T>::AjouterFin(T p_element)
{
    if (this->_taille == 0)
    {
        this->_premier = new Noeud<T>(p_element);
        this->_dernier = this->_premier;
    }
    else
    {
        Noeud<T>* p = this->_dernier;
        this->_dernier = new Noeud<T>(p_element, p);
    }
    this->_taille++;
}
template<typename T>
void ListeChainee<T>::AjouterDebut(T p_element)
{
    if (this->_taille == 0)
    {
        this->_premier = new Noeud<T>(p_element);
        this->_dernier = this->_premier;
    }
    else
    {
        Noeud<T>* p = this->_premier;
        this->_premier = new Noeud<T>(p_element);
        this->_premier->_suivant = p;
    }
    this->_taille++;
}
template<typename T>
void ListeChainee<T>::AjouterA(int p_indice,T p_element)
{
    if (p_indice < 0 || p_indice > this->_taille - 1)
    {
        throw std::exception();
    }
    if (p_indice == 0)
    {
        AjouterDebut(p_element);
    }
    else if (p_indice == this->_taille - 1) 
    {
        AjouterFin(p_element);
    }
    else if(this->_taille > 2)
    {
        std::cout << *this;
        Noeud<T>* p1 = NoeudA(p_indice - 1);
        Noeud<T>* p2 = NoeudA(p_indice);
        //Ce constructeur est construit de telle sorte que p1 pointe vers l'objet en
        //cours de création et l'objet en cours de création pointe vers p2
        Noeud<T>* nouvelle = new Noeud<T>(p_element,p1,p2);
    }
    this->_taille++;
}
template<typename T>
void ListeChainee<T>::SupprimerFin()
{
    if (this->_taille == 0)
    {
        throw std::exception();
    }
    Noeud<T>* avantDernier = this->_premier;
    while (avantDernier->_suivant->_suivant != nullptr)
    {
        avantDernier = avantDernier->_suivant;
    }
    avantDernier->_suivant = nullptr;
    delete this->_dernier;
    this->_dernier = avantDernier;
    this->_taille--;
}
template<typename T>
void ListeChainee<T>::SupprimerDebut()
{
    if (this->_taille == 0)
    {
        throw std::exception();
    }
    if (this->_taille == 1) 
    {
        delete this->_premier;
        this->_premier = nullptr;
    }
    else
    {
        Noeud<T>* deuxieme = this->_premier->_suivant;
        delete this->_premier;
        this->_premier = deuxieme;
    }
    this->_taille--;
}
template<typename T>
void ListeChainee<T>::SupprimerA(int p_indice)
{
    if (p_indice < 0 || p_indice > this->_taille - 1)
    {
        throw std::exception();
    }
    if (p_indice == 0 || this->_taille == 1)
    {
        SupprimerDebut();
    }
    else
    {
        Noeud<T>* p1 = this->_premier;
        Noeud<T>* p2 = this->_premier->_suivant;
        int i = 0;
        while (i < p_indice - 1)
        {
            p1 = p1->_suivant;
            p2 = p2->_suivant;
            i++;
        }
        p1->_suivant = p2->_suivant;
        delete p2;
        p2 = nullptr;
        this->_taille--;
    }
}
template<typename T>
inline T ListeChainee<T>::SupprimerAEtRenvoie(int p_indice)
{
    if (p_indice < 0 || p_indice > this->_taille - 1)
    {
        throw std::exception();
    }
    if (p_indice == 0 || this->_taille == 1)
    {
        T PourRetour = this->_premier->_valeur;
        SupprimerDebut();
        return PourRetour;
    }
    else
    {
        Noeud<T>* p1 = this->_premier;
        Noeud<T>* p2 = this->_premier->_suivant;
        int i = 0;
        while (i < p_indice - 1)
        {
            p1 = p1->_suivant;
            p2 = p2->_suivant;
            i++;
        }
        p1->_suivant = p2->_suivant;
        T PourRetour = p2->_valeur;
        delete p2;
        p2 = nullptr;
        this->_taille--;
        return PourRetour;
    }
}
template<typename T>
inline void ListeChainee<T>::Vider(int p_taille)
{
    if (this->_taille > 0)
    {
        SupprimerDebut();
        Vider(p_taille - 1);
    }
}
template<typename T>
void ListeChainee<T>::Vider()
{
    //while (this->_taille > 0)
    //{
    //    SupprimerDebut();
    //}
    Vider(this->_taille);
}
template<typename T>
void ListeChainee<T>::parcourir(void(*p_fonction)(const int&))
{
    int i = 0;
    while (i < this->_taille - 1)
    {
        p_fonction(i);
        i++;
    }
}

template<typename T>
void ListeChainee<T>::Echanger(const int& p_element1, const int& p_element2)
{

    T temp = Obtenir(p_element2 + 1);
    Noeud<T>* p1 = NoeudA(p_element1);
    Noeud<T>* p2 = NoeudA(p_element2);
    p2->_valeur = p1->_valeur;
    p1->_valeur = temp;
}
template<typename T>
void ListeChainee<T>::Trier(bool(*p_fonctionTri)(const int&, const int&))
{
    int superlative;
    for (int i = 0; i < this->_taille - 1;i++)
    {
        superlative = i;
        for (int j = i + 1; j < this->_taille; ++j)
        {
            if (!(*p_fonctionTri)(Obtenir(superlative + 1), Obtenir(j + 1)))
            {
                superlative = j;
            }   
        }   
        Echanger(superlative, i);
    }
}
template<typename T>
void ListeChainee<T>::TrierAscendant()
{
    Noeud<T>* p1 = this->_premier;
    Noeud<T>* p2 = this->_premier;
    for (int i = 0; i < this->_taille - 1; i++)
    {
        for (int j = 0; j < this->_taille - i - 1; j++)
        {
            if (!(p1->_valeur < p1->_suivant->_valeur))
            {
                T temp = p1->_valeur;
                p1->_valeur = p1->_suivant->_valeur;
                p1->_suivant->_valeur = temp;
            }
            p1 = p1->_suivant;
        }
        p1 = this->_premier;
        p2 = p2->_suivant;
    }
}
template<typename T>
T ListeChainee<T>::Obtenir(int p_indice) 
{
    if (p_indice < 0 || p_indice > this->_taille - 1)
    {
        throw std::exception();
    }
    Noeud<T>* p = this->_premier;
    int i = 0;
    while (i < p_indice) 
    {
        p = p->_suivant;
        i++;
    }
    T val = p->_valeur;
    return val;
}
template<typename T>
inline bool ListeChainee<T>::operator==(const ListeChainee<T>& p_liste)
{
    bool resultat = true;
    if (this->_taille != p_liste._taille)
    {
        return false;
    }
    Noeud<T>* p1 = this->_premier;
    Noeud<T>* p2 = p_liste._premier;
    if (this->_taille != 0)
    {
        while (p1->_suivant->_suivant != nullptr)
        {
            if (p1->_valeur != p2->_valeur)
            {
                return false;
            }
            p1 = p1->_suivant;
            p2 = p2->_suivant;
        }
    }
    return resultat;
}
template<typename T>
inline bool ListeChainee<T>::operator!=(const ListeChainee<T>& p_liste)
{
    return false;
}
template<typename T>
ListeChainee<T>& ListeChainee<T>::operator=(const ListeChainee<T>& p_ancienneListe)
{
    std::cout << "copy assignment called" << std::endl;
    Noeud<T>* p = p_ancienneListe._premier;
    //if (*this != p_ancienneListe)
    //{
        Vider();
        int i = 0;
        while (i < p_ancienneListe._taille)
        {
            AjouterFin(p->_valeur);
            p = p->_suivant;
            i++;
        }
    //}
    return *this;
}
template<typename T>
ListeChainee<T>& ListeChainee<T>::operator=(ListeChainee<T>&& p_ancienneListe)
{
    std::cout << "move assignment called" << std::endl;
    if (*this != p_ancienneListe)
    {
        Vider();
        this->_premier = p_ancienneListe._premier;
        this->_dernier = p_ancienneListe._dernier;
        p_ancienneListe._premier = nullptr;
        p_ancienneListe._dernier = nullptr;
    }
    return *this;
}
template<typename T>
void ListeChainee<T>::SupprimerNoeud(Noeud<T>* p_anterior, Noeud<T>* p_noeud)
{
    if (p_anterior == nullptr)
    {
        delete this->_premier;
        this->_premier = p_noeud;
    }
    else if (p_noeud->_suivant == nullptr)
    {
        p_anterior->_suivant = nullptr;
        delete this->_dernier;
        this->_dernier = p_anterior;
    }
    else 
    {
        p_anterior->_suivant = p_noeud->_suivant;
        delete p_noeud;
    } 
}
template<typename T>
std::ostream& operator<<(std::ostream& p_cout,const ListeChainee<T>& p_liste)
{
    Noeud<T>* p = p_liste._premier;
    if (p == nullptr) 
    {
        p_cout << "{}" << std::endl;
    }
    else
    {
        p_cout << "taille : " << p_liste._taille;
        p_cout << "{";
        while (p->_suivant != nullptr)
        {
            p_cout << p->_valeur << " ->";
            p = p->_suivant;
        }
        p_cout << p->_valeur;
        p_cout << "}" << std::endl;
        return p_cout;
    }
}
template<typename T>
class ListeChainee<T>::Iterateur
{
private:
    Noeud<T>* _position;
public:
    Iterateur(Noeud<T>* p_nouvellePosition) : _position(p_nouvellePosition) {};
    Iterateur operator++() { this->_position = this->_position->_suivant; return *this; };
    T& operator*() { return this->_position->_valeur; };
    bool operator==(const Iterateur& p_position) { return this->_position == p_position._position; };
    bool operator!=(const Iterateur& p_position) { return this->_position != p_position._position; };
};



;
