class LRUCache {
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node *head;
    Node *tail;

    void addNode(Node* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node){
        deleteNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node *node = mp[key];
        moveToFront(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node *node = mp[key];
            node->value = value;
            moveToFront(node);
            return;
        }
        if(mp.size() == capacity){
            Node *lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node *node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */