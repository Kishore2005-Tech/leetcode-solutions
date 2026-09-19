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
    void reverse(ListNode*& head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* counter=head;
        int count=0;
        while (counter!=NULL) {
            counter=counter->next;
            count++;
        }
        ListNode* prev=NULL;
        ListNode* temp2=head;
        for (int i=0;i<count/k;i++){
            ListNode* temp3=temp2;
            ListNode* temp4=temp2;
            for(int i=0;i<k-1;i++){
                temp2=temp2->next;
            }
            ListNode* nxt=temp2->next;
            temp2->next=NULL;
            reverse(temp3);
            if(i==0) {
                head=temp3;
            }
            temp2=temp4;
            temp2->next=nxt;
            if (prev!=NULL) {
                prev->next=temp3;
            }
            prev=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};
