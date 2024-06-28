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

    void compareStatues(Statue * main, Statue * s1);

public:
    Verity(Statue s1, Statue s2, Statue s3);

    Statue getStatue(position_t index);

    std::string calculate();
};
