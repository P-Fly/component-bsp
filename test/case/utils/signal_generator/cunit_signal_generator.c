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
#include <stdlib.h>
#include "err.h"
#include "signal_generator.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "cunit_signal_generator.h"

static int cunit_signal_generator_initialize(void)
{
    return 0;
}

static int cunit_signal_generator_cleanup(void)
{
    return 0;
}

static void cunit_signal_generator_Sin1k_SR16k_bit16(void)
{
    FILE* file;
    size_t written;
    size_t len;
    uint32_t i;
    int32_t ret;
    int16_t* signal_buff;

    ret = signal_generator_get_data_size(SG_TYPE_SIN_1K, SG_SR_16K, SG_BIT_16);
    CU_PASS(ret > 0);

    len = ret;

    signal_buff = (int16_t*)malloc(len);
    CU_ASSERT_PTR_NOT_NULL_FATAL(signal_buff);

    ret = signal_generator_get_data(SG_TYPE_SIN_1K,
                                    SG_SR_16K,
                                    SG_BIT_16,
                                    signal_buff);
    CU_ASSERT_EQUAL(ret, 0);

    file = fopen("Sin1k_SR16k_bit16", "a");
    CU_ASSERT_PTR_NOT_NULL_FATAL(file);

    for (i = 0; i < 10000; i++)
    {
        written = fwrite(signal_buff, len, 1, file);
        CU_ASSERT_EQUAL(written, 1);
    }

    fclose(file);
    free(signal_buff);
}

static void cunit_signal_generator_Sin1k_SR48k_bit32(void)
{
    FILE* file;
    size_t written;
    size_t len;
    uint32_t i;
    int32_t ret;
    int32_t* signal_buff;

    ret = signal_generator_get_data_size(SG_TYPE_SIN_1K, SG_SR_48K, SG_BIT_32);
    CU_PASS(ret > 0);

    len = ret;

    signal_buff = (int32_t*)malloc(len);
    CU_ASSERT_PTR_NOT_NULL_FATAL(signal_buff);

    ret = signal_generator_get_data(SG_TYPE_SIN_1K,
                                    SG_SR_48K,
                                    SG_BIT_32,
                                    signal_buff);
    CU_ASSERT_EQUAL(ret, 0);

    file = fopen("Sin1k_SR48k_bit32", "a");
    CU_ASSERT_PTR_NOT_NULL_FATAL(file);

    for (i = 0; i < 10000; i++)
    {
        written = fwrite(signal_buff, len, 1, file);
        CU_ASSERT_EQUAL(written, 1);
    }

    fclose(file);
    free(signal_buff);
}

static void cunit_signal_generator_Sin10k_SR16k_bit32(void)
{
    FILE* file;
    size_t written;
    size_t len;
    uint32_t i;
    int32_t ret;
    int32_t* signal_buff;

    ret = signal_generator_get_data_size(SG_TYPE_SIN_10K, SG_SR_16K, SG_BIT_32);
    CU_PASS(ret > 0);

    len = ret;

    signal_buff = (int32_t*)malloc(len);
    CU_ASSERT_PTR_NOT_NULL_FATAL(signal_buff);

    ret = signal_generator_get_data(SG_TYPE_SIN_10K,
                                    SG_SR_16K,
                                    SG_BIT_32,
                                    signal_buff);
    CU_ASSERT_EQUAL(ret, 0);

    file = fopen("Sin10k_SR16k_bit32", "a");
    CU_ASSERT_PTR_NOT_NULL_FATAL(file);

    for (i = 0; i < 10000; i++)
    {
        written = fwrite(signal_buff, len, 1, file);
        CU_ASSERT_EQUAL(written, 1);
    }

    fclose(file);
    free(signal_buff);
}

static void cunit_signal_generator_Sin10k_SR48k_bit16(void)
{
    FILE* file;
    size_t written;
    size_t len;
    uint32_t i;
    int32_t ret;
    int16_t* signal_buff;

    ret = signal_generator_get_data_size(SG_TYPE_SIN_10K, SG_SR_48K, SG_BIT_16);
    CU_PASS(ret > 0);

    len = ret;

    signal_buff = (int16_t*)malloc(len);
    CU_ASSERT_PTR_NOT_NULL_FATAL(signal_buff);

    ret = signal_generator_get_data(SG_TYPE_SIN_10K,
                                    SG_SR_48K,
                                    SG_BIT_16,
                                    signal_buff);
    CU_ASSERT_EQUAL(ret, 0);

    file = fopen("Sin10k_SR48k_bit16", "a");
    CU_ASSERT_PTR_NOT_NULL_FATAL(file);

    for (i = 0; i < 10000; i++)
    {
        written = fwrite(signal_buff, len, 1, file);
        CU_ASSERT_EQUAL(written, 1);
    }

    fclose(file);
    free(signal_buff);
}

int32_t cunit_signal_generator_register_suite_and_case(void)
{
    CU_pSuite new_suite;
    CU_pTest new_test;

    new_suite = CU_add_suite("signal_generator",
                             cunit_signal_generator_initialize,
                             cunit_signal_generator_cleanup);
    if (!new_suite)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "signal_generator_Sin1k_SR16k_bit16",
                           cunit_signal_generator_Sin1k_SR16k_bit16);
    if (!new_test)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "signal_generator_Sin1k_SR48k_bit32",
                           cunit_signal_generator_Sin1k_SR48k_bit32);
    if (!new_test)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "signal_generator_Sin10k_SR16k_bit32",
                           cunit_signal_generator_Sin10k_SR16k_bit32);
    if (!new_test)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "signal_generator_Sin10k_SR48k_bit16",
                           cunit_signal_generator_Sin10k_SR48k_bit16);
    if (!new_test)
    {
        return -EINVAL;
    }

    return 0;
}
