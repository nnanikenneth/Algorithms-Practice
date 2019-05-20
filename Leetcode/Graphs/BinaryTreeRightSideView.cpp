/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

///we keep track of levels and distances which represents the information about the 
///leve of a current node
///we also keep track of the previous nodes
///per node for each loop
///remember to always visit left before right in order to view the right side view
///if distance or level changes then we take the last previous value
///dont forget to take the final previous value after the loop as the level criteria
///is not met
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)return {};
        
        queue<TreeNode*> que;
        que.push(root);
        map<TreeNode *, int> dist;
        dist[root] = 0;
        int level = 0;
        
        vector<int> rightSideValues = {};
        TreeNode *prev = NULL;
        
        while(que.size() != 0){
            TreeNode * nextNode = que.front();
            que.pop();
            
            if(dist[nextNode] > level){
                rightSideValues.push_back(prev->val);
                level++;
            }
            
            if(nextNode->left != NULL){
                que.push(nextNode->left);
                dist[nextNode->left] = dist[nextNode] + 1;
            }
            
            if(nextNode->right != NULL){
                que.push(nextNode->right);
                dist[nextNode->right] = dist[nextNode] + 1;
            }
            
            prev = nextNode;
        }
        
        rightSideValues.push_back(prev->val);
        
        return rightSideValues;
    }
};