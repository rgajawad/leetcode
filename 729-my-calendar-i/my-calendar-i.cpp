class MyCalendar {

struct Node{
    bool lazy = false;
    Node* left = nullptr;
    Node* right = nullptr;
};

Node* root;
const int MAX = 1e9;
private:
    map<int,int> mp;

    bool query(Node* node, int start, int end, int l, int r){
        if(!node || l >= end || r <= start) return false;
        if(node->lazy) return true;
        int mid = start + (end-start)/2;
        return query(node->left, start, mid, l,r) || query(node->right, mid, end, l, r);
    }

    void update(Node* node, int start, int end, int l, int r){
        if(l >= end || r <= start)  return;
        if(l <= start && end <= r){
            node->lazy = true;
            return;
        }
        int mid = start + (end - start)/2;
        if(!node->left) node->left = new Node();
        if(!node->right) node->right = new Node();
        update(node->left, start, mid, l , r);
        update(node->right, mid, end, l , r);

    }

public:
    MyCalendar() {
        root = new Node();
    }

    // [10, 20] [15, 25]
    
    bool book(int startTime, int endTime) {
        if(query(root, 0, MAX, startTime, endTime)) return false;
        update(root, 0,MAX, startTime,endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */