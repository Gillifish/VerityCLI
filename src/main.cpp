#include "Verity.h"

int main (int argc, char *argv[]) 
{
    Statue s1 = Statue(CIRCLE, CIRCLE, CIRCLE);
    Statue s2 = Statue(TRIANGLE, TRIANGLE, TRIANGLE);
    Statue s3 = Statue(SQUARE, SQUARE, SQUARE);

    Verity v(s1, s2, s3);

    v.calculate();

    return 0;
}