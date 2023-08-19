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


//  Morris Preorder Traversal
class Solution {
public:
    TreeNode* findPredecessor(TreeNode* curr){
        TreeNode* pred = curr->left;
        while(pred->right!=NULL && pred->right!=curr){
            pred = pred->right;
        }
        return pred;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr!=NULL){
            if(curr->left != NULL){
                TreeNode* predecessor = findPredecessor(curr);
                if(predecessor -> right == NULL){
                    // create a link
                    predecessor -> right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    predecessor -> right = NULL;
                    curr = curr->right;
                }
            }
            else
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};