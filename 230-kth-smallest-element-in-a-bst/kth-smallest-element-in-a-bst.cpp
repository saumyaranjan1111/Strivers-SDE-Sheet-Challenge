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
    void inorder(TreeNode* root, int &num, int &ans, int k){
        if(root == NULL) return;
        
        inorder(root->left, num, ans, k);
        num++;
        
        if(ans == -1 && num == k){
            ans = root-> val;
            return;
        }
        else if(ans != -1){
            return;
        }

        inorder(root->right, num, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> ino;
        int num = 0;
        int ans = -1;
        inorder(root, num, ans, k);
        
        return ans;
    }
};