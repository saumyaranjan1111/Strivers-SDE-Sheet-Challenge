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
    int count = 0;
private:
    pair<int, int> countnodes(TreeNode* node){
        if(node == NULL) return {0, 0};

        pair<int, int> left = countnodes(node->left);
        pair<int, int> right = countnodes(node->right);

        int leftsum = left.first;
        int leftnum = left.second;

        int rightsum = right.first;
        int rightnum = right.second;

        int totalsum = leftsum + rightsum + node->val;
        int totalnodes = leftnum + rightnum + 1;

        if(totalnodes != 0)
            if(totalsum/totalnodes == node->val) count++;

        return { leftsum + rightsum + node->val, leftnum + rightnum + 1 };
    }
public:
    int averageOfSubtree(TreeNode* root) {
        countnodes(root);
        return count;
    }
};