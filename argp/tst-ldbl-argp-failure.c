#define ARGP_FUNCTION		argp_failure
#define ARGP_FUNCTION_PARAMS	(state, 0, 0, "%Lf%f%Lf%f", (long double) -1, (double) -2, (long double) -3, (double) -4)
#include <tst-ldbl-argp-template.c>
