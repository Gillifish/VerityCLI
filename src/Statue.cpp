#include "Statue.h"

Statue::Statue(shape_t s1, shape_t s2, shape_t callout)
{
    m_has[0] = s1;
    m_has[1] = s2;
    m_callout = callout;

    void calcNeeds();
    void calcErrors();
}

void Statue::calcNeeds()
{
    int index = 0;

    switch (m_callout)
    {
    case TRIANGLE:
        if (!has(SQUARE))
        {
            m_needs[index] = SQUARE;
            index++;
        }

        if (!has(CIRCLE))
        {
            m_needs[index] = CIRCLE;
        }
        break;
    case SQUARE:
        if (!has(TRIANGLE))
        {
            m_needs[index] = TRIANGLE;
            index++;
        }

        if (!has(CIRCLE))
        {
            m_needs[index] = CIRCLE;
        }
        break;
    case CIRCLE:
        if (!has(SQUARE))
        {
            m_needs[index] = SQUARE;
            index++;
        }

        if (!has(TRIANGLE))
        {
            m_needs[index] = TRIANGLE;
        }
        break;
    }
}

void Statue::calcErrors()
{
    int index = 0;

    // Calculate errors for the callout shape
    for (shape_t s : m_has)
    {
        if (s == m_callout)
        {
            m_errors[index] = s;
            index++;
        }
    }

    // Calculate errors for dupe case
    if (hasDouble(TRIANGLE) && m_callout != TRIANGLE)
    {
        m_errors[index] = TRIANGLE;
    } else if (hasDouble(SQUARE) && m_callout != SQUARE)
    {
        m_errors[index] = SQUARE;
    } else if (hasDouble(CIRCLE) && m_callout != CIRCLE)
    {
        m_errors[index] = CIRCLE;
    }
}

bool Statue::has(shape_t shape)
{
    for (shape_t s : m_has)
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
    if (m_has[0] == shape && m_has[1] == shape)
    {
        return true;
    }

    return false;
}

bool Statue::needs(shape_t shape)
{
    if (m_needs[0] == shape || m_needs[1] == shape)
    {
        return true;
    }

    return false;
}

bool Statue::complete()
{
    return m_complete;
}