#pragma once

#include <cstdint>
#include <iostream>
#include "Statue.h"
#include <map>
#include <sstream>
#include <string>

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

    std::map<position_t, std::string> m_positionMap = {{LEFT, "LEFT"}, {MIDDLE, "MIDDLE"}, {RIGHT, "RIGHT"}};
    std::map<shape_t, std::string> m_shapeMap = {{TRIANGLE, "TRIANGLE"}, {SQUARE, "SQUARE"}, {CIRCLE, "CIRCLE"}};

    std::string m_output = "";

    void compareStatues(Statue * main, Statue * s1, position_t mainPos, position_t s1Pos);
    bool shapeCheck();

public:
    Verity(Statue s1, Statue s2, Statue s3);

    Statue getStatue(position_t index);

    std::string calculate();
};
