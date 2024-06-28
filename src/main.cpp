#include "Verity.h"

int main (int argc, char *argv[]) 
{
    Statue s1 = Statue(TRIANGLE, SQUARE, TRIANGLE);

    //s1.evaluate();

    s1.printHas();
    s1.printNeeds();
    s1.printErrors();

    return 0;
}
