#include "ListeEntiers.h"
int* CopierTableau(int p_taille,int* p_tab)
{ 
	int* copie = new int[p_taille];
	for (size_t i = 0;i < p_taille;i++) 
	{
		copie[i] = p_tab[i];
	}
	return copie;
};
void PousserDroit(int p_indice, int p_taille, int* p_valeurs)
{
	for (int i = p_taille - 2;i > p_indice - 1;i--)
	{
		p_valeurs[i + 1] = p_valeurs[i];
		//std::cout << *this;
	}
};
ListEntiers::ListEntiers()
	:_valeurs(new int[1]), _capacite(1), _taille(0)
{
}

ListEntiers::ListEntiers(const ListEntiers& p_ancienneListe)
	:_valeurs(nullptr), _capacite(p_ancienneListe._capacite), _taille(p_ancienneListe._taille)
{
	this->_valeurs = CopierTableau(this->_capacite,p_ancienneListe._valeurs);
}

ListEntiers::ListEntiers(ListEntiers&& p_ancienneListe) 
	:_valeurs(p_ancienneListe._valeurs),_capacite(p_ancienneListe._capacite),_taille(p_ancienneListe._taille)
{
	p_ancienneListe._valeurs = nullptr;
	p_ancienneListe._capacite = 0;
	p_ancienneListe._taille = 0;
}

void ListEntiers::Inserer(const int& p_indice,const int& p_valeur)
{
	if (this->_taille == this->_capacite) 
	{
		AgrandirTableau();
	}
	this->_taille++;
	PousserDroit(p_indice,this->_taille,this->_valeurs);
	this->_valeurs[p_indice] = p_valeur;
}

void ListEntiers::operator+(const int& p_element)
{
	Ajouter(p_element);
}

void ListEntiers::operator+=(const int& p_element)
{
	Ajouter(p_element);
}

void ListEntiers::operator+(const ListEntiers& p_liste)
{
	for (size_t i = 0;i < p_liste._taille;i++)
	{
		Ajouter(p_liste._valeurs[i]);
	}
}

void ListEntiers::operator+=(const ListEntiers& p_liste)
{
	for (size_t i = 0;i < p_liste._taille;i++)
	{
		Ajouter(p_liste._valeurs[i]);
	}
}

//int ListEntiers::operator[](const int& p_indice)
//{
//	return Obtenir(p_indice);
//}

int& ListEntiers::operator[](const int p_indice)
{
	return this->_valeurs[p_indice];
}

void ListEntiers::operator~()
{
	int i = 0;
	int j = this->_taille - 1;
	while (i < j)
	{
		int temp = this->_valeurs[j];//{1,2,3}
		this->_valeurs[j] = this->_valeurs[i];
		this->_valeurs[i] = temp;
		i++;
		j--;
	}
}

void ListEntiers::AgrandirTableau()
{
	this->_capacite *= 2;
	int* nouvelle = CopierTableau(this->_capacite, this->_valeurs);
	delete[] this->_valeurs;
	this->_valeurs = nouvelle;
}

std::ostream& operator<<(std::ostream& p_cout, const ListEntiers& p_liste)
{
	p_cout << "{";
	for (size_t i = 0;i < p_liste._taille - 1;i++)
	{
		p_cout << p_liste._valeurs[i] << ", ";
	}
	p_cout << p_liste._valeurs[p_liste._taille - 1] << "}" << std::endl;
	return p_cout;
}
