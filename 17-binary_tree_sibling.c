#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if no sibling or input node/parent is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* Check if node or its parent is NULL */
    if (node == NULL || node->parent == NULL)
        return NULL;

    /* Determine if node is left or right child */
    if (node->parent->left == node)
        return node->parent->right; /* Return right child as sibling */
    else if (node->parent->right == node)
        return node->parent->left; /* Return left child as sibling */

    return NULL; /* No sibling found */
}
