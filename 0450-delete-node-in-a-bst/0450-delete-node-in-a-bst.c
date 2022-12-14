/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findMax(struct TreeNode *root)
{
	if (root->right == NULL)
		return root->val;
	else
		return findMax(root->right);
}

struct TreeNode *deleteNode(struct TreeNode *root, int key)
{
	struct TreeNode *temp;

	if (root == NULL)
		return NULL;
	else if (key < root->val)
		root->left = deleteNode(root->left, key);
	else if (key > root->val)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			root = temp;
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			root = temp;
		}
		else
		{
			root->val = findMax(root->left);
			root->left = deleteNode(root->left, root->val);
		}
	}

	return root;
}