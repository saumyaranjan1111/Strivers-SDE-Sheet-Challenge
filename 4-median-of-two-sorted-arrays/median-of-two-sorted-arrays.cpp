class Solution {
public:
    int nossmallerorequal(int x, int idx, int arr, vector<int>& nums1, vector<int> &nums2){
        int result = 0;
        result += idx+1;
        if(arr == 1){
            result += lower_bound(nums1.begin(), nums1.end(), x) - nums1.begin();
        }
        else {
            result += lower_bound(nums2.begin(), nums2.end(), x) - nums2.begin();
        }

        return result;
    }
    double oddcase(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();

        // nums1
        int low = 0, high = n-1;
        int mid = low + (high - low)/2;
        pair<int, int> ans1 = {nums1[mid], 0};
        while(low <= high){
            mid = low + (high - low)/2;
            int smallernums = nossmallerorequal(nums1[mid], mid, 2, nums1, nums2);
            if(smallernums < (m+n)/2 + 1){
                // this no lies to the left of median
                low = mid+1;
            }
            else {
                ans1 = {nums1[mid], smallernums};
                high = mid-1;
            }
        }

        // nums2
        low = 0, high = m-1;
        mid = low + (high - low)/2;
        pair<int, int> ans2 = {nums2[mid], 0};
        while(low <= high){
            mid = low + (high - low)/2;
            int smallernums = nossmallerorequal(nums2[mid], mid, 1, nums1, nums2);
            if(smallernums < (m+n)/2 + 1){
                low = mid+1;
            }
            else {
                ans2 = {nums2[mid], smallernums};
                high = mid-1;
            }
        }

        // cout<<ans1.second<<endl;
        // cout<<ans2.second<<endl;

        if(ans1.second == (m+n)/2 + 1)
        return ans1.first;

        if(ans2.second == (m+n)/2 + 1)
        return ans2.first;

        return -1;
    }

    double evencase(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size(), m = nums2.size();

        // search for a number in nums1 and nums2 such that the no of elements <= that no in both the arrays combined is == (m+n)/2

        int low = 0, high = n-1;
        int mid = low + (high - low)/2;
        int ans1 = nums1[mid];
        bool flag = false;
        while(low <= high){
            mid = low + (high - low)/2;
            int ele = nums1[mid];

            int smallerorequal = nossmallerorequal(nums1[mid], mid, 2, nums1, nums2);
            if(smallerorequal == (m+n)/2){
                flag = true;
                ans1 = nums1[mid];
                break;
            } 
            else if(smallerorequal < (m+n)/2){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        if(!flag){
            low = 0, high = m-1;
            mid = low + (high - low)/2;
            ans1 = nums2[mid];
            while(low <= high){
                mid = low + (high - low)/2;
                int ele = nums2[mid];

                int smallerorequal = nossmallerorequal(nums2[mid], mid, 1, nums1, nums2);
                if(smallerorequal == (m+n)/2){
                    ans1 = nums2[mid];
                    break;
                } 
                else if(smallerorequal < (m+n)/2){
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }

        // (n+m)/2 + 1th number
        low = 0, high = n-1;
        mid = low + (high - low)/2;
        int ans2 = nums1[mid];
        flag = false;
        while(low <= high){
            mid = low + (high - low)/2;
            int ele = nums1[mid];

            int smallerorequal = nossmallerorequal(nums1[mid], mid, 2, nums1, nums2);
            if(smallerorequal == (m+n)/2 + 1){
                flag = true;
                ans2 = nums1[mid];
                break;
            } 
            else if(smallerorequal < (m+n)/2 + 1){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }

        if(!flag){
            low = 0, high = m-1;
            mid = low + (high - low)/2;
            ans2 = nums2[mid];
            while(low <= high){
                mid = low + (high - low)/2;
                int ele = nums2[mid];

                int smallerorequal = nossmallerorequal(nums2[mid], mid, 1, nums1, nums2);
                if(smallerorequal == (m+n)/2 + 1){
                    ans2 = nums2[mid];
                    break;
                } 
                else if(smallerorequal < (m+n)/2 + 1){
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }

        return ((double)ans1 + (double)ans2)/2;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        if(n == 0){
            if((m+n)%2 == 0){
                return ((double)nums2[m/2] + (double)nums2[m/2 - 1])/2;
            }
            else return (double)nums2[m/2];
        }
        else if(m == 0){
            if((m+n)%2 == 0){
                return ((double)nums1[n/2] + (double)nums1[n/2 - 1])/2;
            }
            else return (double)nums1[n/2];
        }

        if((n+m) %2 != 0){
            return oddcase(nums1, nums2);
        }

        return evencase(nums1, nums2);
    }
};