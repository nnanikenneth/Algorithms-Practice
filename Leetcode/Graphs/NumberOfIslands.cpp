
class Solution {
public:
    //simply this problem can be translated to the problem of returning the number of components in a graph
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)return 0;
        
        vector<bool> temp(grid[0].size(), false);
        vector<vector<bool>> seen(grid.size(), temp);
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!seen[i][j] && grid[i][j] == '1'){
                    dfs(grid, seen, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    vector<int> x = {0, 1, -1, 0};
    vector<int> y = {1, 0, 0, -1};
    //using dfs here
    //tricky here..Why did this ever work?????? i means changing it to bfs (solved)
    //okay i can explain why it works here...
    //what is happening within this piece of code is that the computer traverses and marks the boolean array
    //for each of the four directions this can be likened to the dfs routine which does a recursive deep dive kinda thing
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& seen, int r, int s){
        seen[r][s] = true;
        for(int i = 0; i < x.size(); i++){
            if(r + x[i] >= 0 && r + x[i] < grid.size() && s + y[i] >= 0 && s + y[i] < grid[0].size()){
                if(!seen[r + x[i]][s + y[i]] && grid[r + x[i]][s + y[i]] == '1'){
                    dfs(grid, seen, r + x[i], s + y[i]);
                }
            }
        }
    }
    
    //alternate solution using bfs
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& seen, int r, int s){
        seen[r][s] = true;
        queue< pair<int, int> > q;
        q.push(make_pair(r, s));
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            int e = node.first;
            int f = node.second;
            for(int i = 0; i < x.size(); i++){
                if(x[i] + e >= 0 && x[i] + e < grid.size() && y[i] + f >= 0 && y[i] + f < grid[0].size()){
                    if(!seen[e + x[i]][f + y[i]] && grid[e + x[i]][f + y[i]] == '1'){
                        seen[e + x[i]][f + y[i]] = true;
                        q.push(make_pair(e + x[i], f + y[i]));
                    }
                }
            }
        }
    }
    
    //finally use union find to solve the problem
};