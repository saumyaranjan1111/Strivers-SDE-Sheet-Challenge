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


//  Morris Inorder Traversal
class Solution {
public:
    TreeNode* findPredecessor(TreeNode* curr){
        TreeNode* pred = curr->left;
        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }
        return pred;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* pred = findPredecessor(curr);
                if(pred -> right == NULL){
                    // no link is present 
                    // create a link
                    pred->right = curr;
                    // go to the left
                    curr = curr->left;
                }
                else {
                    // link is already present
                    // which means we have already processed all the nodes present in the left subtree
                    // process the current node and go to the right after removing the link
                    ans.push_back(curr->val);
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
            else{
                // there is no left node for this node
                // process this node
                ans.push_back(curr->val);

                // go to the right, since the left node was not present and have already processed the center node (l n R), so now we need to go to the right node

                curr = curr->right;
            }
        }

        return ans;
    }
};