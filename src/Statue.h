#pragma once

#include <iostream>

enum shape_t
{
    NONE = -1,
    TRIANGLE = 0,
    SQUARE = 1,
    CIRCLE = 2
};

struct swap
{
    int index;
    shape_t shape;
};

class Statue
{
private:
    bool m_complete = false;

    void calcNeeds();
    void calcErrors();

public:
    shape_t has[2] = {NONE, NONE};
    shape_t needs[2] = {NONE, NONE};
    shape_t errors[2] = {NONE, NONE};
    shape_t m_callout;

    Statue(shape_t s1, shape_t s2, shape_t callout);

    bool isHolding(shape_t s);
    bool hasDouble(shape_t s);
    bool isNeeded(shape_t s);
    bool isComplete();
    void changeShape(shape_t to, shape_t from);

    // Debug functions
    void printHas();
    void printNeeds();
    void printErrors();
};