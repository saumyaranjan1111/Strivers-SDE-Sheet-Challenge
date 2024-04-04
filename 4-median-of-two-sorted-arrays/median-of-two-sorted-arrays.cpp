using ll = long long;
class Solution {
public:
    void shuffle(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int>> &right){
        while(left.size() > right.size() + 1){
            ll num = left.top(); 
            left.pop();
            right.push(num);
        }
        while(right.size() > left.size()){
            ll num = right.top();
            right.pop();
            left.push(num);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // right = minheap, left = maxheap
        priority_queue <int, vector<int>, greater<int> > right;
        priority_queue <int> left; 

        for(int i = 0; i<nums1.size(); i++){
            if(!right.empty() && right.top() < nums1[i]){
                right.push(nums1[i]);
            } else {
                left.push(nums1[i]);
            }
            shuffle(left, right);
        }

        for(int i = 0; i<nums2.size(); i++){
            if(!right.empty() && right.top() < nums2[i]){
                right.push(nums2[i]);
            } else {
                left.push(nums2[i]);
            }
            shuffle(left, right);
        }
        double ans = left.size() != right.size() ? (double)left.top() : ((double)left.top() + (double)right.top())/2;
        return ans;
    }
};