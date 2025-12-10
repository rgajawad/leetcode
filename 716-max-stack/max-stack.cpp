struct Node{
    Node* next;
    Node* prev;
    int val;
    Node(int val){
       this->val = val; 
       this->next = NULL;
       this->prev = NULL;
    }
};

struct compare{
    bool operator()(Node* a, Node* b) const{
        return a->val < b->val;
    }
};

class MaxStack {

private:
    Node* head;
    Node* tail;
    map<int, vector<Node*>> mp;

public:
    MaxStack() {
        this->head = new Node(-1);
        this->tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void push(int x) {
        Node* node = new Node(x);
        Node* prev_tail = tail->prev;

        prev_tail->next = node;
        node->prev = prev_tail;

        node->next = tail;
        tail->prev = node;
        mp[x].push_back(node);
    }
    
    int pop() {
        Node* prev_tail = tail->prev;
        int val = prev_tail->val;

        Node* node_prev = prev_tail->prev;
        Node* node_next = prev_tail->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;

        mp[val].pop_back();
        if(mp[val].size() == 0) mp.erase(val);

        delete prev_tail;
        return val;
    }
    
    int top() {
        Node* prev_tail = tail->prev;
        return prev_tail->val; 
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int maxVal = mp.rbegin()->first;
        Node* maxNode = mp[maxVal].back();

        mp[maxVal].pop_back();
        if(mp[maxVal].size() == 0) mp.erase(maxVal);
        
        Node* node_prev = maxNode->prev;
        Node* node_next = maxNode->next;

        node_prev->next = node_next;
        node_next->prev = node_prev;
        
        delete maxNode; 
        return maxVal;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */