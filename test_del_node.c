#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "fifo.h"

static fifo* under_test = NULL;

void test_for_delNode_with_Fifo_pointer_setToNULL(void) {
    TEST_ASSERT_EQUAL(FAILURE,del_node(NULL));
}

void test_for_delNode_should_fail_for_emptyfifo(void) {
    fifo* my_fifo = init_fifo(5);
    TEST_ASSERT_EQUAL(FAILURE,del_node(my_fifo));
}

void test_for_delNode_should_del_Values_with_FirstInFirstOut(void) {
    const unsigned int number_of_elements = 5;
    int number_at_the_front = 0;
    int front = 0;
    int rear = 0;

    fifo* my_fifo = init_fifo(number_of_elements);
 
    /* To fill the fifo, add all the numbers first */
    for( int i = 0; i < number_of_elements; i++) {
        TEST_ASSERT_EQUAL(SUCCESS,add_node((i*5), my_fifo));
    }
    
    /* Delete and check the number at the front */
    for(int i = 0; i < number_of_elements ; i++) {
        front = my_fifo->front;
        number_at_the_front = my_fifo->array_base_address[front];

        /* check the number at the front keeps on updating */
        TEST_ASSERT_EQUAL_UINT32((i*5), number_at_the_front);

        /* check if front increases */
        TEST_ASSERT_EQUAL_INT32(i,front);
 
        /* Delete operation should succeed anyway */
        TEST_ASSERT_EQUAL(SUCCESS,del_node(my_fifo));
    }

    /* After all the Nodes are deleted try deleting again,which should fail */
    TEST_ASSERT_EQUAL(FAILURE,del_node(my_fifo));
}

void test_delNode_when_only_one_element_left(void) {

    const unsigned int number_of_elements = 5;
    int front = 0;
    int rear = 0;
    
    fifo* my_fifo = init_fifo(number_of_elements);

    /* add one node to delete */
    TEST_ASSERT_EQUAL(SUCCESS,add_node(10,my_fifo));

    /* Try deleting that node */
    TEST_ASSERT_EQUAL(SUCCESS,del_node(my_fifo));

    /* Get front and rear after delete operation */
    rear = my_fifo->rear;
    front = my_fifo->front;

    /* Test front and rear */
    TEST_ASSERT_EQUAL_INT32(-1,front);
    TEST_ASSERT_EQUAL_INT32(-1,rear);
}

void test_delNode_for_rollOver_of_front(void) {
    int front = 0;
    int rear = 0;
    const int number_of_elements = 5;
    fifo *my_fifo = init_fifo(5);

    /* Add one element */
    TEST_ASSERT_EQUAL(SUCCESS, add_node(50, my_fifo));  // front 0 rear 0

    /* Fill all the nodes first */
    for (int i=0; i < (number_of_elements-1); i++) {
        TEST_ASSERT_EQUAL(SUCCESS, add_node((i*5), my_fifo)); 
        TEST_ASSERT_EQUAL(SUCCESS, del_node(my_fifo));
        front = my_fifo->front;
        rear = my_fifo->rear;
        TEST_ASSERT_EQUAL_INT(front, rear);
    }

    //  front 4 rear 4

    /* add few elements */
    TEST_ASSERT_EQUAL(SUCCESS, add_node(50, my_fifo)); // front 4  rear 0
    TEST_ASSERT_EQUAL(SUCCESS, add_node(55, my_fifo)); // front 4  rear 1

    /* Delete the node and add the node */
    TEST_ASSERT_EQUAL_INT(SUCCESS, del_node(my_fifo));

    front = my_fifo->front;
    rear = my_fifo->rear;

    /* rear should be zero now i.e. rolled over */
    TEST_ASSERT_EQUAL_INT(0, front);
    TEST_ASSERT_EQUAL_INT(1, rear);
}

/* Test cases for add node */
void tests_for_delNode(void) {
    RUN_TEST(test_for_delNode_with_Fifo_pointer_setToNULL);
    RUN_TEST(test_for_delNode_should_fail_for_emptyfifo);
    RUN_TEST(test_delNode_when_only_one_element_left);
    RUN_TEST(test_for_delNode_should_del_Values_with_FirstInFirstOut);   
    RUN_TEST(test_delNode_for_rollOver_of_front);
}