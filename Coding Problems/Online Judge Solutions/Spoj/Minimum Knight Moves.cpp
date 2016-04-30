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
#include <ctime>
#include <fstream>
#define inf (long long)1e15
#define MAX_N  20
#define URL "http://www.spoj.com/problems/NAKANJ/"

using namespace std;

pair<int, int> get_cord(string input)
{
    pair<int, int> out;
    out.first = input[0] - 'a';
    out.second = input[1] - '1';
    return out;
}

bool isvalid(pair <int,int> start)
{
    if(start.first >= 0 && start.first < 8 && start.second >= 0 && start.second < 8)
        return true;
    return false;
}

///debugging mr crazy here(already done now)
int main()
{
        int t;
        cin >> t;
        for(int k = 0; k < t; k++)
        {
            string st, sp;
            cin >> st >> sp;
            pair<int, int> start = get_cord(st), stop = get_cord(sp);
            queue< pair <int, int> > q;
            bool seen[8][8];
            int dist[8][8];
            memset(seen, 0, sizeof(seen));
            memset(dist, 0, sizeof(dist));
            q.push(start);
            seen[start.first][start.second] = 1;
            dist[start.first][start.second] = 0;
            while(!q.empty())
            {
                pair<int, int> temp = q.front(); q.pop();
                if(temp.first == stop.first && temp.second == stop.second)
                {
                    break;///early exit
                }
                ///look everywhere from here
                if(isvalid(make_pair(temp.first - 2, temp.second - 1)))/// 1
                {
                    q.push(make_pair(temp.first - 2, temp.second - 1));
                    seen[temp.first - 2][temp.second - 1] = 1;
                    dist[temp.first - 2][temp.second - 1] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first - 1, temp.second - 2)))/// 2
                {
                    q.push(make_pair(temp.first - 1, temp.second - 2));
                    seen[temp.first - 1][temp.second - 2] = 1;
                    dist[temp.first - 1][temp.second - 2] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first + 1, temp.second - 2)))/// 3
                {
                    q.push(make_pair(temp.first + 1, temp.second - 2));
                    seen[temp.first + 1][temp.second - 2] = 1;
                    dist[temp.first + 1][temp.second - 2] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first + 2, temp.second - 1)))/// 4
                {
                    q.push(make_pair(temp.first + 2, temp.second - 1));
                    seen[temp.first + 2][temp.second - 1] = 1;
                    dist[temp.first + 2][temp.second - 1] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first - 2, temp.second + 1)))/// 5
                {
                    q.push(make_pair(temp.first - 2, temp.second + 1));
                    seen[temp.first - 2][temp.second + 1] = 1;
                    dist[temp.first - 2][temp.second + 1] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first - 1, temp.second + 2)))/// 6
                {
                    q.push(make_pair(temp.first - 1, temp.second + 2));
                    seen[temp.first - 1][temp.second + 2] = 1;
                    dist[temp.first - 1][temp.second + 2] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first + 1, temp.second + 2)))/// 7
                {
                    q.push(make_pair(temp.first + 1, temp.second + 2));
                    seen[temp.first + 1][temp.second + 2] = 1;
                    dist[temp.first + 1][temp.second + 2] = dist[temp.first][temp.second] + 1;
                }
                if(isvalid(make_pair(temp.first + 2, temp.second + 1)))/// 8
                {
                    q.push(make_pair(temp.first + 2, temp.second + 1));
                    seen[temp.first + 2][temp.second + 1] = 1;
                    dist[temp.first + 2][temp.second + 1] = dist[temp.first][temp.second] + 1;
                }
            }
            cout << dist[stop.first][stop.second] << endl;
        }
}
