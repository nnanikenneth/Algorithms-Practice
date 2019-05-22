class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)return false;
        if(matrix[0].size() == 0)return false;
        for(int i = 0; i < matrix.size(); i++){
            int lo = 0;
            int hi = matrix[0].size() - 1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(matrix[i][mid] > target){
                    hi = mid - 1;
                }
                if(matrix[i][mid] < target){
                    lo = mid + 1;
                }
                if(matrix[i][mid] == target){
                    return true;
                }
            }
        }
        return false;
    }
};