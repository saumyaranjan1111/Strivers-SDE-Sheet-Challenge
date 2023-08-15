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
    int solve(TreeNode* root){
        if(root == NULL){
            // height of null tree is zero
            return 0;
        }

        int left_height = solve(root->left);
        int right_height = solve(root->right);

        if(left_height == -1 || right_height == -1){
            // if any one of the children are not balanced then this also cant be balanced
            return -1;
        }
        if(abs(left_height - right_height) > 1){
            // not a balanced binary tree
            return -1;
        }

        // if both the children are balanced and the height difference is also not > 1, then this node is a balanced binary tree, return the height of this tree
        return max(left_height, right_height) + 1;

    }
    bool isBalanced(TreeNode* root) {
        
        if(solve(root)!=-1)
        return true;
        else return false;

    }
};