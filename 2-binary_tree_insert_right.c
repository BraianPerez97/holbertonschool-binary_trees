#include "binary_trees.h"
/* binary_tree_insert_right - insert a node as the right child of another tree
 *@parent: pointer to the parent node
 *@value: the value of new node
 * Return: pointer to the new node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
        binary_tree_t *new;

        if (parent == NULL)
                return (NULL);

        new = binary_tree_node(parent, value);
        if (new == NULL)
                return (NULL);

        if (parent->left != NULL)
        {
                new->left = parent->left;
                parent->left->parent = new;
        }
        parent->left = new;

        return (new);
}

