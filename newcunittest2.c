/*
 * File:   newcunittest2.c
 * Author: abcde
 *
 * Created on Feb 12, 2019, 10:47:46 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

int negativeOrZero(int input);

void testNegativeOrZero() {
    CU_ASSERT_EQUAL(negativeOrZero(0),1);
    CU_ASSERT_EQUAL(negativeOrZero(-1),1);
    CU_ASSERT_EQUAL(negativeOrZero(1),0);
}

int fibonacci(int input);

void testTotal() {
    CU_ASSERT_EQUAL(fibonacci(8), 60);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest2", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testNegativeOrZero", testNegativeOrZero))) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testTotal", testTotal))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
