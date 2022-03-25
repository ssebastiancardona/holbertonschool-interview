#include "binary_trees.h"

/**
 * sorted_array_to_avl - función
 * @matriz: matriz
 * @tamaño: tamaño
 * Retorno: puntero a la raíz
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (!array ? NULL : insert_AVL_node(NULL, array, 0, (int)size - 1));
}

/**
 * insert_AVL_node - función
 * @parent: puntero al padre
 * @matriz: matriz
 * @start: índice de inicio
 * @end: índice final
 * Retorno: puntero al nodo creado
 */
avl_t *insert_AVL_node(avl_t *parent, int *array, int start, int end)
{
	size_t orem;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);
	orem = (start + end) / 2;
	root = new_node(parent, array[orem]);
	if (!root)
		return (NULL);
	root->left = insert_AVL_node(root, array, start, orem - 1);
	root->right = insert_AVL_node(root, array, orem + 1, end);
	return (root);
}

/**
 * nuevo_nodo - función
 * @parent: puntero al padre
 * @valor: valor
 * Retorno: puntero al nodo creado
 */
avl_t *new_node(avl_t *parent, size_t value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}