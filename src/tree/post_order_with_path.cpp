#include "util.cpp"

vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> path;
    vector<int> res;
    TreeNode *curr = root;
    while (curr)
    {
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
                    //visit current node
                    cout<<curr->val<<", ";
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
                        //visit current node
                        cout<<curr->val<<", ";
                    }
                }
                if(path.empty()) break;
                last = curr;
                curr = path.top();
                path.pop();
            }
            if(curr==root) break;
        };
    }
    return res;
}
int main(){
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5, nullptr, nullptr), new TreeNode(1, nullptr, nullptr)), new TreeNode(0, nullptr, nullptr));
    auto res=postorderTraversal(root);
    for(auto e:res) cout<<e<<", ";
}