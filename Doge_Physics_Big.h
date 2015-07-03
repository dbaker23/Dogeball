#pragma once
#include "Component_Doge_Physics.h"

class Doge_Physics_Big : public Component_Doge_Physics
{
public:
    /*=====================================================
    *Constructor: set speed to big speed

    *Parameters:
    =======================================================*/
    Doge_Physics_Big( Doge& doge );
    ~Doge_Physics_Big();

};

