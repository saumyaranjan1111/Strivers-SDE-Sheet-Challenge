class Solution {
public:
    bool winnerOfGame(string colors) {
        int remchancesa = 0;
        int remchancesb = 0;

        int n= colors.size();
        if(n < 3) return false;

        int i = 0, j = 1, k = 2;
        while(k < n){
            if(colors[i] == colors[j] && colors[j] == colors[k]){
                if(colors[i] == 'A'){
                    remchancesa++;
                }
                else remchancesb++;
            }
            i++; j++; k++;
        }

        if(remchancesa > remchancesb) return true;
        return false; 
    }
};