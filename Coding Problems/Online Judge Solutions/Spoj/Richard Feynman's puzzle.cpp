#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define URL "http://www.spoj.com/problems/SAMER08F/"
using namespace std;

int main()
{
        int n;
        do{

            scanf("%d", &n);
            int prev = 5;
            int next;
            if(n > 2)
            for(int i = 3; i <= n; i++)
            {
                int cnt = 0;
                for(int k = 1; k <= i - 2; k++)cnt += (i - k);
                for(int k = 2; k <= i - 1; k++)cnt += (i - k);
                cnt += 1;
                next = prev + 2*(i - 1) + 1 + cnt;
                prev = next;
            }
            if(n == 1) cout << 1 << endl;
            else if(n == 2)cout << 5 << endl;
            else
            if(n != 0 && n > 2)printf("%d\n", next);//cout << dp[n] << endl;
          }while(n != 0);
}
