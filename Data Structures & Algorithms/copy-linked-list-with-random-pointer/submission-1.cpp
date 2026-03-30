/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    map<Node*,Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* ans=new Node(head->val);
        Node* fa=ans;
        Node* tmp=fa;
        Node* h=head;
        m[head]=ans;
        while(head->next!=nullptr){
            ans->next=new Node(head->next->val);
            ans=ans->next;
            head=head->next;
            m[head]=ans;
        }
        head=h;
        while(tmp!=nullptr){
            Node* a=head->random;
            if(a) a=m[a];
            tmp->random=a;
            tmp=tmp->next;
            head=head->next;
        }
        return fa;
    }
};
