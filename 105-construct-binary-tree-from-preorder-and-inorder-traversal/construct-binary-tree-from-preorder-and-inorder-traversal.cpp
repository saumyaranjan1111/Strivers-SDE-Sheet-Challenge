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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &preInd, int left, int right, unordered_map<int, int> &mp){
        int n = inorder.size();
        if(left > right) return NULL;

        if(preInd >= n) return NULL;

        int pivot = mp[preorder[preInd]];

        preInd++;
        TreeNode* root = new TreeNode(inorder[pivot]);
        root->left = build(preorder, inorder, preInd , left, pivot-1, mp);
        root->right = build(preorder, inorder, preInd , pivot + 1, right, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inorder, preIndex, 0, n-1, mp);
    }
};