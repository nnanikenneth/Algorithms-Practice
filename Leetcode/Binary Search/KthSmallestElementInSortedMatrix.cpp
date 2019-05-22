class Solution {
public:
    ///store only  k elements
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(maxHeap.size() == k){
                    maxHeap.push(matrix[i][j]);
                    maxHeap.pop();
                }else{
                    maxHeap.push(matrix[i][j]);
                }
            }
        }
        
        return maxHeap.top(); 
    }
};