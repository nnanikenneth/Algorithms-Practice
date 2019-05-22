class TrieNode {
    public:
        map<char, TrieNode*> children;
        bool isWord = false;
};



///A trie based solution
///inserta all dictionary into trie
///for each word check all prefixes are words in trie
//if they are we do a check on size and lexico graphic order
///this is slower however
class Solution {
public:
    TrieNode *trie;
    
    string longestWord(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            insertInToTrie(root, words[i]);
        }
        
        string longestWord = "";
        for(int i = 0; i < words.size(); i++){
            string tempWord = words[i];
            bool flag = true;
            for(int j = 1; j <= tempWord.size(); j++) {
                string subs = tempWord.substr(0, j);
                if( canFind(root, subs) == false ){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                if(tempWord.size() > longestWord.size()){
                    longestWord = tempWord;
                }
                if(tempWord.size() == longestWord.size()){
                    if(tempWord < longestWord){
                        longestWord = tempWord;
                    }
                }
            }
        }
        
        return longestWord;
    }
    
    void insertInToTrie(TrieNode *&root, string word) {
        TrieNode *walker = root;
        for(int i = 0; i < word.size(); i++){
            if(walker->children.count(word[i]) == 0){
                walker->children[word[i]] = new TrieNode();
                walker = walker->children[word[i]];
            }else{
                walker = walker->children[word[i]];
            }
        }
        walker->isWord = true;
    }
    
    bool canFind(TrieNode *&root, string word) {
        TrieNode *walker = root;
        for(int i = 0; i < word.size(); i++){
            if(walker->children.count(word[i]) == 0){
                return false;
            }
            walker = walker->children[word[i]];
        }
        if(walker->isWord == true){
            return true;
        }
        return false;
    }

};