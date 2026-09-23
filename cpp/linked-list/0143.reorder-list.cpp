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

        if(head == nullptr || head->next == nullptr){
            return;
        }

        // Step 1: Find Middle

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split List

        ListNode* second = slow->next;
        slow->next = nullptr;

        // Step 3: Reverse Second Half

        ListNode* prev = nullptr;

        while(second != nullptr){

            ListNode* next = second->next;

            second->next = prev;

            prev = second;
            second = next;
        }

        second = prev;

        // Step 4: Merge

        ListNode* first = head;

        while(second != nullptr){

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
