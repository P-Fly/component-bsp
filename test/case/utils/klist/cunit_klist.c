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
#include "klist.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "cunit_klist.h"

static int cunit_klist_initialize(void)
{
    return 0;
}

static int cunit_klist_cleanup(void)
{
    return 0;
}

typedef struct
{
    struct list_head    list;
    uint32_t            data;
} data_node_t;

static void cunit_klist_add_and_delete(void)
{
    LIST_HEAD(head);
    data_node_t* node;
    data_node_t* entry;
    uint32_t i;

    for (i = 0; i < 5; i++)
    {
        node = (data_node_t*)malloc(sizeof(*node));

        node->data = i;
        list_add(&node->list, &head);
    }

    i = 4;

    list_for_each_entry(entry, &head, list)
    {
        CU_ASSERT_EQUAL(entry->data, i--);
    }

    while (!list_empty(&head))
    {
        entry = list_first_entry(&head, data_node_t, list);
        list_del(&entry->list);
        free(entry);
    }

    CU_ASSERT_TRUE(list_empty(&head));

    for (i = 0; i < 5; i++)
    {
        node = (data_node_t*)malloc(sizeof(*node));

        node->data = i;
        list_add_tail(&node->list, &head);
    }

    i = 0;

    list_for_each_entry(entry, &head, list)
    {
        CU_ASSERT_EQUAL(entry->data, i++);
    }

    while (!list_empty(&head))
    {
        entry = list_first_entry(&head, data_node_t, list);
        list_del(&entry->list);
        free(entry);
    }

    CU_ASSERT_TRUE(list_empty(&head));
}

int32_t cunit_klist_register_suite_and_case(void)
{
    CU_pSuite new_suite;
    CU_pTest new_test;

    new_suite = CU_add_suite("klist",
                             cunit_klist_initialize,
                             cunit_klist_cleanup);
    if (!new_suite)
    {
        return -EINVAL;
    }

    new_test = CU_add_test(new_suite,
                           "klist_add_and_delete",
                           cunit_klist_add_and_delete);
    if (!new_test)
    {
        return -EINVAL;
    }

    return 0;
}
