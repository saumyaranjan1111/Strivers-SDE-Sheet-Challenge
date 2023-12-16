class Solution {
public:
    int compress(vector<char>& chars) {

        int gcount = 1;
        int n = chars.size();
        vector<char> ans;
        if(chars.size() == 0) {
            chars = ans;
            return 0;
        }

        for(int i = 0; i<n; i++){
            int j = i+1;
            if(j < n){
                if(chars[j] == chars[i]){
                    // same group
                    gcount++;
                }
                else {
                    // diff group
                    if(gcount == 1){
                        // group count is just one
                        // store that char in ans
                        // and dont store the number of occurences
                        ans.push_back(chars[i]);

                        gcount = 1;
                    }
                    else {
                        // gcount>1
                        ans.push_back(chars[i]);
                        string occur = to_string(gcount);
                        for(auto c : occur){
                            ans.push_back(c);
                        }
                        // i++; 
                        gcount = 1;
                    }
                }
            }
            else {
                ans.push_back(chars[i]);
                if(gcount > 1){
                    string occurs = to_string(gcount);
                    for(auto c: occurs){
                        ans.push_back(c);
                    }
                }
            }
        }
        chars = ans;
        return ans.size();
    }
};