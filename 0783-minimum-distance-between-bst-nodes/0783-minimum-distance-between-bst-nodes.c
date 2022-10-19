/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //#ifndef max
 //#ifndef min
//#define max(a,b)  (((a) > (b)) ? (a) : (b))
//#define min(a,b)  (((a) < (b)) ? (a) : (b))

void diff(struct TreeNode* root,int* prev, int* min) {
    if(root) { 
        diff(root->left,prev,min);
        if( (*prev!=-1) && ( (root->val - *prev) < *min) )
            *min = root->val - *prev;
        *prev=root->val;
        diff(root->right,prev,min);
    }
}

int minDiffInBST(struct TreeNode* root){
    int min=1000000;
    int prev=-1;
    diff(root,&prev,&min);
    return min;
}
