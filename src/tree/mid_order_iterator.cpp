#include "util.cpp"

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
    BSTIterator(TreeNode* root) {
        curr = left_chain(root);
    }
    TreeNode* left_chain(TreeNode* node){
        while(node->left){
            s.push(node);
            node=node->left;
        }
        return node;
    }
    /** @return the next smallest number */
    int next() {
        if (curr->right)
        {
            curr=left_chain(curr->right);
            return curr->val;
        }
        else
        {
            curr=s.top();
            s.pop();
            return curr->val;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return  !s.empty() || curr->right;
    }
private:
    stack<TreeNode*> s;
    TreeNode* curr;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */