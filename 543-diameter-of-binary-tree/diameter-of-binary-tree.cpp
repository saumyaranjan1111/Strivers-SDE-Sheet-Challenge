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
public:
    int solve(TreeNode* root, int &maxd){
        if(root == NULL) return 0;

        int left = solve(root->left, maxd);
        int right = solve(root->right, maxd);

        maxd = max(maxd, left + right + 1);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd = 0;
        int temp = solve(root, maxd);
        return maxd-1;
    }
};