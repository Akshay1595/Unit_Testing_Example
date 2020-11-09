/**
 * @file fifo.cpp
 * @brief This file is written to try Test driven development
 * of fifo / circular queue data structure
 * Requirements:
 * 1. Fifo needs to be have elements specified by user
 * 2. Element added first needs to be taken out first
 * 3. Element added last needs to be taken out last
 * 4. Fifo module needs to have three functions 
 *  a. Add node 
 *  b. Delete node
 *  d. Init fifo
 * @author Akshay Godase
 * @date 10-10-2020
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fifo.h"

fifo* init_fifo(unsigned int number_of_elements){
    fifo* my_fifo = NULL;
    if (number_of_elements != 0) {
        my_fifo = (fifo*)malloc(sizeof(fifo));
        my_fifo->array_base_address = (unsigned int *)malloc(number_of_elements * sizeof(unsigned int));
        my_fifo->num_of_array_elements = number_of_elements;
        memset(my_fifo->array_base_address,0,number_of_elements*(sizeof(int)));
        my_fifo->front = -1;
        my_fifo->rear = -1;
    }
    return my_fifo;
}

status add_node(int num,fifo* my_fifo) {
    if (my_fifo == NULL)
        return FAILURE;
    if (check_if_full(my_fifo) == SUCCESS)
        return FAILURE;
    
    if (check_if_empty(my_fifo) == SUCCESS)
        my_fifo->front = my_fifo->rear = 0;

    else if (my_fifo->rear == (my_fifo->num_of_array_elements-1))
        my_fifo->rear = 0;
    else
        my_fifo->rear++;

    my_fifo->array_base_address[my_fifo->rear] = num;
    return SUCCESS;
}

status del_node(fifo* my_fifo) {
    if (my_fifo == NULL)
        return FAILURE;
    if (check_if_empty(my_fifo) == SUCCESS)
        return FAILURE;

    int front = my_fifo->front;
    int rear = my_fifo->rear;
    my_fifo->array_base_address[front] = 0;

    if (front == rear)
        my_fifo->rear = my_fifo->front = -1;
    else if (front == ((my_fifo->num_of_array_elements)-1))
        my_fifo->front = 0;
    else
        (my_fifo->front)++;

    return SUCCESS;
}

status check_if_full(fifo* my_fifo) {
    if (my_fifo == NULL)
        return FAILURE;

    int front = my_fifo->front;
    int rear = my_fifo->rear;

    if ((front > rear) && ((front - rear) == 1)) 
        return SUCCESS;
    else if ((rear > front) && ((rear - front) == (my_fifo->num_of_array_elements - 1)))
        return SUCCESS;
    else if ((rear == 0) && (front == 0) && (my_fifo->num_of_array_elements == 1))
        return SUCCESS;
    else
        return FAILURE;
}

status check_if_empty(fifo* my_fifo) {
    if ((my_fifo->front == -1) && (my_fifo->rear == -1))
        return SUCCESS;
    else
        return FAILURE;
}

#ifdef UNIT_TEST
void print_node(fifo* my_fifo) {
    if (check_if_empty(my_fifo) == SUCCESS) {
        printf("FIFO empty!\n");
        return;
    }
    int start_index = my_fifo->front;
    int end_index = my_fifo->rear;

    while (start_index != end_index) {
        if(start_index > (my_fifo->num_of_array_elements-1))
            start_index = 0;
        printf("-|%d|-",my_fifo->array_base_address[start_index]);
        start_index++;
    }
    printf("-|%d|-\n",my_fifo->array_base_address[start_index]);
    return;
}
#endif
