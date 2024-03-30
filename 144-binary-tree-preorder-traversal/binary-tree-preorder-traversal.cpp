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
        // the predecessor node is the rightmost node in the left subtree of root
        TreeNode* pre = curr->left;
        while(pre->right != NULL && pre->right != curr){
            pre = pre->right;
        }

        return pre;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        auto curr = root;
        while(curr){
            if(curr->left != NULL){
                auto pred = findPred(curr);
                if(pred->right == NULL){
                    pred->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                } else {
                    // pred->right == curr
                    // this left subtree has already been explored, so now go to the right
                    pred->right = NULL;
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