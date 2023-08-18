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
    TreeNode* build(int postidx, vector<int>&inorder, vector<int>&postorder, int inleft, int inright, int postleft, int postright, unordered_map<int, int>& mp){

        if(inleft > inright) return NULL;
        if(postleft > postright) return NULL;

        postidx = postright;
        TreeNode* root = new TreeNode(postorder[postidx]);
        int pivot = mp[postorder[postidx]];
        
        root->left = build(postidx, inorder, postorder, inleft, pivot-1, postleft, postleft + (pivot-1 - inleft), mp);
        root->right = build(postidx, inorder, postorder, pivot+1, inright, postleft + (pivot-1 - inleft) + 1, postidx-1, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        int inleft = 0, inright = n-1;
        int postleft = 0, postright = n-1;
        int postidx = postright;

        unordered_map<int, int> mp;

        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return build(postidx, inorder, postorder, inleft, inright, postleft, postright, mp);
    }
};