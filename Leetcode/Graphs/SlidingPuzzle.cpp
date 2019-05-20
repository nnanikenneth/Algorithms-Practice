class Solution {
public:
    typedef vector<int> h;
    
    int slidingPuzzle(vector<vector<int>>& board) {
        h target = {1,2,3,4,5,0}; //i think it woudl be easier
        h start;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++)start.push_back(board[i][j]);
        }
        if(target == start)return 0;
        map<h, bool> seen;
        map<h, int> dist;
        queue<h> que;

        seen[start] = true;
        dist[start] = 0;
        que.push(start);
     
        while( !que.empty() ){
            h newNode = que.front();
            que.pop();
            
            //navigating through all next states
            vector<vector<int>> nextstates = getNextStates(newNode); //yeah...i know i spent so much memory
            
            for(int i = 0; i < nextstates.size(); i++){
                if(seen.count(nextstates[i]) == 0){ //if not seen to avoid overcounting
                    
                    dist[nextstates[i]] = dist[newNode] + 1; //update dist
                    que.push(nextstates[i]); //update queue
                    seen[nextstates[i]] = true; //update seen
                    if(nextstates[i] == target) { //check if we arrived at winning move
                        cout << endl << "Ans: " << dist[nextstates[i]] << endl;
                        return dist[nextstates[i]];
                    }//end
                }
            }
            
        }//end while loop
        return -1; //sentinel
    }
    
    vector<h> getNextStates(h newNode){
        int x;
        for(int i = 0; i < newNode.size(); i++){
            if(newNode[i] == 0){
                x = i; break;
            }
        }
        vector<h> out;
        ///i know i know i am lazy to do the right thing
        if(x == 0){
            h temp = newNode;
            swap(temp[x], temp[1]);
            out.push_back(temp);
            temp = newNode;
            swap(temp[x], temp[3]);
            out.push_back(temp);
        }
        if(x == 1){
            h temp = newNode;
            swap(temp[x], temp[0]);
            out.push_back(temp);
                
            temp = newNode;
            swap(temp[x], temp[2]);
            out.push_back(temp);
                   
            temp = newNode;
            swap(temp[x], temp[4]);
            out.push_back(temp);
        }
        if(x == 2){ 
            h temp = newNode;
            swap(temp[x], temp[1]);
            out.push_back(temp);
            temp = newNode;
            swap(temp[x], temp[5]);
            out.push_back(temp);
        }
        if(x == 3){
            h temp = newNode;
            swap(temp[x], temp[0]);
            out.push_back(temp);
            temp = newNode;
            swap(temp[x], temp[4]);
            out.push_back(temp);
        }
       if(x == 4){ 
            h temp = newNode;
            swap(temp[x], temp[1]);
            out.push_back(temp);
                  
            temp = newNode;
            swap(temp[x], temp[3]);
            out.push_back(temp);
                  
            temp = newNode;
            swap(temp[x], temp[5]);
            out.push_back(temp);
        }
        if(x == 5){ 
            h temp = newNode;
            swap(temp[x], temp[2]);
            out.push_back(temp);
            temp = newNode;
            swap(temp[x], temp[4]);
            out.push_back(temp);
        }
        return out;
    }
    
};