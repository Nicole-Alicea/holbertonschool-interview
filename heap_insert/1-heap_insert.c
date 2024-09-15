#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Description: This function recursively measures the height of a binary
 * tree. The height is defined as the number of edges on the longest path
 * from the node to a leaf. If the tree is NULL, it returns -1.
 *
 * Return: The height of the tree. If the tree is NULL, return -1.
 */
int height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * btree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Description: A perfect binary tree is a binary tree in which all internal
 * nodes have two children, and all leaves have the same depth or level.
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 */
int btree_is_perfect(const binary_tree_t *tree)
{
	_Bool l_ch;
	_Bool r_ch;
	int l_per;
	int r_per;

	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		l_ch = !((tree->left)->left) && !((tree->left)->right);
		r_ch = !((tree->right)->left) && !((tree->right)->right);

		if ((tree->left && l_ch) && (tree->right && r_ch))
			return (1);

		if (tree && tree->left && tree->right)
		{
			l_per = btree_is_perfect(tree->left);
			r_per = btree_is_perfect(tree->right);
			return (l_per && r_per);
		}
	}

	return (0);
}

/**
 * swap - Swaps two nodes in a binary heap when the child node has a greater value than the parent node.
 * @arg_node: Pointer to the parent node.
 * @arg_child: Pointer to the child node.
 *
 * Description: This function swaps the positions of a parent node and its child
 * in a Max Binary Heap if the child has a greater value than the parent. After
 * the swap, the heap structure is maintained.
 *
 * Return: Nothing.
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to be inserted into the heap.
 *
 * Description: This function inserts a value into a Max Binary Heap. If the
 * tree is perfect, it inserts the new value in the left subtree, otherwise
 * it continues to insert in the right subtree. It ensures that the Max Heap
 * property (parent node is greater than or equal to child nodes) is maintained
 * by swapping nodes if necessary.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (btree_is_perfect(*root) || !btree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new);
		}
		else
		{
			new = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new);
		}
	}

	if ((*root)->right)
	{
		new = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new);
	}
	else
	{
		new = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new);
	}

	return (NULL);
}
