using ll = long long;
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        ll n = nums.size(); 
        vector<int> &a = nums;
        // if any no is flipped odd no of times then it changes, if even then it remains the same
        // flip all the 0s odd no of times and all the ones that are made in doing that and previous ones too, even no of times
        // to do this, if you encounter a 0 at the start of the window, we will have to flip it since we cannot leave it as it is, as the order in which we flip a bit does not matter, so let us go from left to right and whenever we encounter a 0 at the start of the window, we will need to flip it in a greedy way regardless as leaving it as it is is not an option, since we will have to do another flip operation if we leave it as it is right now, and that flip operation is the same if done now or later, so we will go from left to right, and if we encounter a 0 at the front of the window, we will flip the window, and keep track of number of flips that have taken place in the current window till now, so that we can judge whether the current bit is a 0 or a 1
        // this is the main crux of the problem : figuring out how to keep track of the number of flips that have happened to the current bit (the start of the window) in constant or linear time
        // let us have a queue, if we perform a flip at an index i, it should store the ending of that effect of the flip operation : i + k - 1, which will tell us at any point of time, which flips are yet in effect that is the no of indices that are inside the queue which are greater than the current index at any moment, are flips which have their starting points before the current windows start, and since they are > the current index, their ends are after the current index, hence they are still in effect, so the flips which are in effect if they are even ( then that means that if the current bit is 0, then it still is a 0 after the total effect of the flips, and if the bit is 1, then also it remains a 1, so if it is a zero(effectively), then we need to perform a flip at this point, and if it is an 1 we leave it as it is), 
        // similarly if the no of flips are odd, that means if the current bit is a 0, then after the effects of all the flips it will turn into a 1, so we leave it, if the curren tbit is 1, then it would have turned to be 0 as a result of the effective odd no of window flips, so we need to perform a flipl at this index

        queue<ll> q;
        // this queue will contain the ending indices of all the flip operations
        
        ll count = 0;
        for(ll i = 0; i<n; i++){
            if((a[i] == 0 && q.size()%2 == 0) || (a[i] == 1 && q.size()%2 != 0)){
                // if the original bit was 0 and the "effective flips" that have been applied till now are even 
                // or if the og bit was 1 and the "effective flips" that have been applied till now are odd
                // in both these cases , the bit effectively is currently 0
                // so we need to perform a flip

                // flip
                if(i+k-1 < n){
                    count++;
                    q.push(i+k-1);
                } else {
                    // we need to perform a flip here, but we cannot 
                    // therefore return -1
                    return -1;
                }

            }
                // now the most important part : how are we saying that the no of elements in the queue at any present time are the "active" flips that apply to the current index, that is we will eliminate every element from the queue which is < current index, this ensures that all the flips which were not able to effect the current index are removed from the queue, and only those remain whose end was >= current index, and hence currently affect the current bit
            if(!q.empty() && q.front() <= i){
                q.pop();
            }
        }

        return count;
    }
};