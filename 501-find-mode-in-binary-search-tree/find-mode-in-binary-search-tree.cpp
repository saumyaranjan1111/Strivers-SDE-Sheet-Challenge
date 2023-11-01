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
    void count(TreeNode* node, unordered_map<int, int>& mp){
        if(node == NULL) return;
        mp[node->val]++;
        count(node->left, mp);
        count(node->right, mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        count(root, mp);
        int maxfreq = 0;
        vector<int> ans;
        for(auto it = mp.begin(); it!= mp.end(); it++){
            maxfreq = max(maxfreq, it->second);
        }

        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second == maxfreq)
            ans.push_back(it->first);
        }
        return ans;
    }
};