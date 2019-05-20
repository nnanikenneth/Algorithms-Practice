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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL){
            return false;
        }
        pair<int, TreeNode*> parentx;
        pair<int, TreeNode*> parenty;
        
        /// We traverse the tree storing parent and also depth and return both once found
        FindParent(root, 0, x, parentx);
        FindParent(root, 0, y, parenty);
        
        return (parentx.first) == (parenty.first) && (parentx.second)->val != (parenty.second)->val;
    }
    
    void FindParent(TreeNode* root, int depth, int value, pair<int, TreeNode*> &parent){
        if(root->left != NULL){
            if(root->left->val == value){
                parent.first = depth + 1;
                parent.second = root;
            }
            FindParent(root->left, depth + 1, value, parent);
        }
        
        if(root->right != NULL){
            if(root->right->val == value){
                parent.first = depth + 1;
                parent.second = root;
            }
            FindParent(root->right, depth + 1, value, parent);
        }
    }
};