class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> seen(candidates.size() + 1);
        vector<int> temp;
        set<vector<int>> res;
        
        combinationSum2Helper(candidates, target, seen, 0, temp, res);
        
        vector<vector<int>> sol;
        for(auto i : res){
            sol.push_back(i);
        }
        
        return sol;
    }
    
    bool combinationSum2Helper(vector<int> &candidates, int target, vector<bool> &seen, int sze, vector<int> &temp, set<vector<int>> &res){
        
        if(target == 0){
            return true;
        }
        
        if(target < 0){
            return false;
        }
        
        if(sze == candidates.size()){
            if(target == 0){
                return true;
            }else{
                return false;
            }
        }
        
        for(int i = 0; i < candidates.size(); i++){
            if(seen[i] == false){
                if(temp.size() == 0){
                    temp.push_back(candidates[i]);
                    seen[i] = true;
                    if(combinationSum2Helper(candidates, target - candidates[i], seen, sze+1, temp, res)){
                        res.insert(temp);
                    }
                    seen[i] = false;
                    temp.pop_back();
                    
                }else if(temp[temp.size() - 1] <= candidates[i]){
                    
                    temp.push_back(candidates[i]);
                    seen[i] = true;
                    if(combinationSum2Helper(candidates, target - candidates[i], seen, sze+1,  temp, res)){
                        res.insert(temp);
                    }
                    seen[i] = false;
                    temp.pop_back();
                }
            
            }
        }
        return false;
    }
};