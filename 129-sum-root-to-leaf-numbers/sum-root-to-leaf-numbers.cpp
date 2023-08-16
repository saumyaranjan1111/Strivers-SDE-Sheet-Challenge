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
    void traverse(TreeNode* root, int &ans, string currpath){
        if(root->left == NULL && root->right == NULL){
            currpath += to_string(root->val);
            ans += stoi(currpath);
            return;
        }

        if(root->left != NULL)
        traverse(root->left, ans, currpath + to_string(root->val));

        if(root->right != NULL)
        traverse(root->right, ans, currpath + to_string(root->val));

    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return 0;
        
        traverse(root, ans, "");

        return ans;
    }
};