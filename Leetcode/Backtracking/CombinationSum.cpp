class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        map<vector<int>, int> results;
        vector<int> tempSol;
        combinationSumHelper(candidates, target, tempSol, results);
        vector<vector<int>> ans;
        for(std::map<vector<int>, int>::iterator it = results.begin(); it != results.end(); it++){
            ans.push_back(it->first);
        }
        return ans;
    }
    
    bool combinationSumHelper(vector<int> candidates, int target, vector<int> tempSol, map<vector<int>, int> &results){ //hack
        
        if(target <= 0){ //this is kinda of hack for the 
            if(target == 0){
                return true;
            }else{
                return false;
            }
        }
        
        for(int i = 0; i < candidates.size(); i++){
            tempSol.push_back(candidates[i]);
            if(combinationSumHelper(candidates, target - candidates[i], tempSol, results)){
                    vector<int> temp = tempSol; //some hack
                    sort(temp.begin(), temp.end()); //some hack
                    results[temp] = 1; //some hack
            }
            tempSol.pop_back();
        }
        return false;
    }
};