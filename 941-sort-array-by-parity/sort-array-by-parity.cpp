class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n = a.size();
        int i = 0, j = n-1;

        while(i<j){
            while(i<n && a[i] % 2 == 0) i++;
            while(j>=0 && a[j] % 2 != 0) j--;
            if(i>=j) break;
            swap(a[i], a[j]);
            i++; j--;
        }
        return a;

    }
};