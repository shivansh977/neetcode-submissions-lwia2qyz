struct ListNode{
    int val;
    ListNode* next;
    ListNode* prev;
};

class LRUCache {
private:
    unordered_map<int,int> m;
    unordered_map<int,ListNode*> m1;
    ListNode* root;
    ListNode* tail;
    int capacity;
    int size;
    void moveToLast(ListNode* node){
        if(node->next==NULL) return;
        ListNode* p=node->prev;
        ListNode* n=node->next;
        if(p==NULL){
            this->root=n;
        }
        else{
            p->next=n;
        }
        if(n!=NULL) n->prev=p;
        node->prev=tail;
        node->next=NULL;
        tail->next=node;
        this->tail=node;
    }
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        this->size=0;
        this->root=NULL;
        this->tail=NULL;
    }

    ~LRUCache(){}
    
    int get(int key) {
        if(m.find(key)!=m.end()) {
            ListNode* node=m1[key];
            moveToLast(node);
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            ListNode* node=m1[key];
            moveToLast(node);
            m[key]=value;
            return;
        }
        if(this->size==this->capacity){
            ListNode* tmp=root;
            m.erase(tmp->val);
            m1.erase(tmp->val);
            root=root->next;
            if(root!=NULL) root->prev=NULL;
            tmp->next=NULL;
            tmp->prev=NULL;
            delete tmp;
        }
        else{
            this->size++;
        }
        ListNode* nNode=new ListNode();
        nNode->val=key;
        m[key]=value;
        m1[key]=nNode;
        if(this->tail==NULL){
            this->root=nNode;
        }
        else{
            this->tail->next=nNode;
        }
        nNode->prev=this->tail;
        this->tail=nNode;
    }
};
