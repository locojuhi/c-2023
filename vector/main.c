#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void _print(vec*obj)
{
    size_t length = vector_size(obj);
    printf("[");
    if (length >= 1) {
        printf("%d", vector_item(obj, 0));
    }
    if (length > 1) {
        for(int i=1; i<length; i++) {
            printf(", %d", vector_item(obj, i));
        }
    }
    printf("]\n");
}

int  main(int argc,char ** argv)
{
    vec * obj = vector_create();
    vector_append(obj, 2);
    vector_append(obj, 3);
    vector_prepend(obj, 1);
    // 1,2,3
    vec * otro = vector_copy(obj);
    vector_append(otro, 4);
    _print(otro);
    vector_destroy(otro);
    vector_insert(obj, 0, 0);
    // 0,1,2,3
    _print(obj);
    vector_destroy(obj);
    return EXIT_SUCCESS;
}

