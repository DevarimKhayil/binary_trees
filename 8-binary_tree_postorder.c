#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs post-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: Post-order traversal visits the left subtree, then the right subtree,
 * and finally the current node.
 * If tree or func is NULL, do nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_postorder(tree->left, func);   // Traverse left subtree
    binary_tree_postorder(tree->right, func);  // Traverse right subtree
    func(tree->n);  // Call the function on the current node
}
