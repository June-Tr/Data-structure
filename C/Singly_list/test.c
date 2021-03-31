#include <stdio.h>
#include "singly_list.c"

int main(int argc, char const *argv[]) {
    // test create and free the node.
    int number = 1;
    one_direction_node_t* node;
    node = make_one_direction_node(&number);
    free(node);
    return 0;
}
