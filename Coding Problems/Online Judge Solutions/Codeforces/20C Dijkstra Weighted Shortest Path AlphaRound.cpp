#include <iostream>
#include <vector>
#include <set>
#define inf (long long)1e15
#define URL "http://codeforces.com/contest/20/submission/7847141"
#define URL "http://codeforces.com/contest/20/problem/C"
using namespace std;

const int maxn = 100001; ///MAXIMUM NUMBER OF NODES

int n, m, i, a, b, c, j, p[maxn]; /// (n, m, a, b, c)for input: (p[], i, j) is for parent tree and index respectively
vector < pair<int, long long> > g[maxn];   /// graph data structure
vector <long long> path, d(maxn,inf);   /// path is used to print out the path also d is the array that contains single source s.p to all vertices
set<pair<long long,int> >q;         /// to simulate the priority queue

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a].push_back( make_pair(b,c) );  ///graph is not directed
        g[b].push_back( make_pair(a,c) );   ///graph is not directed
    }
    d[1] = 0;  /// initialisation distance from source(1) to source(1) = 0 note that for all other verices d[i] = infinity
    q.insert( make_pair(0,1) );   ///q[i].first and q[i].second mean

    ///some codes
    while(!q.empty())
    {
        int v = q.begin()->second;  /// take the vertex of .......
        q.erase( q.begin() );
        for(j = 0; j < g[v].size(); j++)
        {
            int to = g[v][j].first;   ///take ending vertex  v connects to ie(first)
            int len = g[v][j].second;   /// take the weight of v ---> to
            if(d[to] > d[v] + len) /// if not relaxed?
            {
                d[to] = d[v] + len; /// relax the edge s ---> to equal s ---> v plus the length of edge v ---> to
                p[to] = v;        /// store the parent of to to be v
                q.insert( make_pair(d[to], to) );  /// insert
            }
        }
    }
    ///printing dijkstra's shortest path from 1 to n
    int a = n;
    while(true)/// start taking the path from the last seen vertex
    {
        path.push_back(a); /// push_back a = n
        a = p[a];   /// parent of a is a
        if(a == 0)break; /// break when you see the zero
    }
    if(path[path.size() - 1] != 1) /// if the lastly taken element is not 1 (should be one if taken correctly)
    {
        cout << -1;
        return 0;
    }
    for(i = path.size() - 1; i >= 0; i--)/// ...otherwise...print the path in reverse as taken from n to 1
        cout << path[i] << " ";
    return 0; /// end of program
}
