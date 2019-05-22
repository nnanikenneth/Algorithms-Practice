class Solution {
public:
    int search(vector<int>& nums, int target) {
        short lo = 0;
        short hi = nums.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi)>>1;
            if(target > nums[mid]){
                lo = mid + 1;
            }
            else if(target < nums[mid]){
                hi = mid - 1;
            }
            if(target == nums[mid]){
                return mid;
            }
        }
        return -1;
    }
};