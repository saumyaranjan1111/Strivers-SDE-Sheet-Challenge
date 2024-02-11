using ll = long long ;
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        // it is always possible to make a smaller sized palindrome, if we can make a larger sized one
        // but the opposite is not true, so if we make a smaller sized palindrome then it is not guaranteed that we will be able to form a larger sized one
        // so for the same set of characters that we have at hand, it is better greedily to make a smaller sized palindrome
        vector<ll> sizes;
        for(auto word : words){
            sizes.push_back(word.size());
        }
        sort(sizes.begin(), sizes.end());

        map<char, ll> mp;
        for(auto word : words){
            for(auto ch : word){
                mp[ch]++;
            }
        }

        ll pairs = 0, nonpairs = 0;
        for(auto it = mp.begin(); it!=mp.end(); it++){
            pairs+= it->second/2;
            nonpairs+= it->second%2;
        }

        int count = 0;
        for(auto x: sizes){
            // check whether it is possible to make a palindrom of size = x
            // if x is even then check if there are atleast x/2 pairs left
            // if x is odd then check if there are atleast x/2 pairs left and at least 1 nonpair left
            if(x%2 == 0){
                if(x/2 <= pairs){
                    count++;
                    pairs-=x/2;
                } else break;
            } else {
                if(x/2 <= pairs){
                    // if nonpairs are available use nonpairs, else check if the pairs are enough to supply that extra character for the middle
                    if(nonpairs >= 1){
                        nonpairs-=1;
                        pairs-=x/2;
                        count++;
                    } else {
                        // nonpairs are not enough, we have to take one character from the pairs
                        if(x/2 + 1 <= pairs){
                            pairs-= x/2 + 1;
                            nonpairs++;
                            count++;
                        } else break;
                    }
                } else break;
            }
        }
        return count;
    }
};