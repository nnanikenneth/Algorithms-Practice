class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(11, 0);
        dp[1] = 9;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1]*(10 - (i - 1)); 
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += dp[i];
        }
        return ans + 1; //plus zero
    }
};