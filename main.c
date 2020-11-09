#include <stdio.h>
#include "fifo.h"

typedef enum choice_ {
    ADD_NODE = 1,
    DEL_NODE,
    PRINT_NODE
}my_choice;

int main() {
    int number_of_elements;
    int choice = 0;
    int num;
    int* num_to_be_deleted = NULL;
    fifo* my_fifo = NULL;

    printf("Enter the number of elements you want in fifo: ");
    scanf("%d",&number_of_elements);

    my_fifo = init_fifo(number_of_elements);
    if (my_fifo == NULL)
        return 0;

    while (1) {
        printf("Enter the choice 1. Add_node 2. Del_node 3. Print_node: X. Exit ");
        scanf("%d",&choice);
        switch (choice)
        {
        case ADD_NODE:
            
            printf("Enter the number you want to add: ");
            scanf("%d",&num);
            add_node(num,my_fifo);
            break;
        
        case DEL_NODE:
            del_node(my_fifo);
            break;

        case PRINT_NODE:
            print_node(my_fifo);
            break;

        default:
            printf("Bye Bye!\n");
            _exit(0);
            break;
        }
    }   
    return 0;
}