#include <stdlib.h>
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
        return list;
    } else {
        struct node_obj * ptr = other->first;
        struct node_obj * value = node_create();
        value->dato = ptr->dato;
        list->first = value;
        for (ptr = ptr->next; ptr; ptr = ptr->next) {
            value->next = node_create();
            value->next->dato = ptr->dato;
            value = value->next;
        }
        return list;
    }
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
    value->dato = item;
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
    struct node_obj * ptr = node_create();
    ptr->dato = item;
    ptr->next = obj->first;
    obj->first = ptr;
}

static struct node_obj * _list_remove(struct node_obj * obj, int pos)
{
    if (pos <= 0)
    {
        struct node_obj * temp = obj->next;
        node_destroy(obj);
        return temp;
    } else {
        obj->next = _list_remove(obj->next, --pos);
        return obj;
    }
}

/** quita un item de una posicon intermedia */
void list_remove(lst * obj, int pos)
{
    obj->first = _list_remove(obj->first, pos);
}


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

static struct node_obj * _list_set(struct node_obj * obj, int pos, int item)
{
    if (pos <= 0)
    {
        obj->dato = item;
        return obj;
    } else {
        obj->next = _list_set(obj->next, --pos, item);
        return obj;
    }
}

/** escribe en el item */
void list_set(lst * obj, int pos, int item)
{
    obj->first = _list_set(obj->first, pos, item);
}

static struct node_obj * list_node_insert(struct node_obj * obj, int pos, int item)
{
    if (pos == 0 || obj == NULL) {
    struct node_obj * nuevo = node_create();
    nuevo->dato = item;
    nuevo->next = obj;
    return nuevo;
} 
    else {
        obj->next = list_node_insert(obj->next, pos - 1, item);
        return obj;
    }
}

void list_insert(lst * obj, int pos, int item)
{
    obj->first = list_node_insert(obj->first, pos, item);
}
