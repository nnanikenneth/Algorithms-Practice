/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        int level = 0;
        levelOrderHelper(root, results, level );
        return results;
    }
    
    
    void levelOrderHelper(TreeNode * root, vector<vector<int>> &results, int level){
        
        if(root == NULL){
            return;
        }
        
        if(level + 1 > results.size()){
            vector<int> temp;
            results.push_back(temp);
        }
        
        results[level].push_back(root->val);
        
        
        levelOrderHelper(root->left, results, level + 1);
        levelOrderHelper(root->right, results, level + 1);
    }
};