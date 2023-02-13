#include <stdlib.h>
#include <string.h>
#include <vector.h>
#include "stack.h"


stack * stack_create()
{
    stack * self = (stack *)malloc(sizeof(struct stack_obj));
    bzero(self, sizeof(struct stack_obj));
    self->bucket = vector_create();
    self->tope = -1;
    return self;
}

void stack_destroy(stack * self)
{
    if (self) {
        vector_destroy(self->bucket);
        free(self);
    }
}

int stack_top(stack * self)
{
    return vector_item(self->bucket, self->tope);
}

void stack_push(stack * self, int item)
{
    vector_append(self->bucket, item);
    self->tope++;
}

void stack_pop(stack * self)
{
    vector_remove(self->bucket, self->tope);
    self->tope--;
}

int stack_top_pop(stack * self)
{
    int item = stack_top(self);
    stack_pop(self);
    return item;
}



