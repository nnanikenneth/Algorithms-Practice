/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/// SOLUTION 
/// DO A BFS ON THE TREE keeping track of a level array that stores all values visited in the levels
/// KEEP TRACK OF LEVELS USING THE DISTANCES COMPUTED WHEN WE PASS THE CURRENT LEVEL
/// take maximum from the level and store in some output array
/// WE CAN OPTIMIZE BY REMOVING THE ARRAY AND TAKING MAX ALL AT ONCE


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)return {};
        
        queue<TreeNode*> que;
        vector<long long> levelNodes;
        vector<int> maxResultPerLevel;
        
        que.push(root);
        map<TreeNode*, long long> dist;
        dist[root] = 0;
        
        long long currentLevel = 0;
    
        while(que.size() != 0){
                        
            TreeNode *curNode = que.front();
            
            que.pop();
            
            if(curNode->right != NULL){
                dist[curNode->right] = dist[curNode] + 1;
                que.push(curNode->right);
            }
        
            if(curNode->left != NULL){
                dist[curNode->left] = dist[curNode] + 1;
                que.push(curNode->left);
            }
            
            if( currentLevel != dist[curNode] ){
                long long maximum = INT_MIN;
                for(int i = 0; i < levelNodes.size(); i++){
                     maximum = max(maximum, levelNodes[i]);
                }
                levelNodes.clear();
                maxResultPerLevel.push_back(maximum);
                currentLevel++;
            }
            
            levelNodes.push_back(curNode->val);
        }
        
        
        //one more traversal since the last level doesn't have constraint{currentLevel != dist[curNode]}
        long long maximum = INT_MIN;
        for(int i = 0; i < levelNodes.size(); i++){
            maximum = max(maximum, levelNodes[i]);
        }
        maxResultPerLevel.push_back(maximum);
        
        return maxResultPerLevel;
    }
};