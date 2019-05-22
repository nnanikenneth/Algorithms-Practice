class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1, -1};
        }
        
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(nums[mid] >= target){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        int lowerbound = hi;
        
        
        lo = 0;
        hi = nums.size() - 1;
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(nums[mid] <= target){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        int upperbound = lo;
        
        if(nums[lowerbound] != target){
            return {-1, -1};
        }
        return {lowerbound, upperbound};
    }
};