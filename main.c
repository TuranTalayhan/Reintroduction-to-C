
/* You are not allowed to use <stdio.h> */
#include <stdlib.h>
#include "io.h"

struct Node {

    int data;

    struct Node *prev;

    struct Node *next;
};

struct Node *create_node(int new_data) {
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

struct Node *add(struct Node *head, int new_data){
    struct Node *new_node = create_node(new_data);
    if(head == NULL){
        head = new_node;
    } else {
        struct Node *current = head;
        while(current->next != NULL){
            current = current->next;
        }

        current->next = new_node;
        new_node->prev = current;
    }
    return head;
}


void write_list(struct Node* head){

    struct Node* current = head;

    while (current != NULL){
        write_int(current->data);
        if(current->next != NULL){
            write_char(',');
        } else {
            write_char(';');
        }
        current = current->next;
    }

    write_char('\n');
}
struct Node *remove_last(struct Node *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
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
    int c = read_char();

    struct Node* head = NULL;

    while(c == 'a' || c == 'b' || c == 'c'){
        if(c == 'a'){
            head = add(head, counter);
            counter++;
        } else if (c == 'b'){
            counter++;
        } else if (c == 'c'){
            head = remove_last(head);
            counter++;
        }
        c = read_char();
    }
    write_list(head);

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
