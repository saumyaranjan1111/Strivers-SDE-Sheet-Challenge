class Solution {
private:
    long long dfs(int node, vector<vector<int>> &tree, int parent, vector<int>& values){

        // if the current node is a leaf node
        // assume that the leaf node is the minimum in that path for now and send it upwards, 
        // if it not the minimum in that path, it will be taken care of up the line
        if(tree[node].size()==1 && node!=0) 
        {
            // if the current node is a leafnode and it is not the root node, then the min value that we can keep in this 
            return values[node];
        }

        // go through all the children subtrees and find the sum of all the min nodes of the corresponding subtrees that we plan to leave in the final tree
        // dfs(child) : gives the min node in the path from root->child->leaf
        // so sumofsubtrees will contain the sum of all the min nodes that we plan to leave in the final subtree
        // if we find that the sumofsubtrees ( i.e. the nodes below the current node that we plan to leave in the tree) < currentnodevalue ( that means that we can still send the sum of those nodes upwards )
        // if we find that the sumofsubtrees > current node value ( we have found a better node to keep in the final subtree ) so we send this value upwards instead
        long long sumofsubtrees = 0;
        for(auto child : tree[node]){
            if(child == parent) continue;
            sumofsubtrees += dfs(child, tree, node, values);
        }

        return min(sumofsubtrees, (long long)values[node]);

    }
    long long summ(int root, vector<vector<int>> &tree, int parent, vector<int>& values){
        
        long long sum = 0;
        for(auto child : tree[root]){
            if(child == parent) continue;
            sum+= summ(child, tree, root, values);
        }
        sum += values[root];
        return sum;
    }
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> tree(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        long long minval = dfs(0, tree, -1, values);
        long long totalsum = summ(0, tree, -1, values);

        return totalsum - minval;
    }
};