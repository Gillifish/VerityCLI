#pragma once

typedef enum 
{
    NONE,
    TRIANGLE,
    SQUARE,
    CIRCLE,
    SPHERE,
    CUBE,
    PRISM,
    CYLINDER,
    CONE,
    PYRAMID
} shape_t;

class Statue
{
private:
    shape_t m_has[2];
    shape_t m_needs[2];
    shape_t m_errors[2];
    int m_needsLength = 0;
    int m_errorsLength = 0;
    shape_t m_callout;
    bool m_complete = false;

    void calcNeeds();
    void calcErrors();

public:
    Statue(shape_t s1, shape_t s2, shape_t callout);

    bool has(shape_t s);
    bool hasDouble(shape_t s);
    bool needs(shape_t s);
    shape_t * getNeeds();
    shape_t * getErrors();
    bool complete();
};