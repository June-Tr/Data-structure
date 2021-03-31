#include <stdio.h>
#include "singly_list.h"

int main(int argc, char const *argv[]) {
    // test create and free the node.
    singly_list_t* list  = NULL;
    int*           added = NULL;
    for(int i = 0; i < 100; i ++){
        added = (int*)malloc(sizeof(int));
        assert(added);
        *added = i;
        list = append_to_singly_list(list, added);
    }
    free_singly_list(&list);
    return 0;
}
