class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
       vector< vector<int> > subs = getSubsets(nums);
        
       return subs;
    }
    
    vector<vector<int>> getSubsets(vector<int> nums){
        int size = ( 1 << nums.size() );
        vector<vector<int>> res;
        
        for(int i = 0; i < size; i++){
            int digit = i;
            vector<int> temp;
            for(int i = 0; i < nums.size(); i++){
                if((digit >> i) & 1){
                    temp.push_back(nums[i]);
                }
            }
            res.push_back(temp);
        }
        return res;
        
    }
};