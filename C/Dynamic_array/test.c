#include <stdio.h>
#include "dynamic_array.h"

int main(int argc, char const *argv[]) {
    dynamic_array_t* array = make_dynamic_array();
    int* num;
    // allocate 100 address to store int. load them into array.
    for(int i = 0; i < 18000000; i++){
        num = (int*) malloc(sizeof(int));
        assert(num);

        *num = i;

        append_to_dynamic_array(array, num);
        num = NULL;
    }
    printf("max: %d\n", array -> max_capacity );
    free_dynamic_array(&array, YES);
    return 0;
}
