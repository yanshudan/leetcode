#include "util.cpp"
class Solution {
public:
    int depth;
    int mindepth;
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        TreeNode *curr = root;
        vector<vector<int>> ret;
        while (curr)
        {
            //visit current node;
            cout << curr->val << ", ";
            
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
    auto res=Solution().pathSum(root,3);
    for(auto e:res) cout<<e<<", ";
}