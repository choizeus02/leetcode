/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root, long min, long max){
    if (root == NULL){
        return true;
    }
    if (root->val > min && root->val < max && 
        check(root->left , min, root->val) && check(root->right , root->val, max)){
        return true;
    }
    return false;
}

bool isValidBST(struct TreeNode* root){
    long min = LONG_MIN;
    long max = LONG_MAX;
    if (check(root->left , min, root->val) && check(root->right , root->val, max)){
        return true;
    }
    return false;
}




