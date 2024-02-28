/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, int depth, int &value, int &maxdepth){
        if (!root) return;
        if(depth>maxdepth){
            maxdepth = depth;
            value = root->val;
        }
        if(root->left) helper(root->left, depth+1, value, maxdepth);
        if(root->right) helper(root->right, depth+1, value, maxdepth);
        return;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int depth = 1;
        int value = 0;
        int maxdepth = 0;
        helper(root, depth, value, maxdepth);
        return value;
    }
};