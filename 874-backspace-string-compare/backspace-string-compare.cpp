class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        int count1 = 0;
        int count2 = 0;
        int i = n-1;
        int j = m-1;

        while(i>=0 || j>=0){
            // run the outer loop until one of the strings becomes empty

            // delete all the characters until the first undeletable character
            while(i>=0){
                if(s[i] == '#'){
                    // if the current char is a hash, then increase the no of characters that we still need to delete
                    count1++;
                    i--;
                }
                else{
                    // if the current char is not a hash, then check if the count of characters that we need to delete is 0 or not, if the no is 0, then stop the loop , if not, then delete the curr char( reduce the no of characters we still need to delete )
                    if(count1 > 0){
                        count1--;
                        i--;
                    }
                    else {
                        break;
                    }

                }
            }

            while(j>=0){
                if(t[j] == '#'){
                    count2++;
                    j--;
                }
                else{
                    if(count2 > 0){
                        count2--;
                        j--;
                    }
                    else {
                        break;
                    }
                }
            }


            // if any one of the strings becomes "empty" before the other, return false
            if((i<0 && j>=0) || (j<0 && i>=0)){
                return false;
            }
            
            // after the running of the above two loops i and j are at the undeletable characters of both the strings

            // if those two chars are not equal return false
            if(i>=0 && j>=0 && s[i] != t[j]) return false;

            // else go to the left character of both and run the loop again
            i--;
            j--;
        }

        return true;
    }
};