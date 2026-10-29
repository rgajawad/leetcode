/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:


    void dfs(TreeNode *root, string &data){
        if(!root){
            data += "#,";
            return ;
        }
        data += to_string(root->val) + ",";
        dfs(root->left, data);
        dfs(root->right, data);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        dfs(root, data);
        return data;
    }

    TreeNode* build(queue<string> &q){
        string val = q.front();
        q.pop();

        if (val == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(q);
        root->right = build(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        queue<string> q;

        while(getline(ss, val, ',')){
            q.push(val);
        }
        return build(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));