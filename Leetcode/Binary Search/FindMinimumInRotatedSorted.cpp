

class Solution {
public:
    int findMin(vector<int>& nums) {
        //bug fix
        if(nums[0] < nums[nums.size() - 1])return nums[0];
        if(nums.size() == 2)return min(nums[0], nums[1]);
    
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo < hi){
           int mid = (hi + lo)>>1;
           if(abs(lo - hi) == 1)return min(nums[lo], nums[hi]);
           if(nums[mid] <= nums[0]){
               hi = mid;
           }else{
               lo = mid + 1;
            }
        }
        return nums[hi];
    }
};