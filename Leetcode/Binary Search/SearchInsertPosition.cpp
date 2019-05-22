class Solution {
public:
    //use less than or equal to
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi){
            int mid = (hi + lo)/2;
            if(nums[mid] >= target){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        if(nums[hi] < target){
            return hi + 1;
        }
        return hi;
    }
};