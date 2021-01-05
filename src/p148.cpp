/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head,ListNode* &tail){
        ListNode* curr=head->next;
        ListNode* last=head;
        ListNode* rtail=tail;
        int value=tail->val;
        while(curr!=rtail){
            if(curr->val>=value){
                last->next=curr->next;
                curr->next=tail->next;
                tail->next=curr;
                tail=curr;
                curr=last->next;
            }
            else
            {
                last=curr;
                curr=curr->next;
            }
        }
        return last;
    }
    void sortList(ListNode* head,ListNode* tail){
        ListNode* middle=partition(head,tail);
        if(middle!=head && head->next!=middle) sortList(head,middle);
        if(middle!=tail && middle->next!=tail) sortList(middle->next,tail);
    }
    ListNode* sortList(ListNode* head) {
        ListNode* curr=head;
        if(curr==nullptr) return curr;
        while(curr->next!=nullptr) curr=curr->next;
        ListNode* tail=curr;
        ListNode* phead=new ListNode(-1);
        phead->next=head;
        sortList(phead,tail);
        return phead->next;
    }
};