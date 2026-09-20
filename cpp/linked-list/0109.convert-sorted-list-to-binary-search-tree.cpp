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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        
        ListNode* slow = head, *fast = head, *slow_prev = nullptr;
        
        // Find the middle element (slow pointer)
        while (fast != nullptr && fast->next != nullptr) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Create root node from the middle element
        TreeNode* root = new TreeNode(slow->val);
        
        // Disconnect the left half from the middle
        slow_prev->next = nullptr;
        
        // Recursively construct left and right subtrees
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
