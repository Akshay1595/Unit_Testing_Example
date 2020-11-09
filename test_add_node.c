#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "fifo.h"

static fifo* under_test = NULL;

void test_for_addNode_with_Fifo_pointer_setToNULL(void) {
    TEST_ASSERT_EQUAL(FAILURE,add_node(10,NULL));
}

void test_for_add_node_should_fail_for_fullfifo_when_rolled_over(void) {
    fifo *my_fifo = init_fifo(3);

    /* Fill fifo with all nodes */
    TEST_ASSERT_EQUAL(SUCCESS,add_node(1,my_fifo));
    TEST_ASSERT_EQUAL(SUCCESS,add_node(2,my_fifo));
    TEST_ASSERT_EQUAL(SUCCESS,add_node(3,my_fifo));

    /* Delete one node */
    TEST_ASSERT_EQUAL(SUCCESS,del_node(my_fifo));

    /* Fill again and make it full */
    TEST_ASSERT_EQUAL(SUCCESS,add_node(4,my_fifo));

    /* Adding should fail */
    TEST_ASSERT_EQUAL(FAILURE,add_node(5,my_fifo));
    TEST_ASSERT_EQUAL(FAILURE,add_node(6,my_fifo));
}

void test_for_addNode_should_fail_for_Fullfifo(void) {
    fifo *my_fifo = init_fifo(3);
    TEST_ASSERT_EQUAL(SUCCESS,add_node(1,my_fifo));
    TEST_ASSERT_EQUAL(SUCCESS,add_node(2,my_fifo));
    TEST_ASSERT_EQUAL(SUCCESS,add_node(3,my_fifo));
    TEST_ASSERT_EQUAL(FAILURE,add_node(4,my_fifo));
    TEST_ASSERT_EQUAL(FAILURE,add_node(5,my_fifo));
}

void test_for_addNode_should_fail_for_Fullfifo_when_no_of_elements_1(void) {
    fifo* my_fifo = init_fifo(1);
    TEST_ASSERT_EQUAL(SUCCESS,add_node(1,my_fifo));
    TEST_ASSERT_EQUAL(FAILURE,add_node(2,my_fifo));
}

void test_for_addNode_should_add_Values_as_Passed(void) {
    fifo* my_fifo = init_fifo(2);
    TEST_ASSERT_EQUAL(SUCCESS,add_node(1, my_fifo));
    TEST_ASSERT_EQUAL(SUCCESS,add_node(2, my_fifo));
    TEST_ASSERT_EQUAL(1,my_fifo->array_base_address[0]);
    TEST_ASSERT_EQUAL(2,my_fifo->array_base_address[1]);
}

void test_addNode_for_rollOver_of_rear(void) {
    const int number_of_elements = 5;
    int rear = 0;
    int front = 0;
    fifo *my_fifo = init_fifo(number_of_elements);

    /* Fill the Fifo first */
    for(int i=0; i < number_of_elements; i++) {
        TEST_ASSERT_EQUAL(SUCCESS,add_node((i*5), my_fifo));
    }

    /* Delete 1 node */
    TEST_ASSERT_EQUAL(SUCCESS,del_node(my_fifo));

    /* Try adding one more node and check rear */
    TEST_ASSERT_EQUAL(SUCCESS,add_node(25, my_fifo));
    rear = my_fifo->rear;
    front = my_fifo->front;
    TEST_ASSERT_EQUAL(0,rear);
    TEST_ASSERT_EQUAL_INT(1,front);
}

/* Test cases for add node */
void tests_for_addNode(void) {
    RUN_TEST(test_for_addNode_with_Fifo_pointer_setToNULL);
    RUN_TEST(test_for_addNode_should_fail_for_Fullfifo);
    RUN_TEST(test_for_addNode_should_add_Values_as_Passed);
    RUN_TEST(test_for_add_node_should_fail_for_fullfifo_when_rolled_over);
    RUN_TEST(test_for_addNode_should_fail_for_Fullfifo_when_no_of_elements_1);
    RUN_TEST(test_for_addNode_should_add_Values_as_Passed);
    RUN_TEST(test_addNode_for_rollOver_of_rear);
}