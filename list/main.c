#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void _print(lst*obj)
{
    size_t length = list_size(obj);
    printf("(");
    if (length >= 1) {
        printf("%d", list_item(obj, 0));
    }
    if (length > 1) {
        for(int i=1; i<length; i++) {
            printf(", %d", list_item(obj, i));
        }
    }
    printf(")\n");
}

int main (int argc,char ** argv)
{
    printf("hello, world!\n");
    lst * list = list_create();
    
    list_append(list, 6);
    list_append(list, 7);
    list_append(list, 8);

    list_insert(list,0, 5);
    list_insert(list,2, 65);

    _print(list);

    list_remove(list, 2);
    
    _print(list);


    list_set(list, 3, 9);

    _print(list);

    list_destroy(list);
    return EXIT_SUCCESS;
}
