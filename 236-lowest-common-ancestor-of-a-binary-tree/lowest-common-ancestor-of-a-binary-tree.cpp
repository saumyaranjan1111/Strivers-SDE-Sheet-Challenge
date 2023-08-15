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
    TreeNode* lca(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == NULL) return NULL;
        
         // if the root is any one of the two nodes then return the root as it will be the lca of both the nodes
        if(root == p || root == q) return root;

        auto left = lca(root->left, p, q);
        auto right = lca(root->right, p, q);


        if(left && right){
            // if both the paths are returning non-null values then
            // we found one node in the left and one on the right
            // then the current node is the lca
            return root;
        }
        else if(left && !right){
            // the right call returned null
            // we did not find p or q on the right, but found one of p, or q on the left
            // p and q both lie on the left and their lca also lies on the left so we should search on the left
            return left;
        }
        else if(!left && right){
            // the left returned null, the right returned not null, therefore, 
            return right;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // two cases: 
        // first : both the nodes lie on the same path
        // second : both the nodes lie on different paths
        // if both lie on the same path and the current node is one of the two nodes, then the current node is the lca
        // if both lie on the same path but the current node is not one of the two nodes that we are searching for, then go to the direction (left or right) in which both the nodes were found
        // if both lie on different paths, the current node for which both the nodes were found to be on two different sides would be the lca

        return lca(root, p, q);
    }
};