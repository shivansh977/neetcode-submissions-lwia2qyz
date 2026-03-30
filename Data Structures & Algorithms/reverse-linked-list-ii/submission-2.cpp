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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;right--;
        if(right==left) return head;
        ListNode* c1;ListNode* c2;ListNode* c3;ListNode* c4;
        c1=nullptr;
        c2=head;
        for(int i=0;i<left;i++){
            if(c1==nullptr) c1=head;
            else c1=c1->next;
        }
        if(c1!=nullptr) c2=c1->next;
        c3=c2;
        ListNode* prev=c2;
        ListNode* cur=c2->next;
        for(int i=0;i<right-left;i++){
            ListNode* tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        c2=prev;
        c4=cur;
        if(c1!=nullptr) c1->next=c2;
        c3->next=c4;
        if(c1==nullptr) return c2;
        return head;
    }
};