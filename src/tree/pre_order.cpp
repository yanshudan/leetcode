#include "util.cpp"
vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> res;
    auto *curr = root;
    while (curr)
    {
        //visit current node
        visit(curr);
        //visit left subtree
        if (curr->left){
            if(curr->right) s.push(curr);
            curr = curr->left;
        }
        else if (curr->right){
            //visit right subtree
            curr = curr->right;
        }
        else{
            //for leaf node
            if (!s.empty()){
                curr = s.top();
                s.pop();
            }
            curr = curr->right;
        }
    }
    return res;
}
