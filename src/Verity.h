#pragma once

#include <cstdint>
#include <iostream>
#include "Statue.h"

typedef enum
{
    LEFT,
    MIDDLE,
    RIGHT
} position_t;

class Verity
{
private:
    Statue m_leftOut;
    Statue m_middleOut;
    Statue m_rightOut;

public:
    Verity(Statue outsideCallouts[3]);

    Statue getStatue(position_t index);

    std::string calculate();
};
