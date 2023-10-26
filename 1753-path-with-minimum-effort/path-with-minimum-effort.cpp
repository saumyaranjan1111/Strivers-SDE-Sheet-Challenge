class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> mineffort(n, vector<int>(m, INT_MAX));
        mineffort[0][0] = 0;
        set<pair<int, pair<int, int>>> st;

        st.insert({0, {0, 0}});

        while(!st.empty()){
            auto temp = *(st.begin());
            int parenteffort = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            if(row == n-1 && col == m-1){
                // this final node is about to go out of the pq, that means that there exists no node which will contain the same row and col with a lower effort since priority queue will spit out the lowest effort node first and hence even if there are other instances of the same node in the pq, we can be assured that those all contain efforts more than this one
                return parenteffort;
            }
            st.erase(st.begin());

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for(int i = 0; i<4; i++){
                int crow = row + dr[i];
                int ccol = col + dc[i];

                if(crow>=0 && crow<n && ccol>=0 && ccol<m){

                    int effortfromparent = abs(heights[row][col] - heights[crow][ccol]);
                    
                    // minimum effor for this current path, would be the maximum of the min effort till now in this path, and the new jump that we are trying to make
                    // if this new jump has an effort that is greater than the greatest effort in this path till now, then the new effort of this path would be the new effort and hence when we reach crow, ccol using this path, we will have an effort equal to mineffortfromcurrentpath
                    int mineffortfromcurrentpath = max(parenteffort, effortfromparent);

                    if(mineffortfromcurrentpath < mineffort[crow][ccol]){
                        // if this path is better than all the paths that lead upto this crow, ccol till now, then update the min effort needed to reach crow, ccol 
                        mineffort[crow][ccol] = mineffortfromcurrentpath;
                        st.insert({mineffortfromcurrentpath, {crow, ccol}});
                    }
                }
            }
        }
        return -1;

    }
};