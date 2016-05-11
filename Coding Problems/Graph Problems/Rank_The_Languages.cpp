#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <fstream>
#define URL https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1277

using namespace std;
typedef map< pair<int, int>, bool > myMap;

// check grid row col
bool isValid( pair<int, int> cord, int row, int col){
    return (cord.first >= 0 && cord.first < row && cord.second >= 0 && cord.second < col) ? true : false;
}

// comparator object for mutlifield sorting with rules
struct data{
    char language;
    int count;
    bool operator<(data temp)const{
        if(temp.count == count) {
            if (temp.language > temp.language)return true;
            else
                return false;
        }

        if(temp.count < count){
            return true;
        }else
            return false;
    }
};

void dfs(vector<string> &grid, myMap &seen, const pair <int, int> &cord, char t){
    seen[cord] = true;
    // make sure we are within the grid before searching
    //an adj edge if (same char and not seen)
    int m = grid.size();
    int n = grid[0].size();
    if( isValid(make_pair(cord.first, cord.second + 1), m, n) ){
        int i = cord.first;
        int j = cord.second + 1;
        if(grid[i][j] == t && seen.count(make_pair(i, j)) == 0)
            dfs(grid, seen, make_pair(i, j), t); //dir1
    }
    if( isValid(make_pair(cord.first, cord.second - 1), m, n) ){
        int i = cord.first;
        int j = cord.second - 1;
        if(grid[i][j] == t && seen.count(make_pair(i, j)) == 0)
            dfs(grid, seen, make_pair(i, j), t); //dir2
    }
    if( isValid(make_pair(cord.first - 1, cord.second), m, n) ){
        int i = cord.first - 1;
        int j = cord.second;
        if(grid[i][j] == t && seen.count(make_pair(i, j)) == 0)
            dfs(grid, seen, make_pair(i, j), t); //dir3
    }
    if( isValid(make_pair(cord.first + 1, cord.second), m, n) ){
        int i = cord.first + 1;
        int j = cord.second;
        if(grid[i][j] == t && seen.count(make_pair(i, j)) == 0)
            dfs(grid, seen, make_pair(i, j), t); //dir4
    }
}

map<char, int> dfsVisit(vector<string> &grid){
    map<char, int> villages;
    myMap seen;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(seen.count(make_pair(i, j)) == 0){
                char t = grid[i][j];
                dfs(grid, seen, make_pair(i, j), t);

                if(villages.count(grid[i][j]) == 0){
                    villages[grid[i][j]] = 1;
                }else{
                    villages[grid[i][j]]++;
                }
            }
        }
    }
    return villages;
}

int main(){
    int testcase;
    cin >> testcase;
    for(int k = 0; k < testcase; k++){
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for(int i = 0; i < n; i++){
            cin >> grid[i];
        }
        map<char, int> villages = dfsVisit(grid);

        vector<data> res;

        cout << "World #" << k + 1 << endl;

        for(std::map<char, int>::iterator it = villages.begin(); it != villages.end(); it++){
            data temp;
            temp.language = (*it).first;
            temp.count = (*it).second;
            res.push_back(temp);
        }
        sort(res.begin(), res.end()); ///sort with rules
        for(int i = 0; i < res.size(); i++){
            cout << res[i].language << ": " << res[i].count << endl;
        }
    }
}
