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
/*


*/
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        while(true){
            ListNode* curr = prev->next;

            // check if the length of the next segment is k or not
            ListNode* iter = curr;
            for(int i = 0; i < k; i++){
                if(!iter) {
                    return dummy->next;
                }
                iter = iter->next;
            }

            ListNode* segmentStart = curr;
            ListNode* reversed = nullptr;

            for(int i = 0; i < k; i++){
                ListNode* nxt = curr->next;
                curr->next = reversed;
                reversed =curr;
                curr = nxt;
            }
            prev->next = reversed;
            segmentStart->next = curr;
            prev = segmentStart;
        }
        return dummy->next;

    }
};