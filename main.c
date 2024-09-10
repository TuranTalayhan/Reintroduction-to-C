
/* You are not allowed to use <stdio.h> */
#include <stdlib.h>
#include "io.h"

struct List {

    int head;

    struct List *prev;

    struct List *next;
};

struct List *createList(int new_head) {
    struct List *new_list = (struct List *) malloc(sizeof(struct List));
    new_list->head = new_head;
    new_list->next = NULL;
    new_list->prev = NULL;
    return new_list;
}




/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */
int
main() {
    /*-----------------------------------------------------------------
     *TODO:  You need to implement the command line driver here as
     *       specified in the assignment handout.
     *
     * The following pseudo code describes what you need to do
     *
     *  Declare the counter and the collection structure variables
     *
     *
     *  In a loop
     *    1) Read a command from standard in using read_char function
     *    2) If the command is not 'a', 'b', 'c': then break the loop
     *    3) Process the command as specified in the handout
     *  End loop
     *
     *  Print your collection of elements as specified in the handout
     *    as a comma delimited series of integers
     *-----------------------------------------------------------------*/
    int counter = 0;


    return 0;
}
