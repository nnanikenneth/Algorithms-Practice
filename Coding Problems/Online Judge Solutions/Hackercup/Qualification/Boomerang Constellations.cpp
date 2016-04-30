#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    int iter = testCase;
    while(testCase--) {
        int n;
        cin >> n;
        pair<long long , long long> point[n];
        long long longitude, latitude;
        for(int i = 0; i < n; i++) {
                cin >> longitude >> latitude;
                point[i] = make_pair(longitude, latitude);
        }
        long long retval = 0;
        for(int i = 0; i < n; i++) {
            map<long long, long long> cnt;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    long long t1 = point[i].first - point[j].first;
                    long long t2 = point[i].second - point[j].second;
                    t1 = (t1 < 0 ? -1*t1 : t1);
                    t2 = (t2 < 0 ? -1*t2 : t2);
                    long long dist = t1*t1 + t2*t2;
                    if(cnt.count(dist) == 1) {
                        cnt[dist]++;
                    }
                    else
                        cnt[dist] = 1;
                }
            }
            for(map<long long, long long>::iterator it = cnt.begin(); it != cnt.end(); it++) {
                if(it->second >= 2) {
                    long long temp = it->second;
                    retval += (temp*(temp - 1)) /2;
                }
            }
        }
        cout << "Case #" << iter - testCase << ": " << retval << endl;
    }
}
