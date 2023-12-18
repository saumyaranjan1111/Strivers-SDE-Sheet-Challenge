class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;

        set<int> s1, s2;
        for(auto i: nums1) s1.insert(i);
        for(auto j: nums2) s2.insert(j);

        for(auto x: nums1){
            if(s2.find(x)!=s2.end()) s2.erase(x);
        }
        for(auto x: nums2){
            if(s1.find(x)!=s1.end()) s1.erase(x);
        }

        for(auto it = s1.begin(); it!=s1.end(); it++){
            ans1.push_back(*it);
        }
        for(auto it = s2.begin(); it!=s2.end(); it++){
            ans2.push_back(*it);
        }

        vector<vector<int>> answer;
        answer.push_back(ans1);
        answer.push_back(ans2);
        return answer;
    }
};