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
    int ind = 0;
public:
    TreeNode* helper(vector<int>& preorder, int limit){
        if(ind >= preorder.size() || preorder[ind] > limit) return NULL;

        TreeNode* root = new TreeNode(preorder[ind]);
        ind++;
        root->left = helper(preorder, root->val);
        root->right = helper(preorder, limit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;

        TreeNode* root = helper(preorder, INT_MAX);
        // helper will make the tree from index 0
        return root;
    }
};