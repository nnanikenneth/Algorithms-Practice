class Compare{
    public:
    
    bool operator() (pair<int, string> A, pair<int, string> B){
        if(A.first < B.first){
            return true;
        }else if(A.first == B.first){
            if(A.second > B.second){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }  
};


class Solution {
public:
  
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            pair<string, int> temp = (*it);
            pq.push( make_pair(temp.second, temp.first) );
        }
        
        vector<string> output;
        while(k > 0){
            pair<int, string> temp = pq.top();
            pq.pop();
            output.push_back(temp.second);
            k--;
        }
        
        return output;
    }
};