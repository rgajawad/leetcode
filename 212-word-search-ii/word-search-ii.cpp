struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
    TrieNode() = default;
};

class Trie{
   public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
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
};

class Solution {


private:
    vector<vector<char>> board;
    unordered_set<string> res;
    int m, n;

    void dfs(int x, int y, string currWord, TrieNode* node){
        char c = board[x][y];
        if(!node->children.count(c)) return;
        node = node->children[c];

        currWord += c;
        if(node->endOfWord){
            res.insert(currWord);
        }

        board[x][y] = '#';
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto [dx, dy]: dirs){
           int nx = x + dx;
           int ny = y + dy;
           if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '#'){
               dfs(nx, ny, currWord, node);
           }
        }
        board[x][y] = c;
    }

/*
sfs
*/
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        this->board = board;
        m = board.size(), n = board[0].size();
        for(auto word: words){
            trie->insert(word);
        }
        m = board.size();
        n = board[0].size();
        TrieNode* root = trie->root;
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