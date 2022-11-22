#ifndef RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
#define RECURSIVE_DESCENT__RECURSIVE_DESCENT_H

#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "ctype.h"
#include "cmath"

double recursiveDescent(const char *program);

double getAddSub(const char **program);

double getMulDiv(const char **program);


double getPow(const char **program);

double getLog(const char **program);

double getSin(const char **program);

double getCos(const char **program);

double getBrackets(const char **program);

double getValue(const char **program);

#define ASSERT_OK(value, error, ...)                                \
        if (!(value))                                               \
        {                                                           \
            fprintf(stderr, "Error occured: " error, ##__VA_ARGS__);\
            abort();                                                \
        }

#endif //RECURSIVE_DESCENT__RECURSIVE_DESCENT_H
