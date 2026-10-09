class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        findSubset(nums, 0, nums.size(), arr);
        return result;
    }

    void findSubset(vector<int>& nums, int index, int n, vector<int>& arr) {
        if (index >= n) {
            result.push_back(arr);
            return;
        }

        // Include current element
        arr.push_back(nums[index]);
        findSubset(nums, index + 1, n, arr);

        // Exclude current element (Backtrack)
        arr.pop_back();
        findSubset(nums, index + 1, n, arr);
    }
};
