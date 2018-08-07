#!/bin/sh
# Test for the long double conversions in *err* functions.
# Copyright (C) 2018 Free Software Foundation, Inc.
# This file is part of the GNU C Library.

# The GNU C Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.

# The GNU C Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with the GNU C Library; if not, see
# <http://www.gnu.org/licenses/>.

set -e

test_program=$1; shift
test_program_prefix=$1; shift
test_program_output=$1; shift

status=0

${test_program_prefix} \
  ${test_program} \
  2> ${test_program_output} || status=1

# This script is shared among different test cases that have different
# names and print different messages, however, the goal of the tests is
# to detect if floating-point conversions worked, not if the messages
# and filenames are correct, thus:
#
# Remove the trailing messages, if any.
sed -i ${test_program_output} -e "s/: Success//"
#
# Remove the program name.
sed -i ${test_program_output} -e "s/.*tst-[^:]*: //"
#
# Remove the line number annotation (error_at_line).
sed -i ${test_program_output} -e "s/.*1234: //"

cat <<'EOF' |
-1.000000000000000000000000000000000000000000000000000000000000
EOF
cmp - ${test_program_output} > /dev/null 2>&1 ||
{
  status=1
  echo "*** output comparison failed"
}

exit $status
