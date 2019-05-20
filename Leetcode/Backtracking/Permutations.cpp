class Solution {
public:
    bool permutation(vector<int> &nums, int i, vector<vector<int>> &accum){
            if(i == nums.size() - 1){
                return true;
            }
            for(int j = i; j < nums.size(); j++){
                swap(nums[i], nums[j]);
                if( permutation(nums, i + 1, accum) ){
                    accum.push_back(nums);
                }
                swap(nums[i], nums[j]);
            }
            return false;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 1 || nums.size() == 0){
            res.push_back(nums);
            return res;
        }
        permutation(nums, 0, res);
        return res;
    }
};