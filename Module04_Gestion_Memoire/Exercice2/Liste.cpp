#include "Liste.h"

template <class T>
Liste<T>::Liste() :
	m_valeurs(new int[1]), m_nbElements(0), m_capacite(1)
{
}

template<class T>
Liste<T>::Liste(const Liste& p_listeAncienne):
	m_valeurs(nullptr), m_capacite(p_listeAncienne.m_capacite), m_nbElements(p_listeAncienne.m_nbElements)
{
	this->m_valeurs = new int[this->m_capacite];
	for (int i = 0;i < this->m_nbElements;i++)
	{
		this->m_valeurs[i] = p_listeAncienne.m_valeurs[i];
	}
	//std::copy(p_listeAncienne.m_valeurs, p_listeAncienne.m_valeurs.nbElements, this->m_valeurs);
}

template<class T>
Liste<T>::Liste(Liste&& p_listeAncienne):
	m_valeurs(p_listeAncienne.m_valeurs),m_capacite(p_listeAncienne.m_capacite), m_nbElements(p_listeAncienne.m_nbElements)
{
	p_listeAncienne.m_valeurs = nullptr;
}

template<class T>
Liste<T>::~Liste()
{
	if (this->m_valeurs)
	{
		delete[] this->m_valeurs;
		m_valeurs = nullptr;
	}
}

template<class T>
Liste<T>& Liste<T>::operator=(const Liste<T>& p_listeAncienne)
{
	if (this != p_listeAncienne)
	{
		if (this->m_capacite < p_listeAncienne.Capacite)
		{
			int* nouveauxValeurs = new int[p_listeAncienne.Capacite];
			delete[] this->m_valeurs;
			this->m_valeurs = nouveauxValeurs;
			this->Capacite = p_listeAncienne.Capacite;
		}
		for (int i = 0;i < p_listeAncienne.m_nbElements;i++)
		{
			this->m_valeurs[i] = p_listeAncienne[i];
		}
		//std::copy(p_listeAncienne,p_listeAncienne.m_nbElements,m_valeurs);
		this->m_nbElements = p_listeAncienne.m_nbElements;
	}
	return *this;
}

template<class T>
Liste<T>& Liste<T>::operator=(Liste<T>&& p_listeAncienne)
{
	if (this != p_listeAncienne)
	{
		delete[] this->m_valeurs;
		this->m_valeurs = p_listeAncienne.m_valeurs;
		this->m_capacite = p_listeAncienne.m_capacite;
		this->m_nbElements = p_listeAncienne.m_nbElements;
		p_listeAncienne.m_valeurs = nullptr;
		p_listeAncienne.m_capacite = 0;
		p_listeAncienne.m_nbElements = 0;
	}
	return *this;
}

template<class T>
void Liste<T>::AjouterFin(const T& p_valeur)
{
	if (this->m_nbElements == this->m_capacite) 
	{
		int nouvelleCapacite = this->m_capacite * 2;
		int nouveauxValeurs = new int[nouvelleCapacite];
		for (int i = 0;i < this->m_nbElements;i++)
		{
			nouveauxValeurs[i] = this->m_valeurs[i];
		}
		delete[] this->m_valeurs;
		this->m_valeurs = nouveauxValeurs;
		this->m_capacite = nouvelleCapacite;
	}
	this->m_nbElements++;
	this->m_valeurs[m_nbElements] = p_valeur;
}

template<class T>
void Liste<T>::SupprimerFin()
{
	this->m_nbElements--;
}

template<class T>
T Liste<T>::Obtenir(const int& p_indice)
{
	return this->m_valeurs[p_indice];
}

template<class T>
int Liste<T>::NombreElements() const
{
	return this->m_nbElements;
}

template<class T>
int Liste<T>::Capacite() const
{
	return this->m_capacite;
}

template<class T>
void Liste<T>::Parcourir(void(*p_fonction(const int&)))
{
	for (size_t i = 0; i < this->m_nbElements; i++)
	{
		p_fonction(this->m_valeurs[i]);
	}
}
