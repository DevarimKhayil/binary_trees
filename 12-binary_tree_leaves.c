#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaves in the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* If node is a leaf, return 1, otherwise recursively check left and right subtrees */
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
