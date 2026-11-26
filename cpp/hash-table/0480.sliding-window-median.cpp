class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> left;                              // LEFT team (max-heap)
        priority_queue<int, vector<int>, greater<int>> right;  // RIGHT team (min-heap)

        unordered_map<int, int> delayed;   // the notebook of ghosts
        int left_size = 0, right_size = 0; // honest counters (no ghosts)

        // "sweep ghosts off the top"
        auto prune_left = [&]() {
            while (!left.empty() && delayed[left.top()] > 0) {
                delayed[left.top()]--; left.pop();
            }
        };
        auto prune_right = [&]() {
            while (!right.empty() && delayed[right.top()] > 0) {
                delayed[right.top()]--; right.pop();
            }
        };

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            // STEP 1: kick out the oldest (decide team FIRST, prune AFTER)
            if (i >= k) {
                int out = nums[i - k];
                delayed[out]++;                      // it becomes a ghost
                if (out <= left.top()) {
                    left_size--;                     // it was on LEFT
                    if (out == left.top()) prune_left();
                } else {
                    right_size--;                    // it was on RIGHT
                    if (out == right.top()) prune_right();
                }
            }

            // STEP 2: add the new number (Trap 2: never into an empty LEFT)
            prune_left();
            if (!left.empty() && nums[i] <= left.top()) {
                left.push(nums[i]); left_size++;
            } else {
                right.push(nums[i]); right_size++;
            }

            // STEP 3: balance the team sizes
            if (left_size > right_size + 1) {
                prune_left();
                right.push(left.top()); left.pop();
                left_size--; right_size++;
            }
            if (right_size > left_size) {
                prune_right();
                left.push(right.top()); right.pop();
                right_size--; left_size++;
            }

            // STEP 4: read the median (sweep ghosts first)
            if (i >= k - 1) {
                prune_left(); prune_right();
                if (left_size > right_size)
                    ans.push_back(left.top());
                else
                    ans.push_back(((long long)left.top() + right.top()) / 2.0);
            }
        }
        return ans;
    }
};
