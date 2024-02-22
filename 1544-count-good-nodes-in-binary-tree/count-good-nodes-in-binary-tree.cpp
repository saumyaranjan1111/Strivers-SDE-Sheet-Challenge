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
    void dfs(TreeNode* root, int &count, multiset<int>& curr){
        if(!root) return;

        curr.insert(root->val);
        auto it = curr.end();
        it--;
        if(*it == root->val){
            count++;
        }
        dfs(root->left, count, curr);
        dfs(root->right, count, curr);
        curr.erase(curr.find(root->val));
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        multiset<int> curr;
        dfs(root, count, curr);
        return count;
    }
};