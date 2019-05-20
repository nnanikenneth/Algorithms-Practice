class Solution {
public:
    bool isvalid(int i, int j, int row, int col){
        return ( i >= 0 && i < row && j >= 0 && j < col);    
    }
    
    void findMaxAreaOfIsland(int i, int j, vector<vector<int>> &grid, int &maxx, vector<vector<int>> &seen){
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        seen[i][j] = 1;
        maxx++;
        for(int k = 0; k < dx.size(); k++){
            if(isvalid(i + dx[k], j + dy[k], grid.size(), grid[0].size())){
                if(grid[i + dx[k]][j + dy[k]] == 1 && seen[i + dx[k]][j + dy[k]] == 0){
                    findMaxAreaOfIsland(i + dx[k], j + dy[k], grid, maxx, seen);
                }
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxx = 0;
        vector<int> t(grid[0].size(), 0);
        vector<vector<int>> seen(grid.size(), t);
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && seen[i][j] == 0){
                    int tempmax = 0;
                    findMaxAreaOfIsland(i, j, grid, tempmax, seen);
                    maxx = max(tempmax, maxx);
                }
            }
        }
        return maxx;
    }
};