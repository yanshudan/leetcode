#include "util.cpp"
class Solution {
public:
    int tsum;
    vector<TreeNode *> path;
    vector<int> vals;
    void add_path(TreeNode* node){
        //actions when new path is found
        tsum+=node->val;
        path.push_back(node);
        vals.push_back(node->val);
    }
    void rm_path(){
        //actions when retreive from path
        tsum-= *vals.rbegin();
        path.pop_back();
        vals.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        TreeNode *curr = root;
        vector<vector<int>> ret;
        while (curr)
        {
            //visit current node;
            cout << curr->val << ", ";
            
            //visit left subtree
            if (curr->left)
            {
                add_path(curr);
                curr = curr->left;
            }
            //visit right subtree
            else if (curr->right)
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
                        }
                    }
                    if (curr == root)
                        return ret;
                    last = curr;
                    curr = *path.rbegin();
                    rm_path();
                }
            }
        }
    return ret;
    }
};
int main(){
    TreeNode *root = new TreeNode(4, new TreeNode(9, new TreeNode(5, nullptr, nullptr), new TreeNode(1, nullptr, nullptr)), new TreeNode(0, nullptr, nullptr));
    auto res=postorderTraversal(root);
    for(auto e:res) cout<<e<<", ";
}