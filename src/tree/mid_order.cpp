#include "util.cpp"
vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode* curr=root;
    stack<TreeNode*> s;
    while(curr){
        if(curr->left){
            s.push(curr);
            curr=curr->left;
        }
        else if(curr->right){
            //visit current node
            visit(curr);
            curr=curr->right;
        }else{
            //visit current node
            visit(curr);
            while(!s.empty() && curr->right==nullptr){
                curr=s.top();
                s.pop();
                //visit current node
                visit(curr);
            }
            curr=curr->right;
        }
    }
    return root;
}
