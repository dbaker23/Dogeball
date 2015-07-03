#pragma once
#include "Component_Doge_Physics.h"

class Doge_Physics_Arr : public Component_Doge_Physics
{
public:
    /*=====================================================
    *Constructor: set speed to arrow speed

    *Parameters:
    =======================================================*/
    Doge_Physics_Arr( Doge& doge );
    ~Doge_Physics_Arr();
};

