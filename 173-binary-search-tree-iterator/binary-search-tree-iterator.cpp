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
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        if(root == NULL) return;

        st.push(root);
        auto curr = root;

        while(curr->left != NULL){
            st.push(curr->left);
            curr = curr->left;
        }
    }
    
    int next() {
        if(st.size() == 0) return -1;

        auto top = st.top();
        st.pop();
        if(top->right!= NULL){
            st.push(top->right);
            auto curr = top->right;
            while(curr->left != NULL){
                st.push(curr->left);
                curr = curr->left;
            }
        }

        return top->val;
    }
    
    bool hasNext() {
        if(st.size() > 0) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */