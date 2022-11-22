#include "recursive_descent.h"

int main()
{
    double value = recursiveDescent("log(log(16))");
    printf("%lg", value);
    return 0;
}
