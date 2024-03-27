#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs in-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: In-order traversal visits the left subtree, then the current node,
 * and then the right subtree.
 * If tree or func is NULL, do nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_inorder(tree->left, func);   // Traverse left subtree
    func(tree->n);  // Call the function on the current node
    binary_tree_inorder(tree->right, func);  // Traverse right subtree
}
