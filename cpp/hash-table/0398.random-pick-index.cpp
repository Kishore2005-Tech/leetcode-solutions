class Solution {
private:
    unordered_map<int, vector<int>> pos;
public:
    Solution(vector<int>& nums) {
        const int n = nums.size();
        pos.reserve(n);
        for (int i = 0; i < n; ++i) pos[nums[i]].push_back(i);
    }
    int pick(int target) {
        const auto& v = pos[target];
        return v[rand() % v.size()];
    }
};
