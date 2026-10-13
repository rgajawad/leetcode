class WordDictionary {
    struct Node {
        Node* ch[26] = {};
        bool isEnd = false;
    };

public:
    WordDictionary()  {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->ch[i]) cur->ch[i] = new Node();
            cur = cur->ch[i];
        }
        cur->isEnd = true;
        
    }
    
    bool search(string word) {
        return searchHelper(root, word);
    }
    /**
    
    */

    bool searchHelper(Node *node, string word){
        if(word.empty()){
            return node->isEnd;
        }
        Node* cur = node;
        for (int j = 0; j < word.size(); j++) {
            char c = word[j];
            if(c == '.'){
                for(int i = 0; i < 26; i++){
                    if(cur->ch[i]){
                        if(searchHelper(cur->ch[i], word.substr(j+1))) return true;
                    }
                }
                return false;
            }
            int i = c - 'a';
            if (!cur->ch[i]) return false;
            cur = cur->ch[i];
        }
        return cur->isEnd;


    }


private:
    Node *root;

    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 **/