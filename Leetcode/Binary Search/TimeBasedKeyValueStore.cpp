///for a solution using this:
///we will simply use a hash table of keys mapped to an array of 
///timestamp and value
///we binary search on timestamp to get earliest timestamp


class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, vector< pair<int, string> > > mp;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(  make_pair(timestamp, value)  );
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == 0){
            return "";
        }
        
        int lo = 0;
        int hi = mp[key].size() - 1;

        ///looking for last timestamp <= timestamp
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(mp[key][mid].first <= timestamp){
                lo = mid;
            }else{
                hi = mid - 1;
            }   
        }
        
        if(mp[key][lo].first <= timestamp){
            return mp[key][lo].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */