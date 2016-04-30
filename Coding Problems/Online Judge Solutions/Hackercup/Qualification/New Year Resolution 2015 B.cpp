#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <list>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <set>
#include <map>
#define  inf (long long)1e15
#define  MAX_N 100009
using namespace std;
typedef vector<int> vec;
typedef vector< vector <int> > vec_2d;

struct calorie
{
    long long int prot, carb, fat;
};

///hackercup hack challenge no.2
int main()
{
    ofstream out("output.txt");
    ifstream in("input.txt");
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int Ap, Ac, Af;
        cin >> Ap >> Ac >> Af;
        int N; cin >> N;
        calorie food[N];
        for(int j = 0; j < N; j++)cin >> food[j].prot >> food[j].carb >> food[j].fat;
        bool flag = false;
        int brute_force = (1 << N);
        for(int j = 0; j <= brute_force; j++)
        {
            int psum = 0, csum = 0, fsum = 0;
            for(int k = 0; k < N; k++)
            {
                int d = (j >> k);
                if(d&1)
                {
                    psum += food[k].prot;
                    csum += food[k].carb;
                    fsum += food[k].fat;
                }
            }
            if(psum == Ap && csum == Ac && fsum == Af ){flag = true; break;}
        }
        if(flag)
            cout << "Case #" << i + 1 << ": yes" << endl;
        else
            cout << "Case #" << i + 1 << ": no" << endl;
    }
}/// end challenge no.2
