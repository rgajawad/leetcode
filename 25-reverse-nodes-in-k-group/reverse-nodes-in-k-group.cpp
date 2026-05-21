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
// groupPrev -> [k nodes to reverse] -> groupNext

private:
    ListNode* getKth(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;

        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while(true){
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) break;

            // dummy -> 1 -> 2 -> 3 -> 4 -> 5
            
            ListNode* groupNext = kth->next;
            ListNode* curr = groupPrev->next;
            ListNode* groupTail = groupPrev->next;
            ListNode* prev = nullptr;
            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            groupPrev->next = prev;
            groupTail->next = groupNext;

            groupPrev = groupTail;
        }
        return dummy.next;
        
    }
};