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
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>> pq;
        helper(pq, root, k);
        return pq.top();
    }
    
    void helper(priority_queue<int, vector<int>>& pq, TreeNode* root, int k){
        if(root == NULL)
            return;
        pq.push(root->val);
        if(pq.size() > k)
            pq.pop();
        if(root->left != NULL)
          helper(pq, root->left, k);
        if(root->right != NULL)
          helper(pq, root->right, k);        
    }
};
