#include <iostream>
#include <stdexcept>
//
#include "Liste.h"
// std:: ostringstream
Liste::Liste()
{
	this->m_nombreDElements = 0;
	//this->m_elements[20];
}
void Liste::Ajouter(int p_element) 
{
	if (m_nombreDElements > 20) 
	{
		throw std::invalid_argument("La liste est deja pleine");
	}
	int indice = this->m_nombreDElements;
	this->m_elements[indice] = p_element;
	m_nombreDElements++;
}
//void Liste::Supprimer(int p_indice)
//{
//	if (m_nombreDElements == 0)
//	{
//		throw std::invalid_argument("La liste est vide");
//	}
//	int indice = this->m_nombreDElements;
//	int longeur = 20 - m_nombreDElements;
//	for (int i = indice; i < longeur;i++)
//	{
//		this->m_elements[i] = this->m_elements[i + 1];
//	}
//	m_nombreDElements--;
//
//}
//int Liste::Obtenir(int p_index)
//{
//	if (p_index < this->m_nombreDElements - 1)
//	{
//		throw std::invalid_argument("La liste est vide");
//	}
//
//	return this->m_elements[p_index];
//}
//void Liste::Definir(int p_index, int p_element)
//{
//	if (p_index > 20) 
//	{
//		throw std::invalid_argument("La liste n'as pas ce index");
//	}
//
//}
int Liste::GetElementDuTableau(int p_index)
{
	return this->m_elements[p_index];
}