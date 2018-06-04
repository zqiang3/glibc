/* Redirections for monetary functions for -mabi=ieeelongdouble.
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

/* XXX: DO NOT COMMIT.

   On powerpc64le, the implementation of long double with IEEE binary128
   format is not complete.  The redirections of the monetary.h functions
   are supposed to be implemented in bits/monetary-ldbl.h, however, we can
   only redirect all or none.  In the meantime, bits/monetary-ieee128.h
   allows us to redirect part of them for testing purposes.  */

#ifndef _MONETARY_H
# error "Never include <bits/monetary-ieee128.h> directly; use <monetary.h> instead."
#endif

#define __IEEE128_REDIR(name) \
  extern __typeof (name) __##name##ieee128; \
  extern __typeof (name) name __asm (__ASMNAME ("__" #name "ieee128"));

#define __IEEE128_REDIR_CUSTOM(name, custom) \
  extern __typeof (name) custom; \
  extern __typeof (name) name __asm (__ASMNAME (#custom));

__IEEE128_REDIR (strfmon)

#ifdef __USE_GNU
__IEEE128_REDIR_CUSTOM (strfmon_l, __strfmonieee128_l)
#endif
