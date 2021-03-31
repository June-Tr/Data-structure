//include guard
#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H
// add library:
#include <stdlib.h>
#include <assert.h>

/** Imeplementation of singly list: one directional list start from node point
 * to by head, end at last node {point to by tail}.
 */

// Data struct
/* singly list node: since it is one way, we only need to know which is the
  next node {pointer to next} */
typedef struct {
    // ptr to the user's allocated memory.
    void                         *data;

    struct one_direction_node_t *next;

} one_direction_node_t;


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

/*****************************************************************************/
#endif
