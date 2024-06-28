#include "Verity.h"

Verity::Verity(Statue outsideCallouts[3])
:
m_leftOut(outsideCallouts[0]),
m_middleOut(outsideCallouts[1]),
m_rightOut(outsideCallouts[2])
{
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
    return "";
}
