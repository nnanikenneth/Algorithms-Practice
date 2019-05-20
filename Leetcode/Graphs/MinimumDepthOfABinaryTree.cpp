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
    // main solution here
    // int minDepth(TreeNode* root) { //my simplest solution here
    //      if(root == NULL)return 0;
    //      if(root->right == NULL && root->left == NULL)return 1;
    //      if(root->right == NULL && root->left != NULL)return minDepth(root->left) + 1;
    //      if(root->right != NULL && root->left == NULL)return minDepth(root->right) + 1;
    //      return min(minDepth(root->left), minDepth(root->right)) + 1;
    // }
    
    // int secondSolutionToMinDepth(TreeNode* root) { //second solution here
    //      if(root == NULL)return 0;
    //      else if(root->right == NULL && root->left == NULL)return 1;
    //      else if(root->right == NULL && root->left != NULL)return minDepth(root->left) + 1;
    //      else if(root->right != NULL && root->left == NULL)return minDepth(root->right) + 1;
    //      else return min(minDepth(root->left), minDepth(root->right)) + 1;
    // }
    
    int minDepth(TreeNode* root) {
            if(root == NULL)return 0;
            
            int leftSum = (1 << 31) - 1;
            int rightSum = (1 << 31) - 1;
            
            // needed to add this line and the two above
            if(root->right == NULL && root->left == NULL){leftSum = 0; rightSum = 0;} 
            
            if(root->right != NULL)rightSum = minDepth(root->right);
            if(root->left != NULL)leftSum =  minDepth(root->left);
            return 1 + min(leftSum, rightSum);
    }
    
};