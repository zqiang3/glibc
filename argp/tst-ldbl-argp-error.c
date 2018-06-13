#define ARGP_FUNCTION		argp_error
#define ARGP_FUNCTION_PARAMS	(state, "%Lf%f%Lf%f", (long double) -1, (double) -2, (long double) -3, (double) -4)
#include <tst-ldbl-argp-template.c>
