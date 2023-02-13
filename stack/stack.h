#ifndef STACK_H_16sya6a5
#define STACK_H_16sya6a5 1

#include <vector.h>

struct stack_obj
{
    vec * bucket;
    int tope;
};
typedef struct stack_obj stack;

#ifdef __cplusplus
extern "C" {
#endif

stack * stack_create();

void stack_destroy(stack * self);

int stack_top(stack * self);

void stack_push(stack * self, int item);

void stack_pop(stack * self);

int stack_top_pop(stack * self);


#ifdef __cplusplus
}
#endif

#endif /*STACK_H_16sya6a5*/

