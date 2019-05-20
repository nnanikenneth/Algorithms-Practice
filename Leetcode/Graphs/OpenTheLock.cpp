class Solution {
public:
    
    // do a regular bfs but note that you have to be careful for the special case
    // when the start node "0000" is part of the deadends
    
    vector<string> getNextNodes(string &lock, unordered_map<string, bool> &deadend){
        vector<string> nextNodes;
        
        for(int i = 0; i < lock.size(); i++){
            char temp = lock[i];
            
            if(lock[i] - '0' == 0){
                lock[i] = '9';
            }else{
                lock[i]--;
            }
            
            // take lock next nodes
            if(deadend.count(lock) == 0){
                nextNodes.push_back(lock);
            }
            
            lock[i] = temp;
            if(lock[i] - '9' == 0){
                lock[i] = '0';
            }else{
                lock[i]++;
            }
            
            ///Take lock next nodes
            if(deadend.count(lock) == 0){
                nextNodes.push_back(lock);
            }
            lock[i] = temp;
        }
        
        return nextNodes;
    }

    int openLock(vector<string>& deadends, string target) {
        
        queue<string> que;
        unordered_map<string, bool> seen;
        unordered_map<string, bool> deadend;
        unordered_map<string, int> dist;
        
        for(int i = 0; i < deadends.size(); i++){
            deadend[deadends[i]] = true;
        }
        
        /// The base case here we cant go anywhere when the deadend is the fist word here
        if(deadend.count("0000") == 1){
            return -1;
        }
        
        que.push("0000");
        seen["0000"] = true;
        dist["0000"] = 0;

        while(que.size() != 0){
            string node = que.front();
            que.pop();
            
            vector<string> next = getNextNodes(node, deadend);
            for(int i = 0; i < next.size(); i++){
                if( seen.count(next[i]) == 0 ) {
                    que.push(next[i]);
                    seen[next[i]] = true;
                    dist[next[i]] = dist[node] + 1;
                    
                    //early exit optimisation termination
                    if(target == next[i]){       
                        return dist[next[i]];
                    }
                }
            }
        }
        
        return -1;
    }
};