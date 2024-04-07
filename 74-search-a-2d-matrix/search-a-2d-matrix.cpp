using ll = long long;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ll n = matrix.size();
        ll m = matrix[0].size();
        ll rowlow = 0, rowhigh = n-1;
        while(rowlow <= rowhigh){
            ll rowmid = rowlow + (rowhigh-rowlow)/2;
            if(matrix[rowmid][0] > target){
                rowhigh = rowmid-1;
            } else if(matrix[rowmid][m-1] < target){
                rowlow = rowmid+1;
            } else {
                ll low = 0, high = m-1;
                while(low <= high){
                    ll mid = low + (high-low)/2;
                    if(matrix[rowmid][mid] < target){
                        low = mid+1;
                    } else if(matrix[rowmid][mid] > target){
                        high = mid-1;
                    } else {
                        return true;
                    }
                }
                break;
            }
        }
        return false;
    }
};