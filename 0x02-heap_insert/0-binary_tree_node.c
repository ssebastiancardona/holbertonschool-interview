#include "binary_trees.h"

/**
* binary_tree_node - creates node of binary tree
* @parent: pointer to the parent node of the node to create
* @value: value to put in the new node
* Return: a pointer to the new node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *NewNode = NULL;

	NewNode = malloc(sizeof(binary_tree_t));
	if (!NewNode)
		return (NULL);
	NewNode->n = value;
	NewNode->left = NULL;
	NewNode->right = NULL;
	NewNode->parent = parent;
	return (NewNode);
}