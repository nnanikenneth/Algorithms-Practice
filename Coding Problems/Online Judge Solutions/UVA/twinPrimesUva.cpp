#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define url https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1335

std::vector<bool> sieve(20000000, 0);

std::vector<int> get(){
    sieve[0] = 1;
    sieve[1] = 1;
    for(int i = 2; i < (int)sieve.size(); i++){
        if(sieve[i] == false){
            for(int j = i + i; j < (int)sieve.size(); j+=i){
                sieve[j] = true;
            }
        }
    }
    std::vector<int> primes;
    for(int i = 0; i < (int)sieve.size(); i++){
        if(sieve[i] == false){
            primes.push_back(i);
        }
    }
    return primes;
}

int main()
{
    std::vector<int> primes = get();
    std::vector< pair<int, int> > twinPrimes;
    for(int i = 0; i < (int)primes.size() - 1; i++){
        if(primes[i] == primes[i + 1] - 2){
            twinPrimes.push_back(make_pair(primes[i], primes[i + 1]));
        }
    }
    int number;
    while(cin >> number){
        cout << "(" << twinPrimes[number - 1].first << ", " << twinPrimes[number - 1].second << ")" << endl;
    }
}