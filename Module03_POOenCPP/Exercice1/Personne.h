#pragma once
#include <string>

class Personne
{
public:
	Personne();
	~Personne();
	void GetNom(std::string p_nom);
	void SetNom(std::string p_nom);
	void GetPrenom(std::string p_prenom);
	void SetPrenom(std::string p_prenom);
	void GetAge(int p_age);
	void SetAge(int p_age);

private:
	//Personne* ptdata;
	std::string nom;
	std::string prenom;
	int age;
	float taille;
};

