#pragma once

#include <iostream>

enum shape_t
{
    NONE = -1,
    TRIANGLE = 0,
    SQUARE = 1,
    CIRCLE = 2
};

class Statue
{
private:
    shape_t m_has[2] = {NONE, NONE};
    shape_t m_needs[2] = {NONE, NONE};
    shape_t m_errors[2] = {NONE, NONE};
    shape_t m_callout;
    bool m_complete = false;

    void calcNeeds();
    void calcErrors();

public:
    Statue(shape_t s1, shape_t s2, shape_t callout);

    bool has(shape_t s);
    bool hasDouble(shape_t s);
    bool needs(shape_t s);
    bool isComplete();
    void setNeeds(int index, shape_t shape);
    void setErrors(int index, shape_t shape);

    // Debug functions
    void printHas();
    void printNeeds();
    void printErrors();
};