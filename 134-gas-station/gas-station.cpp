class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int req = 0;
        int totalfuel = 0;
        for(auto g:gas) totalfuel+=g;
        for(auto c:cost) req+=c;

        // if the total fuel required is less than what is available, then return -1
        if(req > totalfuel) return -1;

        // if the fuel adding all the stations is sufficient
        // use kadane's algorithm
        // if the value of the current fuel remains>=0 for atleast n consecutive elements, then it is possible
        vector<int> vals;
        for(int i = 0; i<n; i++){
            vals.push_back(gas[i] - cost[i]);
        }
        for(int i = 0; i<n-1; i++){
            vals.push_back(gas[i] - cost[i]);
        }

        int curr = 0;
        int count = 0;
        for(int i = 0; i<vals.size(); i++){
            if(curr + vals[i] < 0){
                curr = 0;
                count = 0;
            }
            else{
                curr += vals[i];
                count++;
            }
            if(count == n) return i - count + 1;
        }
        return -1;

    }
};