class TrieNode{
    public:
    map<char, TrieNode*> children;
    int value; 
    bool isleaf;
    
    TrieNode(){
        value = 0;
        isleaf = false;
        children = {};
    }
};

class MapSum {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *node = root;
        for(int i = 0; i < key.size(); i++){
            if(node->children.count(key[i]) == 0){
                node->children[key[i]] = new TrieNode();
                node = node->children[key[i]];
            }else{
                node = node->children[key[i]];
            }
        }
        node->isleaf = true;
        node->value = val;
    }
    
    int sum(string prefix) {
        TrieNode *node = root;
       
        for(int i = 0; i < prefix.size(); i++){
            if(node->children.count(prefix[i]) == 0){
                return 0;
            }else{
                node = node->children[prefix[i]];
            }
        }
        
        int sum = 0;
        explore(node, sum);
        return sum;
    }
    
    void explore(TrieNode *node, int &sum){
        if(node->isleaf == true){
            sum = sum + node->value;
        }
                
        for(auto it : node->children){
            explore(it.second, sum);
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */