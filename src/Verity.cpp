#include "Verity.h"

Verity::Verity(Statue s1, Statue s2, Statue s3)
:
m_leftOut(s1),
m_middleOut(s2),
m_rightOut(s3)
{
}

void Verity::compareStatues(Statue * main, Statue * s1)
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
    m_leftOut.printHas();
    m_middleOut.printHas();
    m_rightOut.printHas();

    compareStatues(&m_leftOut, &m_middleOut);
    compareStatues(&m_leftOut, &m_rightOut);
    compareStatues(&m_middleOut, &m_leftOut);
    compareStatues(&m_middleOut, &m_rightOut);
    compareStatues(&m_rightOut, &m_leftOut);
    compareStatues(&m_rightOut, &m_middleOut);

    m_leftOut.printHas();
    m_middleOut.printHas();
    m_rightOut.printHas();

    return "";
}
