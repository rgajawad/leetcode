/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node *dummy = new Node(0);
        Node *curr = dummy;
        stack<Node*> st;
        st.push(head);
        while(st.size()){
            Node *node = st.top();
            st.pop();

            if(node->next) st.push(node->next);
            if(node->child) st.push(node->child);

            curr->next = node;
            node->prev = curr;
            node->child = nullptr;
            curr = node;
        }
        head->prev = nullptr;
        return head;
    }
};