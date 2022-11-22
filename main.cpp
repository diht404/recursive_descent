#include "recursive_descent.h"

int main()
{
    double value = recursiveDescent("cos(314/100)");
    printf("%lg", value);
    return 0;
}
