class Solution {
public:
    bool bfs(int root, vector<bool>& vis, vector<int>& left, vector<int>& right){
        queue<int> q;
        q.push(root);
        vis[root] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            int leftnode = left[node];
            int rightnode = right[node];

            if(leftnode!=-1){
                if(vis[leftnode]) return false;
                else {
                    q.push(leftnode);
                    vis[leftnode] = true;
                }
            }
            if(rightnode!=-1){
                if(vis[rightnode]) return false;
                else {
                    q.push(rightnode);
                    vis[rightnode] = true;
                }
            }
        }
        return true;
    }
    vector<int> findRoot(int n, vector<int>& left, vector<int>& right){
        vector<bool> child(n, false);
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(left[i] != -1)
            child[left[i]] = true;

            if(right[i] != -1)
            child[right[i]] = true;
        }
        for(int i = 0; i<n; i++){
            if(!child[i]) ans.push_back(i);
        }
        return ans;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n, false);
        vector<int> roots = findRoot(n, leftChild, rightChild);

        if(roots.size() != 1) return false;

        bool ans = bfs(roots[0], vis, leftChild, rightChild);
        for(int i = 0; i<n; i++){
            if(!vis[i]) return false;
        }

        return ans;
    }
};