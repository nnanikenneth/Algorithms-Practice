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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        int level = 0;
        levelOrderHelper(root, results, level );
        
        int i = 0;
        int j = results.size() - 1;
        while(i < j){
            swap(results[i], results[j]);
            i++;
            j--;
        }
        return results;
    }
    
    
    void levelOrderHelper(TreeNode * root, vector<vector<int>> &results, int level){
        
        if(root == NULL){
            return;
        }
         
        // set up the size of the vector initially
        if(level + 1 > results.size()){
            vector<int> temp;
            results.push_back(temp);
        }
        
        levelOrderHelper(root->left, results, level + 1);
        results[level].push_back(root->val);
        levelOrderHelper(root->right, results, level + 1);        
        
    }
};