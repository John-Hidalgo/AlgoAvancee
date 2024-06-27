#pragma once
#include "Liste.h"

class IAfficher
{
public:
	virtual void Couleurs(const Liste<char> p_couleurs) = 0;
	virtual void Couleurs(const Liste<int> p_couleurs) = 0;
	virtual void Choix() = 0;
};

