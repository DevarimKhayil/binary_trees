#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if no uncle or input node/parent/grandparent is NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    /* Check if node or its parent or grandparent is NULL */
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    /* Determine if parent is left or right child of grandparent */
    if (node->parent == node->parent->parent->left)
        return node->parent->parent->right; /* Return right child as uncle */
    else if (node->parent == node->parent->parent->right)
        return node->parent->parent->left; /* Return left child as uncle */

    return NULL; /* No uncle found */
}

