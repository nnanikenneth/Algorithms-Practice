#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>

#define url https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=305

using namespace std;

int Gcd(int a, int b){
    if(b == 0){
        return a;
    }else{
        return Gcd(b, a%b);
    }
}

long long solve(vector<int> num, vector<int> denum){
    for(int i = 0; i < denum.size(); i++){
        int temp = denum[i];
        int index = 0;
        while(temp != 1){
            int gcd = Gcd(temp, num[index]);
            temp /= gcd;
            num[index] /= gcd;
            index++;
        }
    }
    long long ans = 1;
    for(int i = 0; i < num.size(); i++){
        ans = ans * num[i];
    }
    return ans;
}

int solutionToUva(){
    int n, r;
    while(cin >> n >> r){
       if(n == 0 && r == 0)break;

        if(r == 0){
            cout << n << " things taken " <<  r << " at a time is " << 1 << " exactly." << endl;
            continue;
        }
        if(r == 1){
            cout << n << " things taken " <<  r << " at a time is " <<  n << " exactly." << endl;
            continue;
        }
        int n1 = n - r;
        int n2 = r;
        if(n1 > n2){
            std::vector<int> num(n2);
            std::vector<int> denum(n2);
            for(int i = 0; i < n2; i++){
                num[i] = n1 + 1 + i;
                denum[i] = i + 1;
            }
            cout << n << " things taken " <<  r << " at a time is " <<  solve(num, denum) << " exactly." << endl;
        }else{
            std::vector<int> num(n1);
            std::vector<int> denum(n1);
            for(int i = 0; i < n1; i++){
                num[i] = n2 + 1 + i;
                denum[i] = i + 1;
            }
            cout << n << " things taken " <<  r << " at a time is " <<  solve(num, denum) << " exactly." << endl;
        }
    }
}
