/**
 * Embedded Device Software
 * Copyright (C) 2022 Peter.Peng
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "log.h"
#include "err.h"
#include "trace_impl.h"

int32_t trace_output(const char* format, ...)
{
    va_list args;

    va_start(args, format);

    int ret = vprintf(format, args);

    va_end(args);

    return ret;
}

uint32_t trace_get_tick(void)
{
    return 0;
}

int32_t trace_init(void)
{
    return 0;
}

int32_t trace_deinit(void)
{
    return 0;
}
