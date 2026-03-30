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
    bool hasCycle(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return false;
        ListNode* p1=head;
        ListNode* p2=head;
        while(p2!=nullptr&&p2->next!=nullptr){
            p1=p1->next;
            p2=p2->next->next;
            if(p1==p2) break;
        }
        if(p1==p2&&p1!=nullptr){
            return true;
        }
        return false;
    }
};
