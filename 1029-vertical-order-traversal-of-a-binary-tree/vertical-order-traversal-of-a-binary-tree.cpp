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
    void solve(TreeNode* root, int h, int level, map<int, map<int, multiset<int>>>&mp){
        if(root == NULL) return;

        mp[h][level].insert(root->val);

        solve(root->left, h-1, level+1, mp);
        solve(root->right, h+1, level+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int, map<int, multiset<int>>> mp;

        solve(root, 0, 0, mp);

        for(auto it = mp.begin(); it!=mp.end(); it++){
            vector<int> temp;
            auto hmap = it->second;
            for(auto it2 = hmap.begin(); it2!=hmap.end(); it2++){
                auto sett = it2->second;
                for(auto it3 = sett.begin(); it3!=sett.end(); it3++){
                    temp.push_back(*it3);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};