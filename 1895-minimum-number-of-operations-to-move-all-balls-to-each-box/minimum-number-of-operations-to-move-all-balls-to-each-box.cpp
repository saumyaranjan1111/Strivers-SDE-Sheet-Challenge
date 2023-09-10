class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> rightones(n, 0);
        // rightones[i] : no of ones to the right of i
        int ones = 0;
        for(auto e:boxes){
            if(e == '1') ones++;
        }

        if(boxes[0] == '1') ones--;
        rightones[0] = ones;

        for(int i = 1; i<boxes.size(); i++){
            if(boxes[i]=='1') ones--;

            rightones[i] = ones;
        }
        vector<int> leftones(n, 0);
        leftones[0] = 0;
        if(boxes[0] == '1') ones++;

        for(int i = 1; i<boxes.size(); i++){
            leftones[i] = ones;
            if(boxes[i]=='1') ones++;
        }
        int startscore = 0;
    
        for(int i = 1; i<boxes.size(); i++){
            if(boxes[i] == '1'){
                startscore += i;
            }
        }
        vector<int> ans(boxes.size(), 0);
        ans[0] = startscore;
        for(int i = 1; i<boxes.size(); i++){
            ans[i] = ans[i-1] - rightones[i-1] + leftones[i];
        }
        return ans;
    }
};