/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *p1 = head;
        ListNode *p2 = slow->next;
        slow->next = nullptr;


        ListNode *prev = nullptr;
        ListNode* curr = p2;
        while(curr){
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        //reconnect lists
        p2 = prev; 
        /*

        1->2->3
        5->4

       */ 
        while(p1){
            ListNode *tmp1 =p1->next;
            ListNode *tmp2 = p2 ? p2->next : nullptr;
            p1->next = p2;
            if(p2) p2->next = tmp1;
            p1 = tmp1;
            p2 = tmp2;
        }




    }
};