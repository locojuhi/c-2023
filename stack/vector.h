#ifndef VECTOR_H_7162535161
#define VECTOR_H_7162535161 1

#include <sys/types.h>

struct vector_obj
{
    size_t capacity;
    size_t length;
    // length <= capacity !!!
    int * memory;
};
typedef struct vector_obj vec;

/** construye un nuevo vector */
vec * vector_create();

/** construye un nuevo vector como copia de otro */
vec * vector_copy(vec * other);

/** destruye el vector */
void vector_destroy(vec * obj);

/** devuelve el tamaño en uso del vector */
size_t vector_size(vec * obj);

/** añade un item al final */
void vector_append(vec * obj, int item);

/** añade un item al inicio */
void vector_prepend(vec * obj, int item);

/** añade un item en una posicion intermedia */
void vector_insert(vec * obj, int pos, int item);

/** quita un item de una posicon intermedia */
void vector_remove(vec * obj, int pos);

/** lee el item */
int vector_item(vec * obj, int pos);

/** escribe en el item */
void vector_set(vec * obj, int pos, int item);


#endif /*VECTOR_H_7162535161*/

