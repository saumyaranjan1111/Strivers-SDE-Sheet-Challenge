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
    bool preorder(TreeNode* root, unordered_map<int, int>& mp, int k){
        if(root == NULL) return false;

        if(mp.find(k - root->val)!= mp.end()){
            return true;
        }
        
        mp[root->val]++;
        bool left = preorder(root->left, mp, k);
        bool right = preorder(root->right, mp, k);

        return left||right;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return preorder(root, mp, k);
    }
};