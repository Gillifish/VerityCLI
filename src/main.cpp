#include "Verity.h"

int main (int argc, char *argv[]) 
{
    Statue s1 = Statue(TRIANGLE, SQUARE, SQUARE);
    Statue s2 = Statue(TRIANGLE, CIRCLE, CIRCLE);
    Statue s3 = Statue(SQUARE, CIRCLE, TRIANGLE);

    bool s1Done = s1.isComplete();
    bool s2Done = s2.isComplete();
    bool s3Done = s3.isComplete();

    s1.printHas();
    s2.printHas();
    s3.printHas();

    // Evaluate left statue

    for (int i = 0; i < 2 && !s1Done; i++)
    {
        // Check middle statue
        if (s2.isHolding(s1.needs[i]) && s2.isNeeded(s1.errors[i]) && !s2Done)
        {
            // Swap
            shape_t swap1 = s1.errors[i];
            shape_t swap2 = s1.needs[i];

            s1.changeShape(swap2, swap1);
            s2.changeShape(swap1, swap2);

            s1.needs[i] = NONE;
            s2.errors[i] = NONE;

            // Log

            // Update completion
            s1Done = s1.isComplete();
            s2Done = s2.isComplete();
        }

        // Check right statue
        if (s3.isHolding(s1.needs[i]) && s2.isNeeded(s1.errors[i]) && !s2Done)
        {
            // Swap
            shape_t swap1 = s1.errors[i];
            shape_t swap2 = s1.needs[i];

            s1.changeShape(swap2, swap1);
            s2.changeShape(swap1, swap2);

            s1.needs[i] = NONE;
            s2.errors[i] = NONE;

            // Log

            // Update completion
            s1Done = s1.isComplete();
            s2Done = s2.isComplete();
        }
    }

    s1.printHas();
    s2.printHas();
    s3.printHas();

    return 0;
}
