/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<int> st;
    
    void searchTree(TreeNode *root, stack<int> &st){
        if(root != NULL){
            searchTree(root->right, st);
            st.push(root->val);
            searchTree(root->left, st);
        }
    }
    
    BSTIterator(TreeNode* root) {
        stack<int> temp;
        searchTree(root, temp);
        st = temp;
    }
    
    /** @return the next smallest number */
    int next() {
        int value = st.top();
        st.pop();
        return value;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.size() != 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */