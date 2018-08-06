/* Test for the long double conversions in *warn* functions.
   Copyright (C) 2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <err.h>
#include <stdarg.h>

#include <support/check.h>

static void
do_test_call_varg (const char *format, ...)
{
  va_list args;

  va_start (args, format);
  vwarn (format, args);
  va_end (args);

  va_start (args, format);
  vwarnx (format, args);
  va_end (args);
}

static void
do_test_call_rarg (const char *format, long double ld1, double d1,
		   long double ld2, double d2)
{
  warn (format, ld1, d1, ld2, d2);
  warnx (format, ld1, d1, ld2, d2);
}

static int
do_test (void)
{
  double d1 = -2;
  double d2 = -4;
  long double ld1 = -1;
  long double ld2 = -3;

  /* Print in decimal notation.  */
  do_test_call_rarg ("%Lf - %f - %Lf - %f", ld1, d1, ld2, d2);
  do_test_call_varg ("%Lf - %f - %Lf - %f", ld1, d1, ld2, d2);

  return 0;
}

#include <support/test-driver.c>
