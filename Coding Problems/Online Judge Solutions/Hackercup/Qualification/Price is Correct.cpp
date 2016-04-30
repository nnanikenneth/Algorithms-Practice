#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> solve(long long index, long long price, long long accumulator, vector<long long> &a)
{
        long long sum = accumulator;
        long long cnt = 0;
        long long j = index;
        while(sum <= price && j < a.size())
        {
            sum += a[j];
            if(sum <= price)cnt++;
            j++;
        }
        if(sum > price)sum = sum - a[j - 1];
        return make_pair(cnt, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    ofstream out("output.txt");
    ifstream in("input.txt");
    long long testCase;
    in >> testCase;
    long long iter = testCase;
    while(testCase--) {
        long long n, price;
        in >> n >> price;
        vector<long long> a(n);
        for(int i = 0; i < n; i++)in >> a[i];
        vector<long long> cache(n + 5, 0);
        vector<long long> sum(n+5, 0);
        pair<long long, long long> temp = solve(0, price, 0, a);
        cache[0] = temp.first;
        sum[0] = temp.second;
        for(int i = 1; i < n; i++)
        {
            if(cache[i - 1] == 0)
            {
                temp = solve(i, price, 0, a);
                cache[i] = temp.first;
                sum[i] = temp.second;
            }
            else
            {
                temp = solve(i - 1 + cache[i - 1], price, sum[i - 1] - a[i - 1], a);
                cache[i] = temp.first + cache[i - 1] - 1;
                sum[i] = temp.second;
            }
        }
        long long retval = 0;
        for(int i = 0; i < n; i++)
        {
            retval += cache[i];
        }
        out << "Case #" << iter - testCase << ": " << retval << endl;
    }
}
