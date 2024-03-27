#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree != NULL)
    {
        /* Post-order traversal to delete left subtree */
        binary_tree_delete(tree->left);

        /* Post-order traversal to delete right subtree */
        binary_tree_delete(tree->right);

        /* Delete current node */
        free(tree);
    }
}
