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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int siz=0;
        while(tmp!=nullptr){tmp=tmp->next;siz++;}
        int id=siz-n;
        int cur=0;
        ListNode* prev=nullptr;
        tmp=head;
        while(cur<id){
            cur++;prev=tmp;tmp=tmp->next;
        }
        if(prev==nullptr) head=tmp->next;
        else prev->next=tmp->next;
        tmp->next=nullptr;
        delete tmp;
        return head;
    }
};
