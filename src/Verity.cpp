#include "Verity.h"

Verity::Verity(Statue s1, Statue s2, Statue s3)
:
m_leftOut(s1),
m_middleOut(s2),
m_rightOut(s3)
{
}

void Verity::compareStatues(Statue * main, Statue * s1, position_t mainPos, position_t s1Pos)
{
    main->m_complete = main->isComplete();
    s1->m_complete = s1->isComplete();

    if (main->m_complete || s1->m_complete)
    {
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 && main->needs[i] != NONE; j++)
        {
            if (s1->isHolding(main->needs[i]))
            {
                shape_t toSwap = main->getError();

                main->changeShape(main->needs[i], toSwap);
                s1->changeShape(toSwap, main->needs[i]);

                std::ostringstream oss;
                oss << "Place " << m_shapeMap[toSwap] 
                    << " on " << m_positionMap[mainPos] 
                    << " and " << m_shapeMap[main->needs[i]]
                    << " on " << m_positionMap[s1Pos] << "\n";

                m_output += oss.str();

                if (s1->isNeeded(toSwap))
                {
                    s1->needs[s1->getNeededIndex(toSwap)] = NONE;
                    s1->errors[s1->getErrorIndex(main->needs[i])] = NONE;
                } else
                {
                    s1->errors[s1->getErrorIndex(main->needs[i])] = toSwap;
                }

                main->errors[main->getErrorIndex(toSwap)] = NONE;
                main->needs[main->getNeededIndex(main->needs[i])] = NONE;
            }
        }
    }
}

bool Verity::shapeCheck()
{
    int tCount = 0;
    int sCount = 0;
    int cCount = 0;

    // Check left
    for (int i = 0; i < 2; i++)
    {
        if (m_leftOut.has[i] == TRIANGLE)
        {
            tCount++;
        } else if (m_leftOut.has[i] == SQUARE)
        {
            sCount++;
        } else if (m_leftOut.has[i] == CIRCLE)
        {
            cCount++;
        }
    }

    // Check middle
    for (int i = 0; i < 2; i++)
    {
        if (m_middleOut.has[i] == TRIANGLE)
        {
            tCount++;
        } else if (m_middleOut.has[i] == SQUARE)
        {
            sCount++;
        } else if (m_middleOut.has[i] == CIRCLE)
        {
            cCount++;
        }
    }

    // Check right
    for (int i = 0; i < 2; i++)
    {
        if (m_rightOut.has[i] == TRIANGLE)
        {
            tCount++;
        } else if (m_rightOut.has[i] == SQUARE)
        {
            sCount++;
        } else if (m_rightOut.has[i] == CIRCLE)
        {
            cCount++;
        }
    }

    if (tCount != 2 || sCount != 2 || cCount != 2)
    {
        return false;
    }

    return true;
}

Statue Verity::getStatue(position_t index)
{
    switch (index)
    {
        case LEFT:
            return m_leftOut;
            break;
        case MIDDLE:
            return m_middleOut;
            break;
        case RIGHT:
            return m_rightOut;
            break;
    }
}

std::string Verity::calculate()
{
    if (!shapeCheck())
    {
        return "ERROR: Unsolvable\n";
    }

    m_output = "";

    compareStatues(&m_leftOut, &m_middleOut, LEFT, MIDDLE);
    compareStatues(&m_leftOut, &m_rightOut, LEFT, RIGHT);
    compareStatues(&m_middleOut, &m_leftOut, MIDDLE, LEFT);
    compareStatues(&m_middleOut, &m_rightOut, MIDDLE, RIGHT);
    compareStatues(&m_rightOut, &m_leftOut, RIGHT, LEFT);
    compareStatues(&m_rightOut, &m_middleOut, RIGHT, MIDDLE);

    return m_output;
}
