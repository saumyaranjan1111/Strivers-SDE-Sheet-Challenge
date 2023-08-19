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
    TreeNode* findPredecessor(TreeNode* curr){
        auto pred = curr->left;
        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }
        return pred;
    }
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left != NULL){
                auto post = curr->right;
                auto predecessor = findPredecessor(curr);
                curr->right = curr->left;
                curr->left = NULL;
                predecessor->right = post;
                curr = curr->right;
            }
            else {
                curr = curr->right;
            }

        }
        
    }
};