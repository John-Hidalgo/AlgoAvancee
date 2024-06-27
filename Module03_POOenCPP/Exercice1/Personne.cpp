#include <iostream>
#include <stdexcept>

#include "Personne.h"

Personne::Personne():
nom(""),prenom("")
{
	//ptdata = new Personne(sizeof(Personne));
}

Personne::~Personne()
{
	//if (this->ptdata)
	//{
	//	delete this->ptdata;
	//	this->ptdata = nullptr;
	//}
}

void Personne::GetNom(std::string p_nom)
{
}

void Personne::SetNom(std::string p_nom)
{
}

void Personne::GetPrenom(std::string p_prenom)
{
}

void Personne::SetPrenom(std::string p_prenom)
{
}

void Personne::GetAge(int p_age)
{
}

void Personne::SetAge(int p_age)
{
}
