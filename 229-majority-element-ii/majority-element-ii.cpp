class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;

        for(auto ele : nums)
        {
            if(ele == ele1)
            {
                count1++;
            }
            else if(ele == ele2)
            {
                count2++;
            }
            else if(count1 == 0)
            {
                ele1 = ele;
                count1 = 1;
            }
            else if(count2 == 0)
            {
                ele2 = ele;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(auto e : nums)
        {
            if(e == ele1) count1++;
            if(e == ele2) count2++;
        }
        vector<int> ans;
        if(count1 > nums.size()/3) ans.push_back(ele1);
        if(count2 > nums.size()/3) ans.push_back(ele2);
        return ans;
    }
};