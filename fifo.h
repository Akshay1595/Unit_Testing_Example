/**
 * @file fifo.h
 * @author Akshay Godase
 * @date 10-10-2020
 * @brief This file will have all necessary definitions 
 * for implementation of FIFO data structure
 */ 

#ifndef FIFO_H
#define FIFO_H

#include <stdio.h>

typedef enum status_t{
    SUCCESS = 0,
    FAILURE = 1
}status;

/* Fifo structure and its elements */
typedef struct fifo_
{
    int front;
    int rear;
    unsigned int* array_base_address;
    unsigned int num_of_array_elements;
}fifo;

/**
 * @brief This functions initiate the fifo and returns its address
 * @param num_of_elements number of integers fifo needs to be initiated with
 * @return pointer to fifo created. NULL if fails
 */
fifo* init_fifo(unsigned int num_of_elements);

/**
 * @brief This funcion will add node to the fifo
 * @param num integer to be added
 * @param my_fifo address of fifo to which number needs to be added
 * @return 0 = failed , 1 = success
 */
status add_node(int num,fifo* my_fifo);

/**
 * @brief This funcion will delete node off the fifo
 * @param my_fifo address of fifo
 * @return 0 = failed , 1 = success
 */
status del_node(fifo* my_fifo);

/**
 * @brief Check if Fifo is full
 * @param my_fifo address fifo we want to check if full
 * @return 0 = not full , 1 = full
 */
status check_if_full(fifo* my_fifo);

/**
 * @brief This function Check if Fifo is empty
 * @param my_fifo address of fifo we want to check if empty
 * @return 0 = not not , 1 = empty
 */
status check_if_empty(fifo* my_fifo);

/**
 * @brief This function Check if Fifo is empty
 * @param my_fifo address of fifo of which data has to be printed
 * @return None
 */
void print_node(fifo* my_fifo);

#endif