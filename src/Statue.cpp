#include "Statue.h"

Statue::Statue(shape_t s1, shape_t s2, shape_t callout)
{
    m_has[0] = s1;
    m_has[1] = s2;
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
    // To make the compiler happy
    case NONE:
        break;
    }
}

void Statue::calcErrors()
{
    int index = 0;
    printf("Test\n");

    // Calculate errors for the callout shape
    for (int i = 0; i < 2; i++)
    {
        if (m_has[i] == m_callout)
        {
            printf("Hit\n");
            m_errors[index] = m_has[i];
            index++;
        }
    }

    // Calculate errors for dupe case
    if (hasDouble(TRIANGLE) && m_callout != TRIANGLE)
    {
        printf("Test1\n");
        m_errors[index] = TRIANGLE;
    } else if (hasDouble(SQUARE) && m_callout != SQUARE)
    {
        printf("Test2\n");
        m_errors[index] = SQUARE;
    } else if (hasDouble(CIRCLE) && m_callout != CIRCLE)
    {
        printf("Test3\n");
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

bool Statue::isComplete()
{
    return m_complete;
}

void Statue::setNeeds(int index, shape_t shape)
{
    if (index < 0 && index > 1)
    {
        return;
    }

    m_needs[index] = shape;
}

void Statue::setErrors(int index, shape_t shape)
{
    if (index < 0 && index > 1)
    {
        return;
    }
    
    m_errors[index] = shape;
}

void Statue::printHas()
{
    printf("%d\n", m_has[0]);
    printf("%d\n", m_has[1]);
}

void Statue::printNeeds()
{
    printf("%d\n", m_needs[0]);
    printf("%d\n", m_needs[1]);
}

void Statue::printErrors()
{
    printf("%d\n", m_errors[0]);
    printf("%d\n", m_errors[1]);
}