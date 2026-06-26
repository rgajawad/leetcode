struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode(){
        endOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children.count(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix){
            if(!curr->children.count(c)){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */