class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<long long, int> ab; // a + b, count
        unordered_map<long long, int> cd; // -(c + d), count
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                ab[A[i] + B[j]]++;
            }
        }
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                cd[-(C[i] + D[j])]++;
            }
        }
        long long res = 0;
        for(auto i = ab.begin(); i != ab.end(); i++){
            auto temp = (*i);
            if(cd.count(temp.first) == 1){
                res = res + (temp.second * cd[temp.first]);
            }
        }
        return res;
    }
};