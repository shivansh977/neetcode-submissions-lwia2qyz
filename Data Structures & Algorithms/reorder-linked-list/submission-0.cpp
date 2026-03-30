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
private:
    void reverseList(ListNode*& head){
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur!=nullptr){
            ListNode* n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        head=prev;
    }
public:
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* tmp=head;
        while(tmp!=nullptr){
            n++;tmp=tmp->next;
        }
        tmp=head;
        if(n<=2) return;
        int id=0;
        while(id!=(n-1)/2){
            id++;
            tmp=tmp->next;
        }
        ListNode* n1=head;
        ListNode* n2=tmp->next;
        reverseList(n2);
        tmp->next=nullptr;
        while(true){
            if(n1==nullptr){
                break;
            }
            if(n2==nullptr){
                n1->next==nullptr;
                break;
            }
            ListNode* nn1=n1->next;
            ListNode* nn2=n2->next;
            n1->next=n2;
            n2->next=nn1;
            n1=nn1;
            n2=nn2;
        }
    }
};
