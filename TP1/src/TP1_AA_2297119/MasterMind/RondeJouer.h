#pragma once
#include "IRonde.h"
class RondeJouer :public IRonde
{
public:
    RondeJouer();
    int IRonde::JouerRonde(int p_coups);
};
