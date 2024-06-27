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

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include "err.h"
#include "ring_buff.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "cunit_ring_buff.h"

static int cunit_ring_buff_initialize(void)
{
    return 0;
}

static int cunit_ring_buff_cleanup(void)
{
    return 0;
}

static void cunit_ring_buffer_init_case_0(void)
{
    ring_buff_t ring;
    uint8_t buffer[5];
    int32_t ret;

    ret = ring_buffer_init(NULL, buffer, sizeof(buffer));
    CU_ASSERT_EQUAL(ret, -EINVAL);

    ret = ring_buffer_init(&ring, NULL, sizeof(buffer));
    CU_ASSERT_EQUAL(ret, -EINVAL);

    ret = ring_buffer_init(&ring, buffer, 0);
    CU_ASSERT_EQUAL(ret, -EINVAL);
}

static void cunit_ring_buffer_write_case_0(void)
{
    ring_buff_t ring;
    uint8_t buffer[5];
    int32_t ret;

    ret = ring_buffer_init(&ring, buffer, sizeof(buffer));
    CU_ASSERT_EQUAL(ret, 0);

    ret = ring_buffer_write(NULL, 0x55);
    CU_ASSERT_EQUAL(ret, -EINVAL);
}

static void cunit_ring_buffer_read_case_0(void)
{
    ring_buff_t ring;
    uint8_t buffer[5];
    uint8_t value;
    int32_t ret;

    ret = ring_buffer_init(&ring, buffer, sizeof(buffer));
    CU_ASSERT_EQUAL(ret, 0);

    ret = ring_buffer_read(NULL, &value);
    CU_ASSERT_EQUAL(ret, -EINVAL);

    ret = ring_buffer_read(&ring, NULL);
    CU_ASSERT_EQUAL(ret, -EINVAL);

    ret = ring_buffer_read(&ring, &value);
    CU_ASSERT_EQUAL(ret, -EEMPTY);
}

static void cunit_ring_buffer_function_case_0(void)
{
    ring_buff_t ring;
    uint8_t buffer[5];
    uint8_t value;
    int32_t ret;

    ret = ring_buffer_init(&ring, buffer, sizeof(buffer));
    CU_ASSERT_EQUAL(ret, 0);

    for (uint8_t i = 0; i < 5; i++)
    {
        ret = ring_buffer_write(&ring, i);
        CU_ASSERT_EQUAL(ret, 0);
    }

    ret = ring_buffer_write(&ring, 6);
    CU_ASSERT_EQUAL(ret, -EFULL);

    for (uint8_t i = 0; i < 5; i++)
    {
        ret = ring_buffer_read(&ring, &value);
        CU_ASSERT_EQUAL(ret, 0);
        CU_ASSERT_EQUAL(i, value);
    }

    ret = ring_buffer_read(&ring, &value);
    CU_ASSERT_EQUAL(ret, -EEMPTY);
}

int32_t cunit_ring_buff_register_suite_and_case(void)
{
    CU_pSuite new_suite;
    CU_pTest new_test;

    new_suite = CU_add_suite("ring_buff",
                             cunit_ring_buff_initialize,
                             cunit_ring_buff_cleanup);
    if (!new_suite)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "ring_buffer_init",
                           cunit_ring_buffer_init_case_0);
    if (!new_test)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "ring_buffer_write",
                           cunit_ring_buffer_write_case_0);
    if (!new_test)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "ring_buffer_read",
                           cunit_ring_buffer_read_case_0);
    if (!new_test)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "ring_buffer_function",
                           cunit_ring_buffer_function_case_0);
    if (!new_test)
    {
        return -EINVAL;
    }

    return 0;
}
