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
#define URL "http://codeforces.com/problemset/problem/667/B"
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n];
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt += a[i];
    }
    sort(a, a + n);
    long long dp[n];
    dp[0] = a[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i - 1] + a[i];
    }cout << endl;

    long long sol = 9999999999999999;
    for(int i = 0; i < n - 1; i++){
           long long temp = 2*dp[i] - cnt;
           if(temp < 0)temp = -1*temp;
           sol = min(sol, temp);
    }
    cout << sol + 1 << endl;
}
