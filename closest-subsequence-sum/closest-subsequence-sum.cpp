#define ll long long
class Solution {
public:
    void prll(vector<ll>&arr)
    {
        for(auto e:arr) cout<<e<<" ";
        cout<<endl;
    }
    void generateallsubsets(ll ind, ll currsum, vector<ll>& arr, vector<ll>& ans)
    {
        if(ind == arr.size())
        {
            ans.push_back(currsum);
            return;
        }

        // take
        generateallsubsets(ind+1, currsum+arr[ind], arr, ans);

        // dont take
        generateallsubsets(ind+1, currsum, arr, ans);
    }
    vector<ll> generatesumsofallsubsets(vector<ll> &arr)
    {
        vector<ll> ans;
        generateallsubsets(0, 0, arr, ans);
        return ans;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        // approach 1: we can try to do this by using the brute force method but that wont work, since 2^40 == 10^12 -> tle
        // approach 2: meet in the middle
        ll n = nums.size();
        vector<ll> left;
        vector<ll> right;
        for(ll i = 0; i<n/2; i++)
        {
            left.push_back(nums[i]);
        }
        for(ll i = n/2; i<n; i++)
        {
            right.push_back(nums[i]);
        }

        // now generate all the subsets of the left array and store their sums 
        vector<ll> leftsums = generatesumsofallsubsets(left);
        // prll(leftsums);
        vector<ll> rightsums = generatesumsofallsubsets(right);
        
        sort(rightsums.begin(), rightsums.end());
        // prll(rightsums);
        ll ans = LONG_LONG_MAX;
        for(ll i = 0; i<leftsums.size(); i++)
        {
            ll eleleft = leftsums[i];
            ll elerightind = lower_bound(rightsums.begin(), rightsums.end(), goal-eleleft) - rightsums.begin();

            // we need the element just <= goal-eleleft, if goal-eleleft is not present in the array then lowerbound gives the element just >goal-eleleft
            if(elerightind > 0)
            ans = min(ans, abs(goal - eleleft - rightsums[elerightind-1]));
            if(elerightind < rightsums.size())
            ans = min(ans, abs(goal - eleleft - rightsums[elerightind]));

            // if leftele = x, search for the largest element in the right array such that x+y <= goal
            // equivalent to searching for the lower bound of goal - x in the right array, this will give the just smallest element from goal-x, therefore x+this element <= goal
            // the answer can be this
        }
        return ans;
    }
};