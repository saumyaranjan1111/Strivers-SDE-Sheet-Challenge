using ll = long long;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ll n = matrix.size();
        ll m = matrix[0].size();

        ll l = 0, r = n-1;
        ll left = 0, right = m-1;

        while(l <= r && left <= right){
            while(l <= r && matrix[l][right] < target){
                l++;
            }
            while(r >= l && matrix[r][left] > target){
                r--;
            }

            if(l > r) break;

            while(left <= right && matrix[r][left] < target){
                left++;
            }
            while(right >= left && matrix[l][right] > target){
                right--;
            }

            if(left > right) break;
            if(matrix[l][left] == target || matrix[l][right] == target || matrix[r][left] == target || matrix[r][right] == target) return true;
        }
        return false;
    }
};