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
    TreeNode* findPred(TreeNode* curr){
        auto pred = curr->left;
        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }
        return pred;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode* curr = root;
        while(curr){
            if(curr->left != NULL){
                TreeNode* pred = findPred(curr);
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            } else {
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }

        return ans;
    }
};