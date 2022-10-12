/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(!root)
        return NULL;
    
    struct TreeNode* node = root;
    if(val < node->val)
        node = searchBST(node->left, val);
    else if(val > node->val)
        node = searchBST(node->right, val);
    else
        return node;
    
    return node;
}