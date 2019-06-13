/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, long minVal, long maxVal){
        if(root == NULL)
            return true;
        if(root->left != NULL && (root->left->val >= root->val || root->left->val <= minVal || root->left->val >= maxVal))
            return false;
        if(root->right != NULL && (root->right->val <= root->val || root->right->val <= minVal || root->right->val >= maxVal))
            return false;
        return ( helper(root->left, minVal, root->val) && helper(root->right, root->val, maxVal) ); 
    }
    
    bool isValidBST(TreeNode* root) {
       return helper(root, LONG_MIN, LONG_MAX);
    }
};
