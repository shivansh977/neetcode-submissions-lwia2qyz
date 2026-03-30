class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* tmp = head;
        int siz = 0;
        while (tmp != nullptr) {
            tmp = tmp->next;
            siz++;
        }
        ListNode* fHead = nullptr;
        ListNode* pTail = nullptr;
        ListNode* n1 = head;
        for (int i = 0; i < siz / k; i++) {
            // reverse k nodes
            ListNode* prev = nullptr;
            ListNode* curr = n1;
            for (int j = 0; j < k; j++) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            if (!fHead) fHead = prev;
            if (pTail) pTail->next = prev;
            pTail = n1;
            n1 = curr;
        }

        // connect remaining nodes
        if (pTail) pTail->next = n1;

        return fHead;
    }
};
