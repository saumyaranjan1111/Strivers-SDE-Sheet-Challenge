class KthLargest {
public:
    // build a min heap that contains the largest k elements of the arrray
    multiset<int> minheap;
    int minsize;
    KthLargest(int k, vector<int>& nums) {
        minsize = k;
        if(nums.size() < k){
            for(int i = 0; i<nums.size(); i++){
                minheap.insert(nums[i]);
            }

        } else {

            for(int i = 0; i<k; i++){
                minheap.insert(nums[i]);
            }
            for(int i = k; i<nums.size(); i++){
                if(nums[i] > *minheap.begin()){
                    minheap.erase(minheap.begin());
                    minheap.insert(nums[i]);
                }
            }
        }
        // now minheap contains the k largest elements present in the array
    }
    
    int add(int val) {
        if(minheap.size() < minsize){
            minheap.insert(val);
            return *minheap.begin();
        }
        else if(val > *minheap.begin()){
            minheap.insert(val);
            minheap.erase(minheap.begin());
            return *minheap.begin();
        }
        return *minheap.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */