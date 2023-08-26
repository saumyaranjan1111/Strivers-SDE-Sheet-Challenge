class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // naive : sort the array, find the kth element from the back
        // time : nlogn, space : 1

        // use a minheap of size k

        priority_queue<int> q;
        for(int i = 0; i<k; i++){
            q.push(-nums[i]);
        }

        for(int i = k; i<nums.size(); i++){
            if(-q.top() < nums[i]){
                q.push(-nums[i]);
                q.pop();
            }
        }

        return (-q.top());
    }
};