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

    shape_t m_leftIn;
    shape_t m_middleIn;
    shape_t m_rightIn;

public:
    Verity(Statue outsideCallouts[3], shape_t insideCallouts[3]);

    shape_t getInsideCallout(position_t index);
    Statue getOutsideCallout(position_t index);

    std::string calculate();
};
