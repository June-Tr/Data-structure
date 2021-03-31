#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
/******************************************************************************/
// USED library
#include <stdlib.h>
#include <assert.h>
#include <time.h>

//CONSTANT DEFINITION
#define INITIAL_SIZE 10
#define FACTOR 3
#define SINGLE 1
#define EMPTY 0
#define YES 1
#define NO 0
/* Dynamic array is allocated at run time, start with a acceptable size.
 * If needed, it can growth.
 * I will implement a simple version of code that decide how much space to
 * increase the space size.
 */
// data structure definition.
typedef struct{
    /* this should only able to maintain a block of memory. algorithm, structure
       make use of this data structure should implement in away that always fill
       the space between the first index to the last index.
     */
    void **memory_space;

    int  max_capacity;
    int  current_filled;
}dynamic_array_t;

/**METHOD****************************************/


/* allocate memory a array with size of INITIAL_SIZE.
 * Return: array if allocation is successful.
 */
dynamic_array_t *make_dynamic_array();


/* Add the data into the memory space at the last index.
 */
void append_to_dynamic_array(dynamic_array_t *array, void* data);

/* Free everything within this array.
 * Arguement: array - address of the shell contain the actual array.
 * Arguement: is_free_item - flag to indicate that we want to free the item.
 *                            stored within the memory_space
 */
void free_dynamic_array(dynamic_array_t **array, int is_free_item);
/******************************************************************************/
#endif
