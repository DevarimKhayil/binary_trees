#include "binary_trees.h"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *ancestor = NULL;
    const binary_tree_t *temp;

    if (first == NULL || second == NULL)
        return NULL;

    temp = first;
    while (temp)
    {
        if (temp == second || temp == second->parent)
            return (binary_tree_t *)temp;
        temp = temp->parent;
    }

    temp = second;
    while (temp)
    {
        if (temp == first || temp == first->parent)
            return (binary_tree_t *)temp;
        temp = temp->parent;
    }

    return (binary_tree_t *)ancestor;
}
