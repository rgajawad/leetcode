class LFUCache {
    struct Node{
        int value;
        int freq;
        list<int>::iterator it;
    };
    int capacity;
    int minFreq;

    unordered_map<int, Node> nodes;
    // frequency -> keys with this  frequency
    unordered_map<int, list<int>> freqList;

    void increaseFrequency(int key){
        Node &node = nodes[key];
        int oldFreq = node.freq;
        freqList[oldFreq].erase(node.it);

        if(freqList[oldFreq].empty()){
            freqList.erase(oldFreq);
            if(minFreq == oldFreq) minFreq++;
        }
        node.freq++;

        freqList[node.freq].push_front(key);
        node.it = freqList[node.freq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        
    }
    
    int get(int key) {
        if(!nodes.count(key)) return -1;
        int value = nodes[key].value;
        increaseFrequency(key);
        return value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(nodes.count(key)){
            nodes[key].value = value;
            increaseFrequency(key);
            return;
        }

        if(nodes.size() == capacity){
            int keyToRemove = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if(freqList[minFreq].empty()) freqList.erase(minFreq);
            nodes.erase(keyToRemove);
        }

        minFreq = 1;
        freqList[1].push_front(key);

        nodes[key] = {
            value,
            1,
            freqList[1].begin()
        };

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */