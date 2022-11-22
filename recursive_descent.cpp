#include "recursive_descent.h"

double recursiveDescent(const char *program)
{
    assert(program != nullptr);

    double value = getAddSub(&program);

    ASSERT_OK(*program == '\0', "Incorrect symbol: _%c_\n", *program)

    return value;
}

double getAddSub(const char **program)
{
    assert(program != nullptr);
    assert(*program != nullptr);

    double leftValue = getMulDiv(program);

    while (**program == '+' || **program == '-')
    {
        char operation = **program;
        (*program)++;

        double rightValue = getMulDiv(program);
        if (operation == '+')
            leftValue += rightValue;
        else
            leftValue -= rightValue;
    }

    return leftValue;
}

double getMulDiv(const char **program)
{
    assert(program != nullptr);
    assert(*program != nullptr);

    double leftValue = getPow(program);

    while (**program == '*' || **program == '/')
    {
        char operation = **program;
        (*program)++;

        double rightValue = getPow(program);

        if (operation == '*')
            leftValue *= rightValue;
        else
            leftValue /= rightValue;
    }

    return leftValue;
}

double getBrackets(const char **program)
{
    assert(program != nullptr);
    assert(*program != nullptr);

    double value = 0;

    if (**program == '(')
    {
        (*program)++;

        value = getAddSub(program);
        ASSERT_OK(**program == ')',
                  "Expected ), but got _%c_\n",
                  **program)
        (*program)++;
    }
    else
        value = getValue(program);

    return value;
}

double getPow(const char **program)
{
    assert(program != nullptr);
    assert(*program != nullptr);

    double leftValue = getBrackets(program);
    double rightValue = NAN;

    while (**program == '^')
    {
        (*program)++;

        rightValue = getBrackets(program);
        leftValue = pow(leftValue, rightValue);
    }

    return leftValue;
}

double getValue(const char **program)
{
    assert(program != nullptr);
    assert(*program != nullptr);

    double value = 0;

    const char *startPtr = *program;

    while (isdigit(**program))
    {
        value = value * 10 + **program - '0';
        ++(*program);
    }

    ASSERT_OK(startPtr != *program,
              "incorrect digit: _%c_\n",
              **program)

    return value;
}