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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // level order traversal using dequeue instead of queue
        deque<TreeNode*> q;
        if(root == NULL) return ans;
        q.push_front(root);

        bool left = true;

        while(!q.empty()){
            
            if(left){
                int currsize = q.size();
                vector<int> temp;
                for(int i = 0; i<currsize; i++){
                    auto node = q.front();
                    q.pop_front();

                    temp.push_back(node->val);

                    if(node->left != NULL){
                        q.push_back(node->left);
                    }
                    if(node->right != NULL){
                        q.push_back(node->right);
                    }
                }
                ans.push_back(temp);
                left = false;
            }
            else{
                int currsize = q.size();
                vector<int> temp;
                for(int i = 0; i<currsize; i++){
                    auto node = q.back();
                    q.pop_back();

                    temp.push_back(node->val);

                    if(node->right != NULL){
                        q.push_front(node->right);
                    }
                    if(node->left != NULL){
                        q.push_front(node->left);
                    }
                }
                ans.push_back(temp);
                left = true;
            }
            
        }
        return ans;

    }
};