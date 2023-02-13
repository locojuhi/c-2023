#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(int argc,char ** argv)
{
    struct stack_obj * st = stack_create();
    stack_push(st, 1);
    stack_push(st, 2);
    stack_push(st, 3);
    printf("espero un tres: %d\n", stack_top(st));
    stack_pop(st);
    printf("ahora espero un dos: %d\n", stack_top(st));
    stack_destroy(st);
    return EXIT_SUCCESS;
}

