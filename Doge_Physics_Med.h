#pragma once
#include "Component_Doge_Physics.h"

class Doge_Physics_Med : public Component_Doge_Physics
{
public:
    /*=====================================================
    *Constructor: set speed to medium speed

    *Parameters:
    =======================================================*/
    Doge_Physics_Med( Doge& doge );
    ~Doge_Physics_Med();
};

