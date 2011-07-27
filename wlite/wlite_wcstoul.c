/*
 * $Id$
 *
 * Copyright (C) 2003  Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Original Author: Adrian Havill <havill@redhat.com>
 *
 * Contributors:
 */

#include <errno.h>   // errno, EILSEQ, ERANGE
#include <limits.h>  // INT_MIN, ULONG_MAX, LONG_MIN

#include "wlite_config.h"   // wchar_t, NULL, size_t

#include "wlite_wchar.h"    // prototypes
#include "wlite_wctype.h"
#include "wlite_stdlib.h"

unsigned long
wlite_wcstoul(const wchar_t *s, wchar_t **endptr, int base) {
    long long i;

    i = wlite_widetoll_(s, endptr, base);
    if (i > ULONG_MAX) {
        errno = ERANGE;
        i = ULONG_MAX;
    }
    if (i < 0) {
        errno = ERANGE;
        i = 0;
    }
    return (unsigned long) i;
}
