/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)return 0;
        int maxx = 1;
        maxDepthHelper(root, 1, maxx);
        return maxx;
    }
    
    void maxDepthHelper(Node* root, int level, int &maxx){
        if(level > maxx){
            maxx = level;
        }
        
        for(int i = 0; i < root->children.size(); i++){
            if(root->children[i] != NULL){
                maxDepthHelper(root->children[i], level + 1, maxx);
            }
        }
    }
};