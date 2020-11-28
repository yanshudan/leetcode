#include "util.cpp"

int preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> path;
    TreeNode *curr = root;
    while (curr)
    {
        //visit current node;
        cout << curr->val << ", ";

        //visit left subtree
        if (curr->left)
        {
            path.push(curr);
            curr = curr->left;
        }
        //visit right subtree
        else if (curr->right)
        {
            path.push(curr);
            curr = curr->right;
        }
        else
        {
            //curr is leaf node
            TreeNode *last = nullptr;
            while (1)
            {
                if (last == curr->right)
                {
                    if (curr == root)
                        return ret;
                    last = curr;
                    curr = path.top();
                    path.pop();
                }
                else if (last == curr->left)
                {
                    if (curr->right)
                    {
                        path.push(curr);
                        curr = curr->right;
                        break;
                    }
                    else
                    {
                        if (curr == root)
                            return ret;
                        last = curr;
                        curr = path.top();
                        path.pop();
                    }
                }
            }
        }
    }
    return ret;
}
int main(){
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5, nullptr, nullptr), new TreeNode(1, nullptr, nullptr)), new TreeNode(0, nullptr, nullptr));
    auto res=postorderTraversal(root);
    for(auto e:res) cout<<e<<", ";
}