#include "dynamic_array.h"
/******************************************************************************/
dynamic_array_t *make_dynamic_array(){
    // allocate the size and ensure that allocation is occured
    dynamic_array_t *array = (dynamic_array_t*)malloc(sizeof(dynamic_array_t));
    assert(array);

    // Allocate the actual array within the shell
    array -> memory_space = (void**) malloc(INITIAL_SIZE * sizeof(void*));
    assert(array -> memory_space);

    array -> max_capacity   = INITIAL_SIZE;
    array -> current_filled = EMPTY;

    // return the allocated array shell
    return array;
}
/******************************************************************************/

void append_to_dynamic_array(dynamic_array_t *array, void* data){

    // ensure the array shell exist some where in memory.
    assert(array && data);

    // check the size to see if the expansion is required.
    if(array -> current_filled >= array -> max_capacity){

        cur_gap = clock() - last_time_relloc;
        last_time_relloc = clock();
        size = get_factor(cur_gap, last_gap, size);
        last_gap = cur_gap;
        printf("Factor: %lf\n", size);
        // update the shell.
        //array -> max_capacity = (int)(array -> max_capacity * size);
        array -> max_capacity = (array -> max_capacity * FACTOR);
        array -> memory_space =
            (void**) realloc(array -> memory_space,
                array -> max_capacity* sizeof(void*));

        assert(array -> memory_space);


    }

    // add the item to the last index.
    array -> memory_space[array -> current_filled] = data;
    array -> current_filled +=1;
}
/******************************************************************************/
void free_dynamic_array(dynamic_array_t **array, int is_free_item){
    assert(*array);

    /* if indicated that we want to free all item in this array. loop through
       till the last index, free them along the way. {it is ok to free void*}
     */
     int i;
     if(is_free_item == YES && (*array) -> current_filled > 0){
         for(i = 0; i < (*array) -> current_filled; i++){
             free((*array) -> memory_space [i]);
         }
     }

     // free the memory space.
     free((*array) -> memory_space);
     free(*array);
     *array = NULL;
}
/******************************************************************************/
