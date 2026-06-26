class WordDictionary {

    struct TrieNode{
        unordered_map<char, TrieNode*> children;
        bool endOfWord;
        TrieNode(){
            endOfWord=false;
        }
    };
    
    
private:
    TrieNode *root;
    bool searchHelper(TrieNode* curr, string word, int index){
        if(index == word.size()){
            return curr->endOfWord;
        }
        char c = word[index];
        if(c == '.'){
            for(auto &p : curr->children){
                if(searchHelper(p.second, word, index+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(!curr->children.count(c)){
                return false;
            }
            return searchHelper(curr->children[c],word, index+1);
        }
    } 
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if (!curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord= true;
    }
    
    bool search(string word) {
       return searchHelper(root, word, 0); 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */