#include <stdlib.H>
#include <string.h>

#include "list.h"

struct node_obj * node_create(void)
{
    struct node_obj * obj;
    obj = (struct node_obj *)malloc(sizeof(struct node_obj));
    bzero(obj, sizeof(struct node_obj));
    return obj;
}

void node_destroy(struct node_obj * obj)
{
    if (obj) {
        free(obj);
    }
}


lst * list_create(void)
{
    struct list_obj * obj;
    obj = (struct list_obj *)malloc(sizeof(struct list_obj));
    bzero(obj, sizeof(struct list_obj));
    return obj;
}

void _list_aux_destroy(struct node_obj * obj)
{
    if (obj) {
        if (obj->next) {
            _list_aux_destroy(obj->next);
        }
        node_destroy(obj);
    }
}

/** destruye el list */
void list_destroy(lst * obj)
{
    if (obj) {
        _list_aux_destroy(obj->first);
        free(obj);
    }
}

/** construye un nuevo list como copia de otro */
lst * list_copy(lst * other)
{
    lst * list = list_create();
    if (!other || !other->first) {
        return lst;
    } else {
        struct node_obj * ptr = other->first;
        struct node_obj * value = create_node();
        value->dato = ptr->dato;
        list->first = value;
        for (ptr = ptr->next; ptr; ptr = ptr->next) {
            value->next = create_node();
            value->next->dato = ptr->dato;
            value = value->next;
        }
        return lst;
    }
/*
    lst * list = list_create();
    size_t len = list_size(other);
    for (int i=0; i<len; i++) {
        list_append(list, list_item(other, i));
    }
    return list;
*/
}

/** devuelve el tamaño en uso del list */
size_t list_size(lst * obj)
{
    size_t answer = 0;
    struct node_obj * ptr = obj->first;
    while (ptr) {
        answer++;
        ptr = ptr->next;
    }
    return answer;
}

/** añade un item al final */
void list_append(lst * obj, int item)
{
    struct node_obj * ptr = obj->first;
    struct node_obj * value = node_create();
    obj->dato = item;
    if (ptr) {
        while(ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = value;
    } else {
        obj->first = value;
    }
}

/** añade un item al inicio */
void list_prepend(lst * obj, int item)
{
    struct node_obj * ptr = create_node();
    ptr->dato = item;
    ptr->next = obj->first;
    obj->first = ptr;
}

/** añade un item en una posicion intermedia */
void list_insert(lst * obj, int pos, int item);

/** quita un item de una posicon intermedia */
void list_remove(lst * obj, int pos);

/** lee el item */
int list_item(lst * obj, int pos)
{
    struct node_obj * ptr = obj->first;
    while (pos > 0) {
        ptr = ptr->next;
        pos--;
    }
    return ptr->dato;
}

/** escribe en el item */
void list_set(lst * obj, int pos, int item);

