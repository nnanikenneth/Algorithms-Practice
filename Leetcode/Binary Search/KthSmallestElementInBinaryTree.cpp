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
    int kthSmallest(TreeNode* root, int k) {
        int sum = 0;
        int val;
        KthSmallestHelper(root, k, sum, val); 
        return val;
    }
    
    void KthSmallestHelper(TreeNode* root, int k, int &sum, int &val){
        if(root->left != NULL){
            KthSmallestHelper(root->left,k, sum, val);
        }
        sum++;
        if(sum == k){
            val = root->val;
            return;
        }
        
        if(root->right != NULL){
             KthSmallestHelper(root->right,k, sum, val);
        }
   
    }
};