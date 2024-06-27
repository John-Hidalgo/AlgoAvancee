#pragma once
#include <algorithm>
#include <iostream>
class ListEntiers 
{
public:
	ListEntiers();
	ListEntiers(const ListEntiers& p_ancienneListe);
	ListEntiers(ListEntiers&& p_ancienneListe);

	void Ajouter(const int& p_valeur)
	{
		if (this->_capacite == this->_taille) 
		{
			AgrandirTableau();
		}
		//this->_valeurs[this->_taille++] = p_valeur;
		this->_valeurs[this->_taille] = p_valeur;
		this->_taille++;
	};
	void Supprimer()
	{
		if (this->_taille == 0) 
		{
			//throw std::invalid_argument("Impossible de supprimer le dernier element");
		}
		this->_taille--;
	};
	int Obtenir(const int& p_indice)
	{
		return this->_valeurs[p_indice];
	};
	void Inserer(const int& p_indice, const int& p_valeur);
	void operator+(const int& p_element);
	void operator+=(const int& p_element);
	void operator+(const ListEntiers& p_liste);
	void operator+=(const ListEntiers& p_liste);
	//int operator[](const int& p_indice);
	int& operator[](const int p_indice);
	void operator~();
	friend std::ostream& operator<<(std::ostream& p_cout, const ListEntiers& p_liste);

private: 
	int _capacite;
	int _taille;
	int* _valeurs;
	void AgrandirTableau();
};
