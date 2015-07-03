#pragma once
#include "Component_Doge_Physics.h"

class Doge_Physics_Sml : public Component_Doge_Physics
{
public:
    /*=====================================================
    *Constructor: set speed to small speed

    *Parameters:
    =======================================================*/
    Doge_Physics_Sml( Doge& doge );
    ~Doge_Physics_Sml();
};

