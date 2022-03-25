#ifndef _BINARY_TREES_H
#define _BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Nodo de árbol binario
 *
 * @n: Entero almacenado en el nodo
 * @parent: Puntero al nodo padre
 * @left: Puntero al nodo secundario izquierdo
 * @right: Puntero al nodo secundario derecho
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* arbolito */
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *new_node(avl_t *parent, size_t value);
avl_t *insert_AVL_node(avl_t *parent, int *array, int start, int end);

#endif /* arbolitosby*/
