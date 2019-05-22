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
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int count = 0;
        count = countNodesHelper(root, count);
        return count;
    }
    
    int countNodesHelper(TreeNode* root, int &count) {
        if(root->left){
            countNodesHelper(root->left, count);
        }
        count++;
        if(root->right){
            countNodesHelper(root->right, count);
        }
        return count;
    }
};