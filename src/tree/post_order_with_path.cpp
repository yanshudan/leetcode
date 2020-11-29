#include "util.cpp"
class Solution {
public:
    vector<TreeNode *> path;
    void add_path(TreeNode* node){
        //actions when new path is found
        path.push_back(node);
    }
    void rm_path(){
        //actions when retreive from path
        path.pop_back();
    }
    bool deeper(){ return depth<mindepth;}

    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> path;
        vector<int> res;
        TreeNode *curr = root;
        while (curr)
        {
            //visit left subtree
            if (curr->left && deeper())
            {
                add_path(curr);
                curr = curr->left;
            }
            //visit right subtree
            else if (curr->right && deeper())
            {
                add_path(curr);
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
                            add_path(curr);
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
                    rm_path();
                }
                if(curr==root) break;
            };
        }
        return res;
    }
};
int main(){
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5, nullptr, nullptr), new TreeNode(1, nullptr, nullptr)), new TreeNode(0, nullptr, nullptr));
    auto res=postorderTraversal(root);
    for(auto e:res) cout<<e<<", ";
}