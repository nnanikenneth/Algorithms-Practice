///Hasmap/Dictionary solution

class MagicDictionary {
public:
    map<string, bool> myDict;
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        map<string, bool> mp;
        for(int i = 0; i < dict.size(); i++){
            mp[dict[i]] = true;
        }
        myDict = mp;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
 
        for(int i = 0; i < word.size(); i++){
            for(int j = 0; j < 26; j++){
                char temp = word[i];
                if('a' + j != temp){
                    word[i] = 'a' + j;
                    if(myDict.count(word) == 1){
                        return true;
                    }
                }
                word[i] = temp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */