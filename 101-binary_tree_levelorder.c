#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: The function traverses the binary tree in level-order and calls
 * the given function for each node, passing the node's value as a parameter.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    queue_t *queue = NULL;

    if (tree == NULL || func == NULL)
        return;

    queue_push(&queue, (void *)tree);

    while (!queue_empty(queue))
    {
        const binary_tree_t *node = (const binary_tree_t *)queue_peek(queue);
        queue_pop(&queue);

        func(node->n);

        if (node->left)
            queue_push(&queue, (void *)node->left);
        if (node->right)
            queue_push(&queue, (void *)node->right);
    }

    queue_free(queue);
}
