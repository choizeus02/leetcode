/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root){
   if(!root->left && !root->right)
        return root->val;
    else if(root->val == 2){
            if(evaluateTree(root->left) || evaluateTree(root->right))
                return 1;
        }
    else if(root->val == 3){
            if(evaluateTree(root->left) && evaluateTree(root->right))
                return 1;

        }
    return 0;
}