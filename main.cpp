#include "recursive_descent.h"

int main()
{
    double value = recursiveDescent("2^3^3+7");
    printf("%lg", value);
    return 0;
}
