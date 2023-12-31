/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lcm(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        if(root->val < p->val && root->val < q->val)
        {
            return lcm(root->right, p, q);
        }
        else if(root->val > p->val && root->val > q->val)
        {
            return lcm(root->left, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcm(root, p, q);
    }
};