class Solution {
public:
    void dfs(int left, int right, int n, string curr, vector<string>& res){
        if(curr.size() == 2*n){
            // we have used up all the 2n characters and made a string curr, now append this string to the vector of strings 
            res.push_back(curr);
        }

        // we have two choices, either append the '(' or ')'
        // for the string to be valid, we can append ')' only when the count of '(' is greater than ')' in the present string, if not so, then appending a ')' will make our string invalid
        // if we want to append '(', then we can do so if the count of already present '(' is smaller than n

        if(left < n){
            dfs(left + 1, right, n, curr + '(', res);
        }
        if(left > right){
            dfs(left, right + 1, n, curr + ')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int left = 0, right = 0;
        string currstring = "";
        dfs(left, right, n, currstring, res);
        return res;
    }
};