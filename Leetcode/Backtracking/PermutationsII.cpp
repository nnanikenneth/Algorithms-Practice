///sams as permutation but just add in a set

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       if(nums.size() == 0){return {{}}; }
       if(nums.size() == 1){
            return {nums};
       }
       set<vector<int>> response;
       permuteUniqueHelper(0, nums, response);
       vector<vector<int>> ans;
       for(auto i : response){
           ans.push_back(i);
       }
       return ans;
    }
    
    bool permuteUniqueHelper(int cur, vector<int> nums, set<vector<int>> &response){
        if(cur == nums.size() - 1){
            return true;
        }
        
        for(int i = cur; i < nums.size(); i++){
            swap(nums[cur], nums[i]);
            if(permuteUniqueHelper(cur + 1, nums, response) == true){
                response.insert(nums);
            }
            swap(nums[cur], nums[i]);
        }
        return false;
    }
};