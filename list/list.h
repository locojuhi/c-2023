#ifndef LIST_H_726438599
#define LIST_H_726438599 1


struct node_obj
{
    int dato;
    struct node_obj * next;
};

struct node_obj * node_create(void);
void node_destroy(struct node_obj * obj);

struct list_obj
{
    struct node_obj * first;
};

typedef struct list_obj lst;

lst * list_create(void);

void list_destroy(lst * obj);

/** construye un nuevo list como copia de otro */
lst * list_copy(lst * other);

/** destruye el list */
void list_destroy(lst * obj);

/** devuelve el tamaño en uso del list */
size_t list_size(lst * obj);

/** añade un item al final */
void list_append(lst * obj, int item);

/** añade un item al inicio */
void list_prepend(lst * obj, int item);

/** añade un item en una posicion intermedia */
void list_insert(lst * obj, int pos, int item);

/** quita un item de una posicon intermedia */
void list_remove(lst * obj, int pos);

/** lee el item */
int list_item(lst * obj, int pos);

/** escribe en el item */
void list_set(lst * obj, int pos, int item);




#endif /*LIST_H_726438599*/

