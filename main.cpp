#include "recursive_descent.h"

int main()
{
    double value = recursiveDescent("3+(4*5-5/3)*3");
    printf("%lg", value);
    return 0;
}
