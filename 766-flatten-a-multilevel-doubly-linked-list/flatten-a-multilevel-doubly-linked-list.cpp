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
/*

1 -> 2 -> 3 
*/

    Node* flattenDFS(Node* head){
        Node* curr = head; 
        Node* temp = curr->next;
        Node* chld = curr->child;
        Node* currTail = curr;
        if(chld){
            curr->next = chld;
            chld->prev = curr;
            curr->child = nullptr;
            currTail = flattenDFS(chld);
        }
        if(temp){
            currTail->next = temp;
            temp->prev = currTail;
            currTail = flattenDFS(temp);
        }
        return currTail;
    }

    Node* flatten(Node* head) {
        if(!head) return nullptr;
        flattenDFS(head);
        return head;
    }
};