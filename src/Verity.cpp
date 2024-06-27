#include "Verity.h"

Verity::Verity(statue_t outsideCallouts[3], shape_t insideCallouts[3])
{
    setOutsideCallouts(outsideCallouts[0], outsideCallouts[1], outsideCallouts[2]);
    setInsideCallouts(insideCallouts[0], insideCallouts[1], insideCallouts[2]);

    evalStatues();
}

void Verity::setInsideCallouts(shape_t left, shape_t middle, shape_t right)
{
    m_leftIn = left;
    m_middleIn = middle;
    m_rightIn = middle;
}

void Verity::setOutsideCallouts(statue_t left, statue_t middle, statue_t right)
{
    m_leftOut = left;
    m_middleOut = middle;
    m_rightOut = right;
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

statue_t Verity::getOutsideCallout(position_t index)
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

void Verity::evalStatues()
{
    // Evaluate left statue

    // Evaluate middle statue

    // Evaluate right statue
}

std::string Verity::calculate()
{
    return "";
}
