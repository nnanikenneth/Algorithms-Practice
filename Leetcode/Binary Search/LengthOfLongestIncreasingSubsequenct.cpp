class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> memo(nums.size(), 0);
        memo[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            int mx = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    mx = max(mx, memo[j]);
                }
            }
            memo[i] = mx + 1;
        }
        int ans = 0;
        for(int i = 0; i < memo.size(); i++){
            ans = max(ans, memo[i]);
        }
        return ans;
    }
};