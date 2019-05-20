/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// THE SOLUTION IS THIS

// to recurse to the left then to the right but keep track of lowest level node encountered first
// the first left node in each level will be the leftest in that level 
// so the last left node in the last level will be the leftest node for the tree

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        //handle base case
        if(root == NULL){
            return -1;
        }
        //end base cases
        
        int level = 0;
        int currentDept = 0;
        int currentLeftestNodeValue = root->val;
        findBottomLeftValueHelper(root, level, currentDept, currentLeftestNodeValue);
        
        return currentLeftestNodeValue;
    }
    
    void findBottomLeftValueHelper(TreeNode* root, int level, int &currentDept, int &currentLeftest){
        
        if(root->left != NULL){
            findBottomLeftValueHelper(root->left, level + 1,  currentDept, currentLeftest);
        }
        if(level > currentDept){
            currentDept = level;
            currentLeftest = root->val;
        }
        if(root->right != NULL){
            findBottomLeftValueHelper(root->right, level + 1,  currentDept, currentLeftest);
        }        
    }
    
};