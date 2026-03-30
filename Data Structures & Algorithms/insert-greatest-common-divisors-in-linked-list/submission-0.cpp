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
    int gcd(int a, int b){
        if(a==0){
            return b;
        }
        return gcd(b%a,a);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* head1=head;
        while(head!=nullptr&&head->next!=nullptr){
            int val1=head->val;
            int val2=head->next->val;
            ListNode* tmp=new ListNode(gcd(val1,val2));
            tmp->next=head->next;
            head->next=tmp;
            head=head->next;
            head=head->next;
        }
        return head1;
    }
};