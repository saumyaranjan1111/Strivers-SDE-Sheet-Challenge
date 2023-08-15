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
    int h = 0;
    int max_h = 0;
    void dfs(TreeNode* node)
    {
        if(node==NULL) return;

        h++;
        dfs(node->left);
        dfs(node->right);
        
        max_h = max(max_h, h);
        h--;
    }
    int maxDepth(TreeNode* root) {
        dfs(root);
        return max_h;
    }
};