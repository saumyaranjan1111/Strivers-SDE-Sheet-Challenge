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
    // n*n solution
    TreeNode* helper(vector<int>& preorder, int left, int right){
        if(left > right) return NULL;
        if(left <0 || right <0) return NULL;

        TreeNode* root = new TreeNode(preorder[left]);
        int pivot = -1;
        int i = left+1;
        while(i<=right && preorder[i] < root->val) i++;
        pivot = i;

        root->left = helper(preorder, left+1, pivot-1);
        root->right = helper(preorder, pivot, right);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n==0) return NULL;
        int left = 0;
        int right = n-1;
        TreeNode* root = new TreeNode(preorder[left]);

        int pivot = -1;

        int i = left+1; 
        while(i<=right && preorder[i] < root->val) i++;
        pivot = i;
        root->left = helper(preorder, left + 1, pivot-1);
        root->right = helper(preorder, pivot, right);

        return root;
    }
};