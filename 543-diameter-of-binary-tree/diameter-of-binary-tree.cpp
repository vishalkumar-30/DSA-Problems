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
    int helper(TreeNode* root, int& sum){
        if(root == NULL) return 0;
        int left = 0, right=0;
        if(root->left) left = helper(root->left, sum)+1;
        if(root->right) right =  helper(root->right, sum)+1;
        sum = max(sum, left+right);
        return max(right, left);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int sum=0;
        int res = helper(root, sum);
        return sum;
    }
};