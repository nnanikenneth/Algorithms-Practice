class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]]++;
        }
        
        vector<int> results;
        for(int j = 0; j < nums2.size(); j++){
            if(mp.count(nums2[j]) == 1){
                
                results.push_back(nums2[j]);
                
                if(mp[nums2[j]] > 1){
                    mp[nums2[j]]--;
                }else if(mp[nums2[j]] == 1){
                    mp.erase(nums2[j]);
                }
                
            }
        }
        
        return results;
    }
};