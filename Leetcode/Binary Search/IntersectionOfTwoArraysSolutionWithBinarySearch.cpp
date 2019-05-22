class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        //nasty case that i dont want to see
        if(nums1.size() == 0 || nums2.size() == 0){
            return res;
        }
        
        bool flag = false; //when true means nums1 is smaller
        if(nums1.size() < nums2.size()){
            flag = true;
        }
        
        if(flag == true){
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            
            for(int i = 0; i < nums2.size(); i++){
                if(search(nums1, nums2[i]) == true){
                    res.push_back(nums2[i]);
                }
                int index = findNext(nums2, nums2[i]);
                i = index;
            }
        }else{
            sort(nums2.begin(), nums2.end());
            sort(nums1.begin(), nums1.end());
        
            for(int i = 0; i < nums1.size(); i++){
                if(search(nums2, nums1[i]) == true){
                    res.push_back(nums1[i]);
                }
                int index = findNext(nums1, nums1[i]);
                i = index;
            }
        }
        return res;
    }
    
   bool search(vector<int> &nums1, int target){
        int lo = 0;
        int hi = nums1.size() - 1;
        while(lo <= hi){
            int mid = (hi + lo)/2; //lo + ((hi - lo)>>1);
            if(nums1[mid] == target){
                return true;
            }
            if(target > nums1[mid]){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return false;
    }
    
    int findNext(vector<int> &nums1, int target){///actually find the last of something
        int lo = 0;
        int hi = nums1.size() - 1;
        while(lo < hi) {
            int mid = (hi + lo + 1)/2; //lo + ((hi-lo + 1)>>1);
            if(nums1[mid] <= target){
                lo = mid;
            }else{
                hi = mid - 1;
            }
        }
        return lo;
    }
};