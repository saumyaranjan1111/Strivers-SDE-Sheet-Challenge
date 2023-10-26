#define mod (int)(1e9 + 7)
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        map<long long, long long> dp;
        for(int i = 0; i<arr.size(); i++){
            dp[arr[i]] = 1;
        }

        for(auto it = dp.begin(); it!=dp.end(); it++){
            long long num = it->first;
            long long indicount = 0;
            for(int i = 2; i<=(int)sqrt(num); i++){
                long long a = i;
                long long b = num/i;
                if(a*b == num){
                    if(a==b){
                        // 1
                        if(dp.find(a) != dp.end()) indicount = (indicount%mod + (dp[a]%mod * dp[a]%mod)%mod)%mod;
                    }
                    else{
                        if(dp.find(a) != dp.end() && dp.find(b) != dp.end()){
                            indicount = (indicount%mod + (dp[a]%mod * dp[b]%mod * 2)%mod)%mod;
                        }
                    }
                }
            }
            dp[num] += indicount%mod;
        }

        int count = 0;
        for(auto it = dp.begin(); it!= dp.end(); it++){
            // cout<<it->first<<" "<<it->second<<endl;
            count = (count%mod + it->second%mod)%mod;
        }
        return count;
    }
};