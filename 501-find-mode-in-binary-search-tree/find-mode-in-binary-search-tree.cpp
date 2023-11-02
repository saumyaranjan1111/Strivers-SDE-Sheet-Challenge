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
    int maxcount = 0;
    int currcount = 0;
    unordered_set<int> st;
    int prev = INT_MIN;
private:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
// the idea is that the inorder traversal of a bst traverses the nodes in ascending order

// so if the current node is equal to the previous node in the preorder traversal, then increase the current count by 1
// else reset the currcount to 1
        
        inorder(root->left, ans);

        if(root->val == prev){
            currcount++;
        }
        else {
            currcount = 1;
        }

// now check if the current count is greater than the maxcount, if that is the case, then make maxcount equal to currcount, since this is the new maxcount, all of the elements previously inserted would be worthless now, so clear them
// insert this new element into the set
        if(currcount > maxcount){
            maxcount = currcount;
            st.clear();
            st.insert(root->val);
        }
        else if(currcount == maxcount){
            // if the current count is equal tot he maxcount, then this node value is also one of the modes until now, so insert it into the set
            st.insert(root->val);
        }

        // set the prev to be the root val, so that , whatever node is processed afterwards knows that this was the last node processed before it (ascending order since this is a bst)
        prev = root->val;

        inorder(root->right, ans);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        
        for(auto it = st.begin(); it!= st.end(); it++){
            ans.push_back(*it);
        }
        return ans;
    }
};