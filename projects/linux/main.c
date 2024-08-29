#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include "log.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "cunit_ring_buff.h"
#include "cunit_signal_generator.h"
#include "cunit_list.h"
#include "cunit_cfifo.h"

int main(void)
{
    CU_ErrorCode error_code;
    int32_t ret;

    error_code = CU_initialize_registry();
    if (error_code != CUE_SUCCESS)
    {
        return -EINVAL;
    }

    ret = cunit_ring_buffer_register_suite_and_case();
    if (ret)
    {
        return ret;
    }

    ret = cunit_signal_generator_register_suite_and_case();
    if (ret)
    {
        return ret;
    }

    ret = cunit_list_register_suite_and_case();
    if (ret)
    {
        return ret;
    }

    ret = cunit_cfifo_register_suite_and_case();
    if (ret)
    {
        return ret;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    error_code = CU_basic_run_tests();
    if (error_code != CUE_SUCCESS)
    {
        return -EINVAL;
    }

    CU_cleanup_registry();

    return 0;
}
