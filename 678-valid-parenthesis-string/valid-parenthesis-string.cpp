class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftbrackets;
        stack<int> stars;

        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(c == '('){
                leftbrackets.push(i);
            } else if(c == '*'){
                stars.push(i);
            } else {
                // check if we can pop out a left bracket
                // if not then check if we can pop out a star
                // if both are not possible then this right bracket cannot be satisfied ever
                // hence return false
                if(leftbrackets.size() > 0){
                    leftbrackets.pop();
                }
                else if(stars.size() > 0){
                    stars.pop();
                }
                else return false;
            }
        }

        // now that we have taken care of all the right brackets = ")"
        // the only ones remaining in are '(' and '*'
        // just ensure that for each '(' there is one '*' to the right of it

        while(!leftbrackets.empty()){
            if(stars.empty()) return false;

            if(leftbrackets.top() > stars.top()) return false;

            leftbrackets.pop();
            stars.pop();
        }

        return leftbrackets.empty();
    }
};