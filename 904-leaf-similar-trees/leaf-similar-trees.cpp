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
    void extractleaves(TreeNode* root, vector<int> &ans){
        if(!root) return;
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->val);
            return;
        }

        extractleaves(root->left, ans);
        extractleaves(root->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left;
        vector<int> right;

        extractleaves(root1, left);
        extractleaves(root2, right);

        // bool flag = true;
        if(left.size() != right.size()) return false;

        for(int i = 0; i<left.size(); i++){
            if(left[i] != right[i]) return false;
        }
        return true;
    }
};