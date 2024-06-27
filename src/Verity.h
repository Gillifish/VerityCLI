#pragma once

#include <cstdint>
#include <iostream>

typedef enum
{
    LEFT,
    MIDDLE,
    RIGHT
} position_t;

typedef enum 
{
    TRIANGLE,
    SQUARE,
    CIRCLE
} shape_t;

struct statue_t
{
    shape_t shape1;
    shape_t shape2;
    shape_t needs[2];
    shape_t dupes[2];
};

class Verity
{
private:
    statue_t m_leftOut;
    statue_t m_middleOut;
    statue_t m_rightOut;

    shape_t m_leftIn;
    shape_t m_middleIn;
    shape_t m_rightIn;

    void evalStatues();

public:
    Verity(statue_t outsideCallouts[3], shape_t insideCallouts[3]);
    
    void setOutsideCallouts(statue_t left, statue_t middle, statue_t right);
    void setInsideCallouts(shape_t left, shape_t middle, shape_t right);

    shape_t getInsideCallout(position_t index);
    statue_t getOutsideCallout(position_t index);

    std::string calculate();
};
