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
#define MAX_N 20

using namespace std;

bool isbound(int i , int j, int r, int c)
{
    if(i < r && i >= 0 && j < c && j >= 0)return true;
    return false;
}

///debugging...
long long int doit(vector <vector <bool> > &a, int bitt, int rem, int row, int col)///bit changes what doit must perform on
{
    ///vector <vector <bool> > a = tt;
    long long int minimum_unhapiness = 0;
    ///for optimal sol...
    for(int i = 0; i < row; i++)///looking  down from 0 0
    {
       if(a[i][0] == bitt && rem > 0)
        {
               {minimum_unhapiness++; rem--;}
        }
    }
    for(int i = 0; i < row; i++)///looking  down from 0 c - 1
    {
        if(a[i][col - 1] == bitt && rem > 0)
           {
               {minimum_unhapiness++; rem--;}
           }
    }
    for(int i = 0; i < col; i++)///looking right from 0 0
    {
        if(a[0][i] == bitt && rem > 0)
          {
                {minimum_unhapiness++; rem--;}
          }
    }
    for(int i = 0; i < col; i++)///looking right from r - 1 0
    {
        if(a[col - 1][i] == bitt && rem > 0)
          {
                {minimum_unhapiness++; rem--;}
          }
    }
    for(int i = 1; i < row - 1; i++)///looking everywhere in inner grid
    {
        for(int k = 1; k < col - 1; k++)
        {
            if(a[i][k] == bitt && rem > 0)
              {
                   if(isbound(i, k + 1, row, col)){minimum_unhapiness++; rem--;}
                   if(isbound(i - 1, k, row, col)){minimum_unhapiness++; rem--;}
                   if(isbound(i, k - 1, row, col)){minimum_unhapiness++; rem--;}
                   if(isbound(i + 1, k, row, col)){minimum_unhapiness++; rem--;}
              }
        }
    }
    return minimum_unhapiness;
}

int main()
{
   ifstream in("input.txt");
   ofstream out("output.txt");
   long long int test_case;
   cin >> test_case;
   for(long long int j = 0; j < test_case; j++)
   {
       int minimum_unhapiness = 0;
       int r, c, n;
       cin >> r >> c >> n;
       vector < vector <bool> > a;
       ///generate boolean array
       for(int i = 0; i < r; i++)
       {
           vector<bool> temp;
           for(int k = 0; k < c; k++)
           {
               temp.push_back(0);
           }
           a.push_back(temp);
       }
       if(r == 1 && c == 1){out << "Case #" << j + 1 << ": " << 0 << endl; continue;}///special case
       for(int i = 0; i < r; i++)
       {
           for(int k = 0; k < c; k++)
           {
               if(i%2==0)
               {
                   if(k%2 == 0)
                        a[i][k] = 1;
               }
               else
               {
                   if(k%2 != 0)
                        a[i][k] = 1;
               }
           }
       }
       int zero = 0;
       int one = 0;
       ///testing output
       for(int i = 0; i < r; i++)
       {
           for(int k = 0; k < c; k++)
           {
               cout << a[i][k] << " ";
           }cout << endl;
       }///end testing input
       for(int i = 0; i < r; i++)///counting
       {
           for(int k = 0; k < c; k++)
           {
               if(a[i][k] == 0)zero++;
                else one++;
           }
       }
       int maximum_safe_capacity = max(one, zero);
       if(n <= maximum_safe_capacity)///case that produces a null
       {
           cout << "Case #" << j + 1 << ": " << 0 << endl; continue;
       }
       else///there must exist a solution
       {
           int rem1 = n - one;
           int rem2 = n - zero;
           int r = doit( a, 1, rem2, r, c);
           int s = doit( a, 0, rem1, r, c);
          cout << "Case #" << j + 1 << ": " << min(r,s) << endl;
       }
   }
}
