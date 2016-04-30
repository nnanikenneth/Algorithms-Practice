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
#define fox(i, n) for(int i = 0; i < n; i++)
using namespace std;

void test(string &code)
{
    int n = code.length() - 1;
    for(int i = 0; i < n; i++)
    {
        swap(code[i], code[i + 1]);
    }
}

bool is_palindrome(string code)
{
    int n = code.length();
    bool flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(code[i] != code[n - i - 1])flag = 1;
    }
    return (flag ? false : true);
}

///O(6n) complexity then reformulate and prove rigorously
int main()
{
    int test;
    cin >> test;
    for(int i = 0; i < test; i++)
    {
        string code;
        cin >> code;
        int n = code.length();
        bool flag = 0;
        ///(therefore try to optimize the code and see what you can gather)
        for(int j = 0; j < n; j++)/// start of the for loop
        {
            bool testing_loop = 0;
            if(code[j] != code[n - j - 1])
            {
                int index_1 = j;
                int index_2 = n - j - 1;
                string temp_code = code;
                temp_code.erase(index_1, 1);

                if(is_palindrome(temp_code))
                {
                    flag = true;
                    break;
                }/// end nested if
                temp_code = code;
                temp_code.erase(index_2, 1);

                if(is_palindrome(temp_code))
                {
                    flag = true;
                    break;
                }/// end nested if
                testing_loop = 1;
            }/// end if
            if(testing_loop)///fast reduction in complexity otherwise code becomes bruteforce..............***
            {
                break;///fast optimization
            }
            if(j == n - 1 && code[j] == code[n - j - 1] && flag == 0){flag = 1;}///....................***
        }///end of for loop
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}
