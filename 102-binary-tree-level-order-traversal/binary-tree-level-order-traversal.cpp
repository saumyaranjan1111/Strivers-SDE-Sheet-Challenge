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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<pair<TreeNode*, int>> q;
        if(root == NULL) return ans;
        q.push({root, 0});

        while(!q.empty()){

            int currsize = q.size();
            vector<int> temp;

            for(int i = 0; i<currsize; i++){
                auto front = q.front();
                auto node = front.first;
                auto level = front.second;

                q.pop();

                temp.push_back(node->val);

                if(node->left != NULL){
                    q.push({node->left, level+1});
                }
                if(node->right != NULL){
                    q.push({node->right, level+1});
                }

            }
            ans.push_back(temp);       
        }
        return ans;
    }
};