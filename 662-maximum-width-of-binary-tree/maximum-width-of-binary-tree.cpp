/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeTreeNode*left;
 *     TreeTreeNode*right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeTreeNode*left, TreeTreeNode*right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int ans = 0;
        queue < pair < TreeNode* , long long >> q;
        q.push({
            root,
            0
        });
        while (!q.empty()) {
            long long size = q.size();
            long long curMin = q.front().second;
            long long leftMost, rightMost;
            for (long long i = 0; i < size; i++) {
            long long cur_id = q.front().second - curMin; // subtracted to prevent long longeger overflow
            TreeNode* temp = q.front().first;
            q.pop();
            if (i == 0) leftMost = cur_id;
            if (i == size - 1) rightMost = cur_id;
            if (temp -> left)
                q.push({
                temp -> left,
                cur_id * 2 + 1
                });
            if (temp -> right)
                q.push({
                temp -> right,
                cur_id * 2 + 2
                });
            }
            ans = max(ans,(int)( rightMost - leftMost + 1));
        }
        return ans;
    }
};