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
#include "cfifo.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "cunit_cfifo.h"

static int cunit_cfifo_initialize(void)
{
    return 0;
}

static int cunit_cfifo_cleanup(void)
{
    return 0;
}

static void cunit_cfifo_basic_case(void)
{
    cfifo fifo;
    uint8_t buffer[8];
    uint8_t w_buffer[5];
    uint8_t r_buffer[4];
    uint32_t i;
    int32_t ret;
    uint32_t ret_u32;
    uint8_t* ptr1;
    uint32_t len1;
    uint8_t* ptr2;
    uint32_t len2;

    (void)memset(buffer, 0, sizeof(buffer) / sizeof(buffer[0]));

    cfifo_init(&fifo, buffer, sizeof(buffer) / sizeof(buffer[0]));

    ret_u32 = cfifo_len(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 0);

    ret_u32 = cfifo_free_space(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 8);

    for (i = 0; i < sizeof(w_buffer) / sizeof(w_buffer[0]); i++)
    {
        w_buffer[i] = i;
    }

    ret = cfifo_put(&fifo, w_buffer, sizeof(w_buffer) / sizeof(w_buffer[0]));
    CU_ASSERT_EQUAL(ret, 0);

    ret_u32 = cfifo_len(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 5);

    ret_u32 = cfifo_free_space(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 3);

    ret = cfifo_pop(&fifo, r_buffer, sizeof(r_buffer) / sizeof(r_buffer[0]));
    CU_ASSERT_EQUAL(ret, 0);

    ret_u32 = cfifo_len(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 1);

    ret_u32 = cfifo_free_space(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 7);

    CU_ASSERT_EQUAL(r_buffer[0], 0);
    CU_ASSERT_EQUAL(r_buffer[1], 1);
    CU_ASSERT_EQUAL(r_buffer[2], 2);
    CU_ASSERT_EQUAL(r_buffer[3], 3);

    ret = cfifo_put(&fifo, w_buffer, sizeof(w_buffer) / sizeof(w_buffer[0]));
    CU_ASSERT_EQUAL(ret, 0);

    ret_u32 = cfifo_len(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 6);

    ret_u32 = cfifo_free_space(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 2);

    ret = cfifo_peek(&fifo, 6, &ptr1, &len1, &ptr2, &len2);
    CU_ASSERT_EQUAL(ret, 0);

    CU_ASSERT_EQUAL(len1, 4);
    CU_ASSERT_EQUAL(ptr1[0], 4);
    CU_ASSERT_EQUAL(ptr1[1], 0);
    CU_ASSERT_EQUAL(ptr1[2], 1);
    CU_ASSERT_EQUAL(ptr1[3], 2);

    CU_ASSERT_EQUAL(len2, 2);
    CU_ASSERT_EQUAL(ptr2[0], 3);
    CU_ASSERT_EQUAL(ptr2[1], 4);

    ret = cfifo_pop(&fifo, r_buffer, sizeof(r_buffer) / sizeof(r_buffer[0]));
    CU_ASSERT_EQUAL(ret, 0);

    ret_u32 = cfifo_len(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 2);

    ret_u32 = cfifo_free_space(&fifo);
    CU_ASSERT_EQUAL(ret_u32, 6);

    CU_ASSERT_EQUAL(r_buffer[0], 4);
    CU_ASSERT_EQUAL(r_buffer[1], 0);
    CU_ASSERT_EQUAL(r_buffer[2], 1);
    CU_ASSERT_EQUAL(r_buffer[3], 2);
}

int32_t cunit_cfifo_register_suite_and_case(void)
{
    CU_pSuite new_suite;
    CU_pTest new_test;

    new_suite = CU_add_suite("cfifo",
                             cunit_cfifo_initialize,
                             cunit_cfifo_cleanup);
    if (!new_suite)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "cunit_cfifo_basic_case",
                           cunit_cfifo_basic_case);
    if (!new_test)
    {
        return -EINVAL;
    }

    return 0;
}
