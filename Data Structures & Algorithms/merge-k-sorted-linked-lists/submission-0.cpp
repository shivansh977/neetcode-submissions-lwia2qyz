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
    int findId(vector<ListNode*>& lists){
        int lowval=INT_MAX,id=-1;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr&&lists[i]->val<lowval){
                lowval=lists[i]->val;
                id=i;
            }
        }
        return id;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int lowval=1e6;
        ListNode* ans=nullptr;
        ListNode* start=nullptr;
        int id=findId(lists);
        while(id!=-1){
            if(ans==nullptr){
                ans=lists[id];
                start=ans;
            }
            else{
                ans->next=lists[id];
                ans=ans->next;
            }
            lists[id]=lists[id]->next;
            id=findId(lists);
        }
        ans->next=nullptr;
        return start;
    }
};
