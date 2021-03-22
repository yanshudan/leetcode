/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Frame{
    TreeNode* ptr;
    int left_height;
    int right_height;
    Frame(TreeNode* tmp,int lh,int rh):ptr(tmp),left_height(lh),right_height(rh){};
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        stack<Frame> path;
        // TreeNode* curr=root;
        if(root==nullptr) return true;
        Frame curr(root,-1,-1);
        auto visit=[](){
            // cout<<curr.ptr->val<<" "<<curr.left_height<<" "<<curr.right_height<<",";
        };
        auto isBalanced=[](Frame & f){
            return f.left_height<=f.right_height+1 && f.right_height<=f.left_height+1;
        };
        while(true){
            if(curr.ptr->left){
                path.push(curr);
                curr.ptr=curr.ptr->left;
            }
            else if(curr.ptr->right){
                curr.left_height=0;
                path.push(curr);
                curr.ptr=curr.ptr->right;
            }else{
                //leaf node
                // TreeNode* last=nullptr;
                Frame last(nullptr,-1,-1);
                while(true){
                    if(last.ptr==curr.ptr->left){
                        curr.left_height=max(last.left_height,last.right_height)+1;
                        if(curr.ptr->right){
                            path.push(curr);
                            curr.ptr=curr.ptr->right;
                            break;
                        }else{
                            curr.right_height=0;
                        }
                        if(!isBalanced(curr)) return false;
                    }else{
                        //from right subtree
                        curr.right_height=max(last.left_height,last.right_height)+1;
                        if(!isBalanced(curr)) return false;
                    }
                    // visit();
                    last=curr;
                    if(path.empty()) return true;
                    // curr=path.top().ptr;
                    curr=path.top();
                    path.pop();
                }
            }
        }
    }
};`