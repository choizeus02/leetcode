/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *Tree(int* nums,int start, int end){
    struct TreeNode *node;
    int mid;
    if (start>end)
        return NULL;
    node = malloc(sizeof(struct TreeNode));
    
    mid = start+(end-start)/2;
    
    node->val=nums[mid];
    node->left=Tree(nums,start,mid-1);
    node->right=Tree(nums,mid+1,end);
    

return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return Tree(nums,0,numsSize-1);
}