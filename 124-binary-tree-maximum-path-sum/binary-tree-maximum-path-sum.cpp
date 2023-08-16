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
    int maxpathdown(TreeNode* root, int &maxi){
        if(root == NULL){
            return 0;
        }

        int leftsum = maxpathdown(root->left, maxi);
        int rightsum = maxpathdown(root->right, maxi);

        maxi = max(maxi, leftsum + rightsum + root->val);

        return max(0, root->val + max(leftsum, rightsum));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        int temp = maxpathdown(root, maxi);

        return maxi;
    }
};