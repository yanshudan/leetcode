/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void next(Node* &upcurr,Node* &curr){
        //left child, return right child.
        if(curr==upcurr->left && upcurr->right){
            curr=upcurr->right;
            return;
        }
        //children of upcurr has been traversed,move upcurr;
        upcurr=upcurr->next;

        //find first upcurr with left child or right child.
        while(upcurr!=nullptr && upcurr->left==nullptr && upcurr->right==nullptr) upcurr=upcurr->next;

        //if upcurr hits end, return nullptr
        if (upcurr==nullptr) 
            curr=nullptr;
        //return left or right child if exists;
        else if(upcurr->left) 
            curr=upcurr->left;
        else if(upcurr->right)
            curr=upcurr->right;
        else cout<<"error"<<endl;
        return;
    }
    Node* connect(Node* root) {
        //current pointers in upper layer and lower layer
        Node* upcurr=root;
        if(upcurr==nullptr) return nullptr;
        Node* curr=upcurr->left?upcurr->left:upcurr->right;

        //head pointers in upper layer and lower layer
        Node* uphead=upcurr;
        Node* head=curr;

        //last pointer of curr;
        Node* last=curr;

        while(head!=nullptr){
            //connect current line;
            while(curr!=nullptr){
                // cout<<curr->val<<" ";
                next(upcurr,curr);
                last->next=curr;
                last=curr;
            }
            // cout<<endl;
            //update head pointers, move to next layer
            uphead=head;
            head=uphead->left;
            
            if(head==nullptr) next(uphead,head);
            upcurr=uphead;
            curr=head;

            last=head;
        }
        return root;
    }
};