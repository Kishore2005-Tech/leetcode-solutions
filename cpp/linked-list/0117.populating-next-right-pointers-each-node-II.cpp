/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* levelStart = root;

        while (levelStart != nullptr) {
            Node* curr = levelStart;
            Node* dummy = new Node(0); // Dummy node to represent the start of the next level
            Node* prev = dummy;

            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    prev->next = curr->left;
                    prev = prev->next;
                }

                if (curr->right != nullptr) {
                    prev->next = curr->right;
                    prev = prev->next;
                }

                curr = curr->next;
            }

            levelStart = dummy->next; // Move to the next level
            delete dummy; // Free the dummy node
        }

        return root;
    }
};
