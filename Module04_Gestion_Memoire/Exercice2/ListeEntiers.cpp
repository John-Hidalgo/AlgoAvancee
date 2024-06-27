#include <iostream>
#include <stdexcept>

#include "ListeEntiers.h"

ListeEntiers::ListeEntiers():
	m_valeurs (new int[1]),
	m_capacite(1),
	m_nbElements(0)
{

}
ListeEntiers::ListeEntiers(const ListeEntiers& p_listeACopier) :
	m_valeurs(nullptr),
	m_capacite(p_listeACopier.m_capacite),
	m_nbElements(p_listeACopier.m_nbElements)
{
	this->m_valeurs = new int[this->m_nbElements];
	for (int i = 0; i < this->m_nbElements;i++)
	{
		this->m_valeurs[i] = p_listeACopier.m_valeurs[i];
	}
}
ListeEntiers::ListeEntiers(ListeEntiers&& p_listeADeplacer) : 
	m_valeurs(p_listeADeplacer.m_valeurs),
	m_capacite(p_listeADeplacer.m_capacite),
	m_nbElements(p_listeADeplacer.m_nbElements)
{
	p_listeADeplacer.m_valeurs = nullptr;
}
ListeEntiers::~ListeEntiers() 
{
	if (this->m_valeurs)
	{
		delete[] m_valeurs;
		this->m_valeurs = nullptr;
	}	
}
void ListeEntiers::ajouterFin(const int& p_valeur)
{

}
ListeEntiers& ListeEntiers::operator=(const ListeEntiers& p_listeACopier)
{
	if (this != &p_listeACopier)
	{
		delete[] this->m_valeurs;
		this->m_valeurs = new int[p_listeACopier.m_capacite];
	}
	return *this;
}

ListeEntiers& ListeEntiers::operator=(ListeEntiers&& p_listeADeplacer)
{
	if (this != &p_listeADeplacer)
	{

	}
	return *this;
}
