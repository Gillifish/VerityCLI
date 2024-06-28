#include "Verity.h"

int main (int argc, char *argv[]) 
{
    Statue s1 = Statue(SQUARE, SQUARE, SQUARE);
    Statue s2 = Statue(CIRCLE, CIRCLE, CIRCLE);
    Statue s3 = Statue(TRIANGLE, TRIANGLE, TRIANGLE);

    Verity v(s1, s2, s3);

    std::cout << v.calculate() << std::endl;

    return 0;
}