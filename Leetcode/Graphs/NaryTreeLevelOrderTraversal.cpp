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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        int level = 0;
        vector<vector<int>> results;
        levelOrderHelper(root, level, results);
        return results;
    }
    
    void levelOrderHelper(Node *root, int level, vector<vector<int>> &results) {
        if(results.size() < level + 1){
            vector<int> temp = {};
            results.push_back(temp);
        }
        
        results[level].push_back(root->val);

        for(int i = 0; i < root->children.size(); i++){
            if(root->children[i] != NULL){
                levelOrderHelper(root->children[i], level + 1, results);
            }
        }
    }
};