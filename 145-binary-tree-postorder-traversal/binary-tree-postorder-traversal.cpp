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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        // using two stacks
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            auto base_node = st1.top();
            st1.pop();
            st2.push(base_node);

            if(base_node->left != NULL){
                st1.push(base_node->left);
            }
            if(base_node->right != NULL){
                st1.push(base_node->right);
            }
        }

        vector<int> ans;
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};