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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        
        ListNode* temp = head;
        ListNode* temp2 = head->next;
        int last = head->val;
        
        while (temp2 != nullptr) { // while end of Linked list
            if (temp2->val == last) { // Current number same as last number
                if (temp2->next == nullptr) { // If last element, just delete and break loop
                    temp->next = nullptr;
                    break;
                }
                temp2 = temp2->next; // Not last, then delete that element
                temp->next = temp2; // and move to next element
            } else { // If not the same as last element, jump to next node
                temp = temp2;
                last = temp->val;
                temp2 = temp2->next;
            }
        }
        
        return head; // return the head back
    }
};
