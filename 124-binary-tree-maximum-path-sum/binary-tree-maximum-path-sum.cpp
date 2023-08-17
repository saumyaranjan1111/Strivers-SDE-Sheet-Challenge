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
    int solve(TreeNode* root, int &ans){
        if(root == NULL) return 0;

        // max vertical path sum whose starting node is the left node
        int left = solve(root->left, ans);

        // max vertical path sum whose starting node is the right node
        int right = solve(root->right, ans);
        
        // if this node lies on the maxsum path, then we update the ans
        ans = max(ans, left + right + root->val);

        // we are updating the ans, but we are returning the max vertical path sum which includes this node
        return max(0, root->val + max(left, right));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int temp = solve(root, ans);
        return ans;
    }
};