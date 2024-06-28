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
    if (has[0] != m_callout && has[1] != m_callout && has[0] != has[1])
    {
        return true;
    }

    return false;
}

void Statue::changeShape(shape_t to, shape_t from)
{
    for (int i = 0; i < 2; i++)
    {
        if (has[i] == from)
        {
            has[i] = to;
            m_complete = isComplete();

            return;
        }
    }
}

shape_t Statue::getError()
{
    for (int i = 0; i < 2; i++)
    {
        if (errors[i] != NONE)
        {
            return errors[i];
        }
    }

    return NONE;
}

int Statue::getErrorIndex(shape_t shape)
{
    for (int i = 0; i < 2; i++)
    {
        if (errors[i] == shape)
        {
            return i;
        }
    }

    return -1;
}

int Statue::getNeededIndex(shape_t shape)
{
    for (int i = 0; i < 2; i++)
    {
        if (needs[i] == shape)
        {
            return i;
        }
    }

    return -1;
}

// Debug

void Statue::printHas()
{
    printf("Has\n");
    printf("%d |", has[0]);
    printf(" %d\n", has[1]);
}

void Statue::printNeeds()
{
    printf("Needs\n");
    printf("%d |", needs[0]);
    printf(" %d\n", needs[1]);
}

void Statue::printErrors()
{
    printf("Errors\n");
    printf("%d |", errors[0]);
    printf(" %d\n", errors[1]);
}