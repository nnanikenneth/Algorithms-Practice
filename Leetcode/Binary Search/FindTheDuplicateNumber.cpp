class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::vector<int> a = nums;
        sort(a.begin(), a.end());
        int out = 0;
        for(int i = 0; i < a.size() - 1; i++){
            if(a[i] == a[i + 1]){
                out = a[i];
                break;
            }
        }
        return out;
    }
};