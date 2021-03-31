//include guard
#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H
// add library:
#include <stdlib.h>
#include <assert.h>

//CONSTANT DEFITNITION
#define SINGLE 1
/** Imeplementation of singly list: one directional list start from node point
 * to by head, end at last node {point to by tail}.
 */

// Data struct
/* singly list node: since it is one way, we only need to know which is the
  next node {pointer to next} */
typedef struct one_direction_node one_direction_node_t;

struct one_direction_node{
    // ptr to the user's allocated memory.
    void                 *data;

    one_direction_node_t *next;
};


/* list shell */
typedef struct {
    // first item in node in list. if NULL mean list is empty.
    one_direction_node_t *head;
    // last item in list.
    one_direction_node_t *tail;
    // CAN be add to store addition information.
    void                  *opt_data;
} singly_list_t;

/*Method*******************************************************/

/* Allocate memory for the node.
 * Arguement: data - pointer to some allocated addresses{must not be NULL}
 * Return: the address of the node.
 */
one_direction_node_t *make_one_direction_node(void* data);


/* Allocate and initalise a singly list.
 * Return: the list with head and tail point to nothing. also set the optional
 *          data to null.
 */
singly_list_t *make_empty_singly_list();


/* add description data into the list.
 * actual structure of the added data is define by user.
 * Arguement: list - allocate list {can be empty}
 */
void add_optional_data_to_singly_list(singly_list_t* list, void* data);

/* Add data to the list.
 * if list = empty: create new list with no optional data
 *    else: add to the input list from tail.

 * Arguement: list - a pointer to list. {does not restrict to be null}
 * Arguement: data - pointer to a data{of any type} in memory. {not null}
 * Return:    list.
 */
singly_list_t *append_to_singly_list(singly_list_t *list, void* data);


/* Add data to the list.
 * if list = empty: create new list with no optional data
 *    else: add to the input list from head.
 *
 * Arguement: list - a pointer to list. {does not restrict to be null}
 * Arguement: data - pointer to a data{of any type} in memory. {not null}
 * Return:    list.
 */
singly_list_t *insert_to_singly_list(singly_list_t *list, void *data);


/* Remove the first item from the list.
 * Argument: pointer to the list which must not be null.
 * Return: data store in the node.
 */
void *pop_from_singly_list(singly_list_t *list);


/* Remove the last item in list
 * Arguement: list - pointer to list.
 * Return: data store in the node.
 */
void *remove_last_from_singly_list(singly_list_t *list);


/* Free all everything in the list: {node} + {data} + {list}
 * lose the address of the list
 *Argument: list - address of the list.
 */
void free_singly_list(singly_list_t** list);
/*****************************************************************************/
#endif
