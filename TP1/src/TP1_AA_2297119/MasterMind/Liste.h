#pragma once
#include <iostream>
#include <string>
#include <exception>

template <class T>
class Liste
{
public:
	Liste() :
		m_valeurs(new T[1]), m_capacite(1), m_nbElements(0)
	{
	};
	Liste(const Liste& p_listeAncienne) :
		m_valeurs(nullptr), m_capacite(p_listeAncienne.m_capacite), m_nbElements(p_listeAncienne.m_nbElements)
	{
		this->m_valeurs = new T[this->m_capacite];
		for (int i = 0;i < this->m_nbElements;i++)
		{
			this->m_valeurs[i] = p_listeAncienne.m_valeurs[i];
		}
	};
	Liste(Liste&& p_listeAncienne) :
		m_valeurs(p_listeAncienne.m_valeurs), m_capacite(p_listeAncienne.m_capacite), m_nbElements(p_listeAncienne.m_nbElements)
	{
		p_listeAncienne.m_valeurs = nullptr;
		p_listeAncienne.m_capacite = 0;
		p_listeAncienne.m_nbElements = 0;
	};
	~Liste()
	{
		if (this->m_valeurs)
		{
			delete[] m_valeurs;
			this->m_valeurs = nullptr;
		}
	};
	void ajouterFin(const T& p_valeur)
	{
		if (this->m_nbElements == this->m_capacite)
		{
			int nouvelleCapacite = this->m_capacite *= 2;
			T* nouvelleListe = new T[nouvelleCapacite];
			for (int i = 0; i < this->m_nbElements;i++)
			{
				nouvelleListe[i] = this->m_valeurs[i];
			}
			delete[] this->m_valeurs;
			this->m_valeurs = nouvelleListe;
			this->m_capacite = nouvelleCapacite;
		}
		this->m_valeurs[this->m_nbElements++] = p_valeur;
	};
	void supprimerFin()
	{
		if (this->m_nbElements == 0) 
		{
			throw std::invalid_argument("Impossible de supprimer le dernier element");
		}
		--this->m_nbElements;
	};
	T obtenir(const int& p_indice)
	{
		if (p_indice >= this->m_nbElements || p_indice < 0)
		{
			throw std::invalid_argument("L'indice n'est pas valide");
		}

		return this->m_valeurs[p_indice];
	};
	void Affecter(const int& p_indice, T p_valeur)
	{
		if (p_indice >= this->m_nbElements || p_indice < 0)
		{
			throw std::invalid_argument("L'indice n'est pas valide");
		}
		this->m_couleurs[p_indice] = p_valeur;
	};
	void parcourir(void(*p_fonction(const int&)))
	{
		for (size_t indexValeur = 0; indexValeur < this->m_nbElements; indexValeur++)
		{
			p_fonction(this->m_valeurs[indexValeur]);
		}
	};
	void RemplirParChaine(const std::string& p_chaine)
	{
		for (int i = 0;i < p_chaine.size();i++)
		{
			ajouterFin(p_chaine[i]);
		}
	};
	bool TrouveAIndex(const int p_index, const T& p_valeur)
	{
		return true;
	};
	bool Contient(const T& p_valeur)
	{
		bool verifier = false;
		for (int i = 0;i < this->m_nbElements;i++)
		{
			if (this->m_valeurs[i] == p_valeur)
			{
				return true;
			}
		}
		return verifier;
	};
	Liste& operator=(const Liste& p_AncienneListe)
	{
		if (this != &p_AncienneListe)
		{
			if (this->m_capacite < p_AncienneListe.m_capacite) 
			{
				int* nouvellevaleurs = new int[p_AncienneListe.m_capacite];
				delete[] this->m_valeurs;
				this->m_capacite = p_AncienneListe.m_capacite;
				
			}
			for (int i = 0; i < p_AncienneListe.m_capacite;i++)
			{
				this->m_valeurs[i] = p_AncienneListe.m_valeurs[i];
			}
			this->m_nbElements = p_AncienneListe.m_nbElements;
		}
		return *this;
	};
	Liste& operator=(Liste&& p_AncienneListe) noexcept
	{
		if (this != p_AncienneListe)
		{
			this->m_nbElements = p_AncienneListe.m_nbElements;
			if (this->m_valeurs)
			{
				delete[] this->m_valeurs;
				this->m_valeurs = nullptr;
			}
			this->m_capacite = p_AncienneListe.m_capacite;
			this->m_valeurs = p_AncienneListe.m_valeurs;
		}
		return *this;
	};
	int nombreElements() const { return this->m_nbElements; };
	int capacite() const { return this->m_capacite; };
private:
	T* m_valeurs;
	int m_capacite;
	int m_nbElements;
};
