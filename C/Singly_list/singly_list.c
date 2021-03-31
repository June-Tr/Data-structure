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
