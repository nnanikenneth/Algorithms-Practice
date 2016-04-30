#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <ctime>
#include <iomanip>
#define  epsilon 1e-09
#include <hash_map>
#define URL "http://www.spoj.com/problems/ELIS/"

using namespace std;

int max_increasing_subsequence(int a[], int n)
{
    int dp[n];
    dp[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
        int maxx = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                if( maxx < 1 + dp[j] )maxx = dp[j] + 1;
            }
        }
        dp[i] = maxx;
    }
    int maxx = 0;
    int maxx_loc = 0;
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > maxx){maxx = dp[i]; maxx_loc = i;}
    }
    return maxx;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << max_increasing_subsequence(a, n) << endl;
}
