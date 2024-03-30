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
        // using one stack : just go left until you cant, then try to go right one step, then go all the way left again
        // when you cant go right from a node, the fact that we attempted to go right from the node indicates that we have already gone through all the nodes in the left subtree of the node, and if the right node is null or already visited, then we process the root node, since both left and right have been now completed
        stack<pair<TreeNode*, int>> st;
        vector<int> post;
        if(root == NULL) return post;
        st.push({root, 1});
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            auto node = temp.first;
            int n = temp.second;
            if(n == 1){
                st.push({node, 2});
                if(node->left != NULL){
                    st.push({node->left, 1});
                }
            } else if(n == 2){
                st.push({node, 3});
                if(node->right != NULL){
                    st.push({node->right, 1});
                }
            } else {
                post.push_back(node->val);
            }
        } 
        return post;
    }
};