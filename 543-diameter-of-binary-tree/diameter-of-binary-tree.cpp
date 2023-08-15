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
    int findheight(TreeNode* root, int &ans){
        if(root == NULL) return 0;

        int lefth = findheight(root->left, ans);
        int righth = findheight(root->right, ans);

        ans = max(ans, lefth + righth);

        return max(lefth, righth) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // distance between any two nodes = distance of one node from lca + distance of another node from lca
        int ans = 0;

        int temp =findheight(root, ans);
        return ans;
    }
};