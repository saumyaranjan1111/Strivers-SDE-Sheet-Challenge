#define ll long long
class Solution {
public:
    void prll(vector<ll>&arr)
    {
        for(auto e:arr) cout<<e<<" ";
        cout<<endl;
    }
    void generateallsubsets(ll ind, ll currsum, vector<ll>& arr, unordered_map<ll, vector<ll>>& ans, ll currsize)
    {
        if(ind == arr.size())
        {
            ans[currsize].push_back(currsum);
            return;
        }

        // take
        generateallsubsets(ind+1, currsum+arr[ind], arr, ans, currsize+1);

        // dont take
        generateallsubsets(ind+1, currsum, arr, ans, currsize);
    }
    unordered_map<ll, vector<ll>> generatesumsofallsubsets(vector<ll> &arr)
    {
        unordered_map<ll, vector<ll>> ans;
        ll currsize = 0;
        generateallsubsets(0, 0, arr, ans, currsize);
        return ans;
    }
    int minimumDifference(vector<int>& nums) {
        ll n = nums.size();
        ll sum = 0;
        for(auto e:nums)sum+=e;

        vector<ll> left, right;
        for(ll i = 0; i<n/2; i++)
        {
            left.push_back(nums[i]);
        }
        for(ll i = n/2; i<n; i++)
        {
            right.push_back(nums[i]);
        }

        ll ans = LONG_LONG_MAX;
        unordered_map<ll, vector<ll>> leftsums = generatesumsofallsubsets(left);
        unordered_map<ll, vector<ll>> rightsums = generatesumsofallsubsets(right);

        for(auto it = rightsums.begin(); it!=rightsums.end(); it++)
        {
            sort(it->second.begin(), it->second.end());
        }

        for(auto it = leftsums.begin(); it!=leftsums.end(); it++)
        {
            ll firstpartsize = it->first;
            ll secondpartsize = n/2 - firstpartsize;
            for(auto x:it->second)
            {
                ll lb = lower_bound(rightsums[secondpartsize].begin(), rightsums[secondpartsize].end(), (sum-2*x)/2) - rightsums[secondpartsize].begin();
                if(lb>0)
                {
                    ll y = rightsums[secondpartsize][lb-1];
                    ans = min(ans, abs(2*(x+y) - sum));
                    // cout<<x<<","<<y<<","<<abs(2*(x+y) - sum)<<" : "<<ans<<endl;
                }
                if(lb<rightsums[secondpartsize].size())
                {
                    ll y = rightsums[secondpartsize][lb];
                    ans = min(ans, abs(2*(x+y) - sum));
                    // cout<<x<<","<<y<<","<<abs(2*(x+y) - sum)<<" : "<<ans<<endl;
                }
                // cout<<endl;
            }
        }
        // ans = min(ans, abs(2*leftsums[n/2][0]-sum));
        // ans = min(ans, abs(2*rightsums[n/2][0]-sum));


        // for(auto it = leftsums.begin(); it!=leftsums.end(); it++)
        // {
        //     cout<<it->first<<":";
        //     prll(it->second);
        // }
        // for(auto it = rightsums.begin(); it!=rightsums.end(); it++)
        // {
        //     cout<<it->first<<":";
        //     prll(it->second);
        // }
        return ans;
    }
};