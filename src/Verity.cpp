#include "Verity.h"

Verity::Verity(Statue outsideCallouts[3], shape_t insideCallouts[3])
:
m_leftOut(outsideCallouts[0]),
m_middleOut(outsideCallouts[1]),
m_rightOut(outsideCallouts[2]),
m_leftIn(insideCallouts[0]),
m_middleIn(insideCallouts[1]),
m_rightIn(insideCallouts[2])
{
}

shape_t Verity::getInsideCallout(position_t index)
{
    switch (index)
    {
        case LEFT:
            return m_leftIn;
            break;
        case MIDDLE:
            return m_middleIn;
            break;
        case RIGHT:
            return m_rightIn;
            break;
    }
}

Statue Verity::getOutsideCallout(position_t index)
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
    return "";
}
