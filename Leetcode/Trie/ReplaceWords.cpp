class TrieNode{
    public:
      map<char, TrieNode*> children;
      bool isword;
     
    TrieNode(){
        children = {};
        isword = false;
    }
};

class Solution {
public:
    
    void buildTrie(vector<string> dict, TrieNode *root){
        for(int i = 0; i < dict.size(); i++){
            insertWord(dict[i], root);
        }
    }
    
    void insertWord(string word, TrieNode *root){
        TrieNode *newNode = root;
        for(int i = 0; i < word.size(); i++){
            if(newNode->children.count(word[i]) == 0){
                newNode->children[word[i]] = new TrieNode();
                newNode = newNode->children[word[i]];
            }else{
                newNode = newNode->children[word[i]];
            }
        }
        newNode->isword = true;
    }
    
    string searchGetPrefix(string word, TrieNode *root){
        TrieNode *newNode = root;
        string prefix = "";
        
        for(int i = 0; i < word.size(); i++){

            if(newNode->children.count(word[i]) == 1){
                prefix.push_back(word[i]);
                ///if we are at end of word then return that prefix
                if(newNode->children[word[i]]->isword == true){
                    //becareful of this
                    return prefix;
                    // break;
                }
                newNode = newNode->children[word[i]];
            }else{
                break;
            }
        }
        
        ///be careful of this 
        if(newNode->isword == true){
            return prefix;
        }
        return "";
    }
    
    
    ///entry point 
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode *root = new TrieNode();
        buildTrie(dict, root);
        
        string newSentence = "";
        string word = "";
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] == ' '){
                
                if(word.size() != 0){
                    string prefix = searchGetPrefix(word, root);
                    if(prefix.size() == 0){
                        newSentence = newSentence + word + " ";
                    }else{
                        newSentence = newSentence + prefix + " ";
                    }    
                }
                word = "";
            }else{
                word.push_back(sentence[i]);
            }
        }
        
        if(word.size() != 0){
            string prefix = searchGetPrefix(word, root);
            if(prefix.size() == 0){
                newSentence = newSentence + word;
            }else{
                newSentence = newSentence + prefix;
            }    
        }
        return newSentence;
    }
};



