class Solution {
public:
    bool canGetToWord(string a, string b){
        int count = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                count++;
            }
        }
        if(count == 1){
            return true;
        }
        return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> que;
        map<string, bool> seen;
        map<string, int> distance;
        que.push(beginWord);
        
        seen[beginWord] = true;
        distance[beginWord] = 1;
        
        int result = 0;
        while(que.size() != 0){
            string frontWord = que.front();
            que.pop();
            for(int i = 0; i < wordList.size(); i++){
                if(canGetToWord(frontWord, wordList[i])){
                    if(seen[wordList[i]] == 0){
                        que.push(wordList[i]);
                        seen[wordList[i]] = true;
                        distance[wordList[i]] = distance[frontWord] + 1;
                        if(wordList[i] == endWord){
                            result = distance[wordList[i]];
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};