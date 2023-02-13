#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "vector.h"

/** construye un nuevo vector */
vec * vector_create()
{
    vec * obj = (vec *)malloc(sizeof(struct vector_obj));
    assert((obj != NULL));
    bzero(obj, sizeof(struct vector_obj));
    return obj;
}

/** construye un nuevo vector como copia de otro */
vec * vector_copy(vec * other)
{
    vec * obj = vector_create();
    size_t len = vector_size(other);
    for(int i=0; i<len; i++) {
        vector_append(obj, vector_item(other, i));
    }
    return obj;
}

/** destruye el vector */
void vector_destroy(vec * obj)
{
    if (obj) {
        if (obj->memory) {
            free(obj->memory);
        }
        free(obj);
    }
}

/** devuelve el tamaño en uso del vector */
size_t vector_size(vec * obj)
{
    return obj->length;
}

/** añade un item al final */
void vector_append(vec * obj, int item)
{
    vector_insert(obj, obj->length, item);
}

/** añade un item al inicio */
void vector_prepend(vec * obj, int item)
{
    vector_insert(obj, 0, item);
}

#define BLOCK 256

/** se asegura que haya suficiente capacidad */
static void vector_require(vec * obj, size_t capacity)
{
    if (obj->capacity >= capacity) {
        return; // no hago nada
    } else {
        size_t new_capacity = obj->capacity;
        while (new_capacity < capacity) {
            new_capacity += BLOCK;
        }
        int * ptr = (int*)realloc(obj->memory, (sizeof(int) * new_capacity));
        if (ptr) {
            obj->memory = ptr;
        }
        obj->capacity = new_capacity;
    }
}

/** añade un item en una posicion intermedia */
void vector_insert(vec * obj, int pos, int item)
{
    vector_require(obj, vector_size(obj) + 1);
    size_t length = vector_size(obj);
    for (int i=length; i>=pos; i--) {
        vector_set(obj,i,vector_item(obj,i-1));
    }
    obj->length++;
    vector_set(obj, pos, item);
}

/** quita un item de una posicon intermedia */
void vector_remove(vec * obj, int pos)
{
    size_t length = vector_size(obj);
    for (int i=pos+1; i<length; i++) {
        vector_set(obj,i-1,vector_item(obj,i));
    }
    obj->length--;
}

/** lee el item */
int vector_item(vec * obj, int pos)
{
    return obj->memory[pos];
}

/** escribe en el item */
void vector_set(vec * obj, int pos, int item)
{
    obj->memory[pos] = item;
}

