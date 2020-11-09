#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "fifo.h"
#include "test.h"

static fifo* under_test = NULL;

/* TestCases for init */
void test_if_initSuccess_when_numOfElements_setToValidValue(void) {
    TEST_ASSERT_NOT_EQUAL(NULL,init_fifo(5));
    TEST_ASSERT_NOT_EQUAL(NULL,init_fifo(0xFFFF));
}

void test_if_initFails_when_numOfElements_setTo0(void){
    TEST_ASSERT_EQUAL_INT(NULL,init_fifo(0));
}

void test_init_of_front_and_rear_when_fifo_is_empty(void) {
    fifo* under_test = init_fifo(5);
    TEST_ASSERT_EQUAL(-1,under_test->front);
    TEST_ASSERT_EQUAL(-1,under_test->rear);
}

void test_initFifo_for_number_of_elements(void) {
    fifo* under_test = init_fifo(5);
    TEST_ASSERT_EQUAL_INT(5,under_test->num_of_array_elements);
}

void test_initFifo_values_for_arrayElements_set_to_zero(void) {
    const int number_of_elements = 5;
    fifo* under_test = init_fifo(number_of_elements);
    
    /* Test if array base address is not left uninitiazed */
    TEST_ASSERT_NOT_EQUAL(0,under_test->array_base_address);

    /* Test integer array initialized to 0 */
    for (int i=0;i<number_of_elements;i++)
        TEST_ASSERT_EQUAL_INT(0,under_test->array_base_address[i]);
}

void tests_for_initFifo(void) {
    RUN_TEST(test_init_of_front_and_rear_when_fifo_is_empty);
    RUN_TEST(test_if_initFails_when_numOfElements_setTo0);
    RUN_TEST(test_if_initSuccess_when_numOfElements_setToValidValue);
    RUN_TEST(test_initFifo_values_for_arrayElements_set_to_zero);
    RUN_TEST(test_initFifo_for_number_of_elements);
}
