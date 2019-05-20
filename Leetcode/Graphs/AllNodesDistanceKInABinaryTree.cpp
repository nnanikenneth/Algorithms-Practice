/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

///Solution here 
///You should try to compute the parent structure to access parent elements then use this structure then run a BFS algorithm to find all the nodes with distance k

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL) return {};
        map<TreeNode*, TreeNode*> parent;
        preProcessTree(parent, NULL, root);
        
        vector<int> allNodesKdist = findAllNodes(parent, target, K);
        
        return allNodesKdist;
    }
    
    void preProcessTree(map<TreeNode*, TreeNode*> &parent, TreeNode *prev,  TreeNode* root){
        if(root->right){
            preProcessTree(parent, root, root->right);
        }
        
        parent[root] = prev;
        
        if(root->left){
            preProcessTree(parent, root, root->left);
        }
    }
    
    vector<int> findAllNodes(map<TreeNode*, TreeNode*> parent, TreeNode* start, int k){
        
        queue<TreeNode*> que;
        map<TreeNode*, int> dist;
        map<TreeNode*, bool> seen;

        que.push(start);
        dist[start] = 0;
        seen[start] = true;
        
        vector<int> response;
        
        while(que.size() != 0){
            TreeNode* topNode = que.front();
            que.pop();
            
            if(dist[topNode] == k){
                response.push_back(topNode->val);
            }
            
            if(topNode->right){
                if(seen.count(topNode->right) == 0){
                    que.push(topNode->right);
                    dist[topNode->right] = dist[topNode] + 1;
                    seen[topNode->right] = true;
                }
            }
            
            if(topNode->left){
                if(seen.count(topNode->left) == 0){
                    que.push(topNode->left);
                    dist[topNode->left] = dist[topNode] + 1;
                    seen[topNode->left] = true;
                }
            }
            
            ///please escape the null condition here
            if( seen.count(parent[topNode]) == 0 && parent[topNode] != NULL){
                que.push(parent[topNode]);
                dist[parent[topNode]] = dist[topNode] + 1;
                seen[parent[topNode]] = true;
            }
            ///check the parent structure here
        }
        
        return response;
    }
};