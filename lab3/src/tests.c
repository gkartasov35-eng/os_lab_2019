#include <CUnit/Basic.h>
#include "find_min_max.h"

static void test_full_array(void)
{
    int values[] = {7, -4, 12, 0};
    struct MinMax result = GetMinMax(values, 0, 4);
    CU_ASSERT_EQUAL(result.min, -4);
    CU_ASSERT_EQUAL(result.max, 12);
}

static void test_subrange(void)
{
    int values[] = {100, 4, -3, 8, 90};
    struct MinMax result = GetMinMax(values, 1, 4);
    CU_ASSERT_EQUAL(result.min, -3);
    CU_ASSERT_EQUAL(result.max, 8);
}

static void test_one_element(void)
{
    int values[] = {5};
    struct MinMax result = GetMinMax(values, 0, 1);
    CU_ASSERT_EQUAL(result.min, 5);
    CU_ASSERT_EQUAL(result.max, 5);
}

static void test_empty_range(void)
{
    int values[] = {5};
    struct MinMax result = GetMinMax(values, 0, 0);
    CU_ASSERT_EQUAL(result.min, 0);
    CU_ASSERT_EQUAL(result.max, 0);
}

int main(void)
{
    CU_pSuite suite;

    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    suite = CU_add_suite("GetMinMax", NULL, NULL);
    if (suite == NULL
        || CU_add_test(suite, "full array", test_full_array) == NULL
        || CU_add_test(suite, "subrange", test_subrange) == NULL
        || CU_add_test(suite, "one element", test_one_element) == NULL
        || CU_add_test(suite, "empty range", test_empty_range) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
