class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, int> M;
        for (auto num : nums)
            M[num]++;

        int res = 0;
        bool flag = false;
        while (head)
        {
            if (M[head->val] == 0 && flag) {
                res++;
                flag = false;
            }
            else if (M[head->val] == 1)
                flag = true;

            head = head->next;
        }

        if (flag)
            res++;

        return res;
    }
};
