#pragma once

#include "Statue.h"

#include <cstdint>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

/*
*  Describes the position of the statue object
*/
typedef enum
{
    LEFT,
    MIDDLE,
    RIGHT
} position_t;

/*
* Implements the mechanics of the encounter and returns the needed instructions
*/
class Verity
{
private:

    // Left, right, and middle statues on the outside room
    Statue m_leftOut;
    Statue m_middleOut;
    Statue m_rightOut;

    // Maps for formatting the output strings for the calculate functions
    std::map<position_t, std::string> m_positionMap = {{LEFT, "LEFT"}, {MIDDLE, "MIDDLE"}, {RIGHT, "RIGHT"}};
    std::map<shape_t, std::string> m_shapeMap = {{TRIANGLE, "TRIANGLE"}, {SQUARE, "SQUARE"}, {CIRCLE, "CIRCLE"}};

    // Output for the calculate function
    std::string m_output = "";

    // Compares two statues and makes the necessary shape swaps
    void compareStatues(Statue * main, Statue * s1, position_t mainPos, position_t s1Pos);

    // Checks if the input is valid
    bool shapeCheck();

public:

    // Constructor that takes each statue from left to right
    Verity(Statue s1, Statue s2, Statue s3);

    // Returns a statue object from a given index
    Statue getStatue(position_t index);

    /*
    * Finds the solution to the encounter
    * Returns a string of the needed shape swaps
    */
    std::string calculate();
};
