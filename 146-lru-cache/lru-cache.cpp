
/*

  head -> node -> node -> tail

  mp : key -> node 

  get : does it exist in the mp: 
        if it does return value 
        move the node to the top of the list 
  put : if exists in mp, move node to the top of the list and update the value
         otherwise create new node and appennd to the top of the list

 add (node) -> add node to the top of the list
 remove (node) 

*/


struct Node{
    Node* next;
    Node* prev;
    int key, value;
    Node() = default;
    Node(int k, int v){
        key = k;
        value = v;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> key2node;
    int capacity;
    Node* head;
    Node* tail;
    int count;
public:
    LRUCache(int capacity) {
       this->capacity = capacity; 
       head = new Node();
       tail = new Node();
       head->next= tail, tail->prev = head;
       count = 0;

    }
    
    int get(int key) {
        if(!key2node.count(key)){
            return -1;
        }
        Node* node = key2node[key];
        remove(node);
        add(node);
        return node->value;
    }
    
    void put(int key, int value) {
        Node* node;
        if(!key2node.count(key)){
            node = new Node(key, value);
            key2node[key] = node;
            count += 1;
        }
        else{
            node = key2node[key];
            node->value = value;
            remove(node);
        }
        add(node);
        if(count > capacity){
            Node* lru = tail->prev;
            remove(lru);
            key2node.erase(lru->key);
            delete lru;
            count -= 1;
        }
    }

    void remove(Node* node){
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt; 
        nxt->prev = prv;
    }

    void add(Node* node){
        Node* nxt = head->next;
        head->next = node, nxt->prev = node;
        node->next = nxt, node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */