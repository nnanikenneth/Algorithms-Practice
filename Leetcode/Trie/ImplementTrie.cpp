class TrieNode {
  public:
    
    map<char, TrieNode*> children;
    bool isword;
  
    TrieNode(){
        isword = false;
        children = {};
    }
};


class Trie {

    public:
        /** Initialize your data structure here. */
        TrieNode *root;
    
        Trie() {
           root = new TrieNode();
        }

        /** Inserts a word into the trie. */
        void insert(string word) {
            
            TrieNode *copy = root; 
            for(int i = 0; i < word.size(); i++){
                if( copy->children.count(word[i]) == 0){
                    copy->children[word[i]] = new TrieNode();
                    copy = copy->children[word[i]];
                }else{
                    copy = copy->children[word[i]];
                }
            }
            copy->isword = true;
        }

        /** Returns if the word is in the trie. */
        bool search(string word) {
            
            TrieNode *copy = root;
            for(int i = 0; i < word.size(); i++){
                if(copy->children.count(word[i]) == 0){
                    return false;
                }else{
                    copy = copy->children[word[i]];
                }
            }
            
            if(copy->isword){
                return true;
            }
            return false;
        }

        /** Returns if there is any word in the trie that starts with the given                 prefix. */
        bool startsWith(string prefix) {
            TrieNode *copy = root;
            
            for(int i = 0; i < prefix.size(); i++){
                if(copy->children.count(prefix[i]) == 0){
                    return false;
                }else{
                    copy = copy->children[prefix[i]];
                }
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */