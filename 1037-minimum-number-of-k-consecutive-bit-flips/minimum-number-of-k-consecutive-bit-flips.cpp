using ll = long long;
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ll n = nums.size();
        ll count = 0;
        deque<ll> zero, one;
        deque<ll>* zeroptr = &zero;
        deque<ll>* oneptr = &one;
        for(ll i = 0; i<k; i++){
            if(nums[i] == 1) one.push_back(i);
            else zero.push_back(i);
        }

        ll l = 0;
        for(ll r = k; r<=n; r++){
            l = r-k;
            while(!(*zeroptr).empty() && (*zeroptr).front()<l){
                (*zeroptr).pop_front();
            }
            while(!(*oneptr).empty() && (*oneptr).front()<l){
                (*oneptr).pop_front();
            }


            // flip only when the first element of (*zeroptr) == l
            if(l == (*zeroptr).front()){
                // flip
                ll val = (*oneptr).empty() ? 1e15 : (*oneptr).front();
                while(!(*zeroptr).empty() && (*zeroptr).front() < (*oneptr).front()){
                    (*zeroptr).pop_front();
                }
                deque<ll>* temp = zeroptr;
                zeroptr = oneptr;
                oneptr = temp;
                count++;
            }

            if(r == n) break;
            if(nums[r] == 1) (*oneptr).push_back(r);
            else (*zeroptr).push_back(r);
        }

        if((*zeroptr).empty()) return count;
        return -1;
    }
};