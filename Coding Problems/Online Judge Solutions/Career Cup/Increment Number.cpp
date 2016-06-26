#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
using namespace std;
#define url  "https://www.careercup.com/question?id=5687411305611264"

class BigNumber{
    public:
    BigNumber(const std::vector<int> &input);
    std::vector<int> increment();
    private:
    std::vector<int> digits;
};

BigNumber::BigNumber(const std::vector<int> &input) {
    digits = input;
}

std::vector<int> BigNumber::increment() {
    vector<int> out;
    int index = digits.size() - 1;
    while(digits[index] == 9 && index >= 0){
        out.push_back(0);
        index--;
    }
    if(index == -1){
        out.push_back(1);
    }else{
        digits[index]++;
        out.push_back(digits[index]);
        index--;
        while(index >= 0){
            out.push_back(digits[index]);
            index--;
        }
    }
    reverse(out.begin(), out.end());
    return out;
}

int convertToIntHorner(vector<int> a){
    int ret = 0;
    for(int i = 0; i < a.size(); i++){
        ret = 10*ret + a[i];
    }
    return ret;
}

int main(){
    vector<int> num = {1,1,2}; //Test value should return 113
    BigNumber A(num);
    vector<int> returnVal = A.increment();
    for(int i = 0; i < returnVal.size(); i++){
        cout << returnVal[i];
    }cout << endl;
}
