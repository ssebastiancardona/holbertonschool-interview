#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * is_binary_search_tree - comprueba si el árbol es un árbol de búsqueda binaria
 * @node: nodo actual que se está comprobando
 * @min: entero que indica el límite izquierdo del valor del nodo actual
 * @max: entero que indica el límite derecho del valor del nodo actual
 * @height: altura del nivel del árbol binario actual
 * (el valor actual debe ser <= max y >= min)
 * Devuelve: 1 si el árbol es un BST válido, de lo contrario 0
 */
int is_binary_search_tree(const binary_tree_t *node, int min, int max,
		int *height)
{
	int isq_h = 0;
	int der_h = 0;

	if (!node)
		return (1);

	if (node->n >= max || node->n <= min)
		return (0);

	if (!is_binary_search_tree(node->left, min, node->n, &isq_h) ||
			!is_binary_search_tree(node->right, node->n,
				max, &der_h))
		return (0);
	*height = (isq_h > der_h ? isq_h : der_h) + 1;
	return (abs(isq_h - der_h) < 2);
}

/**
 * binary_tree_is_avl - comprueba si un árbol binario es un árbol AVL válido
 * @tree: apunta al nodo raíz del árbol para verificar
 * Devuelve: 1 si el árbol es un AVL válido, de lo contrario 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int altura = 0;

	if (!tree)
		return (0);
	return (is_binary_search_tree(tree, INT_MIN, INT_MAX, &altura));
}