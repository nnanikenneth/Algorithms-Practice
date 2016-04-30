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
#define MAX_N  25
#define URL "http://www.spoj.com/problems/TOANDFRO/"
using namespace std;

int main()
{
    int n = 9;
    while(n != 0)
    {
        cin >> n;
        if(n == 0)return 0;
        string en;
        cin >> en;
        int t = en.length();
        int r;

        if(t%n == 0){
            r = t/n;
        } else {
            r = t/n + 1;
        }

        char a[r][n];
        int k = 0;
        bool flag = false;
        int rr = 0;
        for(int i = 0; i < r; i++)
        {
            if(rr%2==0)
            {
                for(int j = 0; j < n; j++)
                {
                    if(k == t){flag = 1; break;}
                    a[i][j] = en[k];
                    k++;
                }
            }
            else
            {
                for(int j = n - 1; j >= 0; j--)
                {
                    if(k == t){flag = 1; break;}
                    a[i][j] = en[k];
                    k++;
                }
            }
            rr++;
            if(flag)break;
        } //end for

        k = 0;
        flag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < r; j++)
            {
                if(k == t){flag = 1; break;}
                cout << a[j][i];
                k++;
            }
            if(flag)break;
        }
        cout << endl;
    } //end while
} // end main
