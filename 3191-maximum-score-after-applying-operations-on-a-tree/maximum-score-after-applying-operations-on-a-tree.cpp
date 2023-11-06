class Solution {
private:
    long long sumofvaluestobeleftinthetree(int node, int parent, vector<vector<int>>& tree, vector<int>& values){
        
        if(tree[node].size() == 1 && parent != -1){
            // if the no of children of a node is 1 and the parent is not -1, then it will be a leaf node
            // we did not just use tree[node].size() == 1 because it can also apply to the case where the root node has just one child, and in that case our function will return the value of the root node without checking further down
            // hence to specify that the node is a leaf node, we need to put the parent!=-1 condition
            // this is a leaf node
            // imagine what should this function return in the case where there is only one node which is this node, ofc we cant remove this node, as the one node in each path condition would be violated, so we just send the value of this node upwards
            return values[node];
        }

        long long minvalsfromchildren = 0;
        for(auto child : tree[node]){
            if(child == parent) continue;

            minvalsfromchildren += sumofvaluestobeleftinthetree(child, node, tree, values);
        }
        if(minvalsfromchildren < values[node]){
            // the minimum sum of all the nodes to be left in the tree is smaller than the value of the current node
            // so we dont need to change anything, these are the nodes that need to be left in their respective subtrees in the final tree
            // so just send this answer upwards
            return minvalsfromchildren;
        }
        else{
            // the value of the current node is smaller than the sum of all the nodes to be left in the final tree, in their respective subtrees
            // so instead of leaving those nodes in the final subtree, we would prefer to leave this current node in the final subtree
            return values[node];
        }

        return -1;
    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> tree(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        long long totalvalue = 0;
        for(auto val : values){
            totalvalue+=val;
        }

        long long sumofnodesleft = sumofvaluestobeleftinthetree(0, -1, tree, values);

        long long score = totalvalue - sumofnodesleft;

        return score;
    }
};