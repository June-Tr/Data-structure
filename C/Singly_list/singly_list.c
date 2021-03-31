#include "singly_list.h"
/******************************************************************************/
one_direction_node_t *make_one_direction_node(void* data){
    // check if the data point exist.
    assert(data);

    // Allocate memory for the return node.
    one_direction_node_t* return_node =
        (one_direction_node_t*) malloc(sizeof(one_direction_node_t));
    assert(return_node);

    // initialise all the attribute of the allocated node.
    return_node -> next = NULL;
    return_node -> data = data;

    return return_node;
}
/******************************************************************************/
singly_list_t *make_empty_singly_list(){
    singly_list_t *return_list =
        (singly_list_t*) calloc(SINGLE, sizeof(singly_list_t));
    // the return_list is allocated.
    assert(return_list);
    return return_list;
}
/******************************************************************************/
void add_optional_data_to_singly_list(singly_list_t* list, void* data){
    // ensure the list is allocated.
    assert(list);

    list -> opt_data = data;
}
/******************************************************************************/
singly_list_t *append_to_singly_list(singly_list_t *list, void* data){
    // check if there was a list.
    if(!list)
        list = make_empty_singly_list();

    // create the node to store the data.
    // the create method will handle determine if data is existed.
    one_direction_node_t *new = make_one_direction_node(data);

    // case of adding new node to empty
    if((list -> head) == NULL){
        list -> head = list -> tail = new;

    }// case of adding to list that are not empty
    else{
        //add the new node to the end
        list -> tail -> next = new;
        // make that the new tail
        list -> tail = new;
    }
    return list;
}
/******************************************************************************/
singly_list_t *insert_to_singly_list(singly_list_t *list, void* data){
    // check if there was a list.
    if(!list)
        list = make_empty_singly_list();

    // create the node to store the data.
    // the create method will handle determine if data is existed.
    one_direction_node_t *new = make_one_direction_node(data);

    // case of adding new node to empty
    if((list -> head) == NULL){
        list -> head = list -> tail = new;

    }// case of adding to list that are not empty
    else{
        // make the new node point to current head
        new -> next = list -> head;
        // make that the new head.
        list -> head = new;
    }
    return list ;
}
/******************************************************************************/
void *pop_from_singly_list(singly_list_t *list){
    // check the list is existed.
    assert(list);

    void                 *return_data;
    one_direction_node_t *target;

    // remove a node that does not exist.
    if(list -> head == NULL)
        return list -> head;

    // remove the node and free it.
    target = list -> head;
    list -> head = target -> next;

    // get the data.
    return_data = target -> data;
    free(target);
    return return_data;
}
/******************************************************************************/
void *remove_last_from_singly_list(singly_list_t *list){
    // check the list is existed.
    assert(list);

    void                 *return_data;
    one_direction_node_t *target;

    // case where there only one item in list.
    if(list -> head == list -> tail){
        return_data = list -> head -> data;
        // free and lose the address of free memory.
        free(list -> head);
        list -> head = list -> tail = NULL;
    }else{
        target = list -> head;

        while(target -> next -> next){
            target = target -> next;
        }
        // found the second last node, replace and free the tail.
        return_data = list -> tail -> data;
        free(list -> tail);

        list -> tail = target;
        target -> next = NULL;
    }
    return return_data;
}
/******************************************************************************/
void free_singly_list(singly_list_t** list){
    assert(*list);
    void* data;
    // if not empty.
    if((data = pop_from_singly_list(*list))){

        // free the data.
        free(data);
        free_singly_list(list);
    }else{
        // free the list
        if((*list) -> opt_data)
            free((*list) -> opt_data);
        free(*list);
        *list = NULL;
    }

}
