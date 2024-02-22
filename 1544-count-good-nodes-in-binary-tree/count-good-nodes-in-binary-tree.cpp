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
    void dfs(TreeNode* root, int &count, int maxtillnow){
        if(root == NULL) return;

        if(root->val >= maxtillnow){
            count++;
        }

        dfs(root->left, count, max(maxtillnow, root->val));
        dfs(root->right, count, max(maxtillnow, root->val));
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        int maxtillnow = -1e5;
        dfs(root, count, maxtillnow);
        return count;
    }
};