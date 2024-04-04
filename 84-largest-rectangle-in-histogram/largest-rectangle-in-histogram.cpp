using ll = long long;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // how much can you expand the current bar height to the left and to the right
        ll n = heights.size();
        ll maxarea = 0;
        vector<ll> area(n, 0);
        stack<pair<ll, ll>> pes;
        stack<pair<ll, ll>> nes;
        for(ll i = 0; i<n; i++){
            ll leftarea = 0;
            
            // try to see if this bar can be extended to the left
            while(!pes.empty() && pes.top().first >= heights[i]){
                pes.pop();
            }

            if(!pes.empty()){
                leftarea = heights[i] * (i-pes.top().second-1);
            } else {
                leftarea = heights[i] * (i);
            }
            
            pes.push({heights[i], i});
            area[i] += leftarea;
        }

        for(ll i = n-1; i>=0; i--){
            ll rightarea = 0;
            while(!nes.empty() && nes.top().first >= heights[i]){
                nes.pop();
            }

            if(!nes.empty()){
                rightarea = heights[i] * (nes.top().second-i);
            } else {
                rightarea = heights[i] * (n-i);
            }

            nes.push({heights[i], i});
            area[i] += rightarea;
            maxarea = max(maxarea, area[i]);
        }

        return maxarea;
    }
};