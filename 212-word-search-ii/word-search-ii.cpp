class Solution {

struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode(){
        endOfWord = false;
    }
};

private:
    TrieNode* root;
    vector<vector<char>> board;
    unordered_set<string> res;

    void insert(string word){
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }


    void dfs(int x, int y, string currWord, TrieNode* node){
        int m, n;
        m = board.size(), n = board[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '#') return;
        if(!node->children.count(board[x][y])) return;
        node = node->children[board[x][y]];
        currWord += board[x][y];
        if(node->endOfWord){
            res.insert(currWord);
        }
        char c = board[x][y];
        board[x][y] = '#';
        dfs(x+1, y, currWord, node);
        dfs(x-1, y, currWord, node);
        dfs(x, y+1, currWord, node);
        dfs(x, y-1, currWord, node);
        board[x][y] = c;
    }

/*
sfs
*/
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->root = new TrieNode();
        this->board = board;
        for (auto word: words){
            insert(word);
        }
        int m,n;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(root->children.count(board[i][j])){
                    dfs(i, j, "", root);
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};