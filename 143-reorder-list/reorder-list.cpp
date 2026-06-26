/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };


 L0 -> L1 -> L2 -> ...... Ln-1 -> Ln

 Using fast and slow pointers, we can get the middle of the linked list

 L0->L1->L2->L3

 L0->L1
 L2->L3 

 */
class Solution {
public:

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL; 
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* head2 = reverse(temp);
        ListNode* p1 = head;
        ListNode* p2 = head2;
        
        while(p1 && p2){
            auto p1_temp = p1->next;
            auto p2_temp = p2->next;
            p1->next = p2;
            p2->next = p1_temp;
            p1 = p1_temp, p2 = p2_temp;
        }

    }
};