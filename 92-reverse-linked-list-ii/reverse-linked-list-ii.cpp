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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* prevLeft = dummy;
        for(int i = 1; i < left; i++){
            prevLeft = curr;
            curr = curr->next;
        }

        // reverse from left to right
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        ListNode* leftNode = curr;
        for(int i = left; i <= right; i++){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* rightNode = prev;
        prevLeft->next = rightNode;
        leftNode->next = temp;

        return dummy->next;

    }
};