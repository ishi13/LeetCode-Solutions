/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/

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

// res will contain 2D vector of elements in zig zag order
vector<vector<int>> res;
public:

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    traverse(root, 0);
    return res; 
}

void traverse(TreeNode *root, int level) {
    if (!root) {
        return; 
    }

  // create sub vector for level if it hasn't been created
    if (res.size() <= level) {
        vector<int> subList{};
        res.push_back(subList); 
    }

    // store reference to vector containing nodes for current level
    vector<int> *list = &res.at(level); 
    if (level % 2 == 0) {
    	// add even leveled nodes in order
        list->insert(list->end(), root->val); 
    } else {
    	// add odd leveled nodes in reverse order
        list->insert(list->begin(), root->val); 
    }

    // continue traversing each child node 
    traverse(root->left, level+1);
    traverse(root->right, level+1);
}
};
