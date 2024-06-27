#pragma once
#include "IRonde.h"
#include <random>
#include <chrono>
class RondeOrd :public IRonde
{
public:
    RondeOrd();
    int IRonde::JouerRonde(int p_coups);
    void FaireCodeParOrdinateur();

};

