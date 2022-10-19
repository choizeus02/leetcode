/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void InitNode(struct TreeNode* node, int val)
{
    node->val = val;
    node->left = NULL;
    node->right = NULL;
}
    
    
void InsertNode(struct TreeNode** root, struct TreeNode* newNode)
{
    if (!*root)
        *root = newNode;
    
    else
    {
        if (newNode->val < (*root)->val)
            InsertNode(&(*root)->left, newNode);
        
        else if(newNode->val > (*root)->val)
            InsertNode(&(*root)->right, newNode);
        
        else
            free(newNode) ;
    }
}


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
    InitNode(new_node, val);
    InsertNode(&root, new_node);
    return root;
}