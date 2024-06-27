#pragma once
#include <iostream>
#include <exception>

template<typename T>
class Liste
{
public:
    Liste();
    Liste(const Liste&);
    Liste(Liste&&);
    ~Liste();

    void Ajouter(const T&);
    void Inserer(const int&, const T&);
    void Supprimer();
    void Retirer(const int&);

    void operator+(const T&);
    Liste& operator+(const Liste&);
    bool operator==(const Liste&);
    bool operator!=(const Liste&);
    void operator~();
    T& operator[](const int&);
    Liste& operator=(const Liste&);
    Liste& operator=(Liste&&);
    template<typename T>
    friend std::ostream& operator<<(std::ostream&, const Liste<T>&);

    int TrouveTaille() const;

private:
    int _capacite;
    int _taille;
    T* _valeurs;
    T* CopierTableau();
    void CopierTableau(Liste<T> p_tab);
    void AgrandirTableau();
    void AgrandirTableau(Liste<T>);
    void PousserValeursDroite(const int);
    void PousserValeursGauche(const int);
};


template<typename T>
T* Liste<T>::CopierTableau()
{
    T* copie = new T[this->_capacite];
    for (size_t i = 0;i < this->_taille;i++)
    {
        copie[i] = this->_valeurs[i];
    }
    return copie;
};

template<typename T>
void Liste<T>::CopierTableau(Liste<T> p_Liste)
{
    delete[] this->_valeurs;
    this->_valeurs = new T[p_Liste._capacite];
    for (size_t i = 0;i < this->_taille;i++)
    {
        this->_valeurs[i] = p_Liste._valeurs[i];
    }
};
template<typename T>
void Liste<T>::AgrandirTableau()
{
    this->_capacite *= 2;
    T* nouvelle = CopierTableau();
    delete[] this->_valeurs;
    this->_valeurs = nouvelle;
}
template<typename T>
inline void Liste<T>::AgrandirTableau(Liste<T> p_liste)
{
    this->_capacite = p_liste._capacite;
    T* nouvelle = CopierTableau(p_liste);
    delete[] this->_valeurs;
    this->_valeurs = nouvelle;
}
template<typename T>
void Liste<T>::PousserValeursDroite(const int p_indice)
{
    for (int i = this->_taille - 2;i > p_indice - 1;i--)
    {
        this->_valeurs[i + 1] = this->_valeurs[i];
        //std::cout << *this;
    }
}
template<typename T>
void Liste<T>::PousserValeursGauche(const int p_indice)
{
    for (int i = p_indice; i < this->_taille + 1; i++)
    {
        this->_valeurs[i] = this->_valeurs[i + 1];
    }
}

template<typename T>
void Liste<T>::Ajouter(const T& p_valeur)
{
    if (this->_taille == this->_capacite)
    {
        AgrandirTableau();
    }
    this->_valeurs[this->_taille] = p_valeur;
    this->_taille++;
}
template<typename T>
void Liste<T>::Inserer(const int& p_indice, const T& p_valeur)
{
    if (p_indice < 0 || p_indice > this->_taille)
    {
        throw std::invalid_argument(
            "L'index que vous avez dans votre paramètre est hors des limites du tableau.");
    }
    if (this->_taille == this->_capacite)
    {
        AgrandirTableau();
    }
    this->_taille++;
    PousserValeursDroite(p_indice);
    this->_valeurs[p_indice] = p_valeur;
}
template<typename T>
void Liste<T>::Supprimer()
{
    if (this->_taille == 0)
    {
        throw std::invalid_argument("La liste est vide");
    }
    this->_taille--;
}
template<typename T>
void Liste<T>::Retirer(const int& p_indice)
{
    if (p_indice < 0 || p_indice > this->_taille + 1)
    {
        throw std::invalid_argument(
            "L'index que vous avez dans votre paramètre est hors des limites du tableau.");
    }
    this->_taille--;
    PousserValeursGauche(p_indice);
}
template<typename T>
void Liste<T>::operator+(const T& p_element)
{
    Ajouter(p_element);
}
template<typename T>
Liste<T>& Liste<T>::operator+(const Liste& p_liste)
{
    for (int i = 0; i < p_liste._taille;i++)
    {
        Ajouter(p_liste._valeurs[i]);
    }
    return *this;
}
template<typename T>
bool Liste<T>::operator==(const Liste<T>& p_liste)
{
    bool verifier = true;
    for (int i = 0; i < p_liste._taille;i++)
    {        
        if (this->_valeurs[i] == p_liste._valeurs[i])
        {
            return false;
        }
    }
    return verifier;
}
template<typename T>
bool Liste<T>::operator!=(const Liste& p_liste)
{
    return true;
}
template<typename T>
void Liste<T>::operator~()
{
    int i = 0;
    int j = this->_taille - 1;
    while (i < j)
    {
        T temp = this->_valeurs[j];
        this->_valeurs[j] = this->_valeurs[i];
        this->_valeurs[i] = temp;
        i++;
        j--;
    }
}
template<typename T>
inline T& Liste<T>::operator[](const int& p_indice)
{
    return this->_valeurs[p_indice];
}
template<typename T>
Liste<T>& Liste<T>::operator=(const Liste& p_ancienneListe)
{
    if (*this != p_ancienneListe)
    {
        CopierTableau(p_ancienneListe);
        this->_capacite = p_ancienneListe._capacite;
        this->_taille = p_ancienneListe._taille;
    }
    return *this;
}

template<typename T>
Liste<T>& Liste<T>::operator=(Liste&& p_ancienneListe)
{
    this->_taille = p_ancienneListe._taille;
    if (this->_valeurs)
    {
        delete[] this->_valeurs;
    }
    this->_valeurs = p_ancienneListe._valeurs;
    p_ancienneListe._valeurs = nullptr;
    p_ancienneListe._capacite = 0;
    p_ancienneListe._taille = 0;

    return *this;
}

template<typename T>
int Liste<T>::TrouveTaille() const
{
    return this->_taille;
}

template<typename T>
std::ostream& operator<<(std::ostream& p_cout, const Liste<T>& p_liste)
{
    p_cout << "{";
    for (size_t i = 0;i < p_liste._taille - 1;i++)
    {
        p_cout << p_liste._valeurs[i] << ", ";
    }
    p_cout << p_liste._valeurs[p_liste._taille - 1] << "}" << std::endl;
    return p_cout;
}

template<typename T>
Liste<T>::Liste()
    :_capacite(1), _taille(0), _valeurs(new T[1])
{}
template<typename T>
Liste<T>::Liste(const Liste& p_ancienneListe)
    : _capacite(p_ancienneListe._capacite), _taille(p_ancienneListe._taille), _valeurs(nullptr)
{
    this->_valeurs = new T[p_ancienneListe._capacite];
    for (int i = 0; i < p_ancienneListe._taille;i++)
    {
        this->_valeurs[i] = p_ancienneListe._valeurs[i];
    }
}

template<typename T>
Liste<T>::Liste(Liste&& p_ancienneListe)
    :_capacite(p_ancienneListe._capacite), _taille(p_ancienneListe._taille), _valeurs(p_ancienneListe._valeurs)
{
    p_ancienneListe._capacite = 0;
    p_ancienneListe._taille = 0;
    p_ancienneListe._valeurs = nullptr;
}
template<typename T>
inline Liste<T>::~Liste()
{
    if (this->_valeurs) 
    {
        delete[] this->_valeurs;
        this->_valeurs = nullptr;
    }
}
;
