class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1) return 1;
        vector<int> dist(n, 1);

        for(int i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                if(dist[i] <= dist[i-1]) dist[i]+=dist[i-1] - dist[i] + 1;
            }
        }

        for(int i = n-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                if(dist[i] <= dist[i+1]) dist[i]+=dist[i+1] - dist[i] + 1;
            }
        }

        int count = 0;
        for(auto e:dist) count+=e;
        return count;
        
    }
};