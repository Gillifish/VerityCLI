#include "Statue.h"

Statue::Statue(shape_t s1, shape_t s2, shape_t callout)
{
    has[0] = s1;
    has[1] = s2;
    m_callout = callout;

    calcNeeds();
    calcErrors();
}

void Statue::calcNeeds()
{
    int index = 0;

    switch (m_callout)
    {
    case TRIANGLE:
        if (!isHolding(SQUARE))
        {
            needs[index] = SQUARE;
            index++;
        }

        if (!isHolding(CIRCLE))
        {
            needs[index] = CIRCLE;
        }
        break;
    case SQUARE:
        if (!isHolding(TRIANGLE))
        {
            needs[index] = TRIANGLE;
            index++;
        }

        if (!isHolding(CIRCLE))
        {
            needs[index] = CIRCLE;
        }
        break;
    case CIRCLE:
        if (!isHolding(SQUARE))
        {
            needs[index] = SQUARE;
            index++;
        }

        if (!isHolding(TRIANGLE))
        {
            needs[index] = TRIANGLE;
        }
        break;
    // To make the compiler happy
    case NONE:
        break;
    }
}

void Statue::calcErrors()
{
    int index = 0;

    // Calculate errors for the callout shape
    for (int i = 0; i < 2; i++)
    {
        if (has[i] == m_callout)
        {
            errors[index] = has[i];
            index++;
        }
    }

    // Calculate errors for dupe case
    if (hasDouble(TRIANGLE) && m_callout != TRIANGLE)
    {
        errors[index] = TRIANGLE;
    } else if (hasDouble(SQUARE) && m_callout != SQUARE)
    {
        errors[index] = SQUARE;
    } else if (hasDouble(CIRCLE) && m_callout != CIRCLE)
    {
        errors[index] = CIRCLE;
    }
}

bool Statue::isHolding(shape_t shape)
{
    for (shape_t s : has)
    {
        if (s == shape)
        {
            return true;
        }
    }

    return false;
}

bool Statue::hasDouble(shape_t shape)
{
    if (has[0] == shape && has[1] == shape)
    {
        return true;
    }

    return false;
}

bool Statue::isNeeded(shape_t shape)
{
    if (needs[0] == shape || needs[1] == shape)
    {
        return true;
    }

    return false;
}

bool Statue::isComplete()
{
    for (int i = 0; i < 2; i++)
    {
        if (needs[i] != -1 && errors[i] != -1)
        {
            return false;
        }
    }

    return true;
}

void Statue::changeShape(shape_t to, shape_t from)
{
    for (int i = 0; i < 2; i++)
    {
        if (has[i] == from)
        {
            has[i] = to;
        }
    }
}

// Debug

void Statue::printHas()
{
    printf("Statue\n");
    printf("%d |", has[0]);
    printf("%d\n", has[1]);
}

void Statue::printNeeds()
{
    printf("%d\n", needs[0]);
    printf("%d\n", needs[1]);
}

void Statue::printErrors()
{
    printf("%d\n", errors[0]);
    printf("%d\n", errors[1]);
}