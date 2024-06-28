#pragma once

// Shapes
enum shape_t
{
    NONE = -1,
    TRIANGLE = 0,
    SQUARE = 1,
    CIRCLE = 2
};

/*
* Class that represents the statues for the Verity encounter
*/
class Statue
{
private:
    // Calculates what the statue needs and puts it in the needs array
    void calcNeeds();

    // Calculates what the statue does not need and puts it in the errors array
    void calcErrors();

public:

    // Arrays to hold need, error, and holding shapes
    shape_t has[2] = {NONE, NONE};
    shape_t needs[2] = {NONE, NONE};
    shape_t errors[2] = {NONE, NONE};

    // Callout shape for the statue
    shape_t m_callout;

    // Variable for if the statue is complete and should not be changed
    bool complete = false;

    // Contructor that takes the shapes the statue is holding and the corresponding inside callout
    Statue(shape_t s1, shape_t s2, shape_t callout);

    // Returns true if the given shape is being held by the statue
    bool isHolding(shape_t s);

    // Returns true if the statue is holding two of the same shape
    bool hasDouble(shape_t s);

    // Returns true if the given shape is needed
    bool isNeeded(shape_t s);

    // Returns true if the shape is complete
    bool isComplete();

    // Changes a shape being held to another shape
    void changeShape(shape_t to, shape_t from);

    // Returns a shape that is not needed
    shape_t getError();

    // Returns the index of an unneeded shape
    int getErrorIndex(shape_t shape);

    // Returns the index of a needed shape
    int getNeededIndex(shape_t shape);
};