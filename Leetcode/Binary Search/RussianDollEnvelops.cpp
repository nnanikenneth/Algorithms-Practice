class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() == 0)return 0;
        vector<int> mem(envelopes.size(), 0);
        sort(envelopes.begin(), envelopes.end());
        mem[0] = 1;
        for(int i = 1; i < envelopes.size(); i++){
            int maxx = 0;
            for(int j = 0; j < i; j++){
                if(iscomp(envelopes[i], envelopes[j])){
                    maxx = max(maxx, mem[j]);
                }
            }
            mem[i] = maxx + 1;
        }
        
        int ans = 0;
        for(int i = 0; i < mem.size(); i++){
            cout << mem[i] << " ";
            if(mem[i] > ans){
                ans = mem[i];
            }
        }cout << endl;
        return ans;
    }
    //impolement condition here
    bool iscomp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first && a.second > b.second;
    }
};