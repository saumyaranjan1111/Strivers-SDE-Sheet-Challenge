class Solution {
public:
    bool backtrack(vector < int > & nums, int i, int reqSum, int currSum, vector < bool > & isVisited, int k) {

  if (reqSum == currSum)
  {
      if(k==1) return true;
      return backtrack(nums, 0, reqSum, 0, isVisited, k - 1);
  }
    if (i == nums.size())
    return false;
    for(int j = i; j<nums.size(); j++)
    {
        if (!isVisited[j] && nums[j] + currSum <= reqSum) {
            isVisited[j] = true;
            if (backtrack(nums, j + 1, reqSum, currSum + nums[j], isVisited, k))
            return true;
            isVisited[j] = false;
        }
    }
  return false;
}

bool canPartitionKSubsets(vector < int > & nums, int k) {

  int sum = 0;
  for (int ele: nums) sum += ele;
  if (sum % k != 0) return false;

  int n = nums.size();
    if(n<k) return false;
    if(n==1 && k==1) return true;
    // if(k==1) return true;
  vector < bool > vis(n, false);
  vis[0] = true;
  return backtrack(nums, 0, sum / k, nums[0], vis, k);
}
};
