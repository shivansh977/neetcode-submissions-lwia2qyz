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
    int getSize(ListNode* l){
        int a=0;
        while(l!=nullptr){
            a++;l=l->next;
        }
        return a;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        if(getSize(l2)>getSize(l1)){
            swap(l1,l2);
        }
        ListNode* tmp=l1;
        while(l1!=nullptr||l2!=nullptr||carry>0){
            int sum=carry;
            if(l1!=nullptr) sum+=l1->val;
            if(l2!=nullptr) sum+=l2->val;
            l1->val=(sum%10);
            carry=(sum/10);
            if(l1->next==nullptr&&carry){
                l1->next=new ListNode();
            }
            l1=l1->next;
            if(l2) l2=l2->next;
        }
        return tmp;
    }
};
