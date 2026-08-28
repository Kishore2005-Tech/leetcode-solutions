class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binary(nums, target, true), binary(nums, target, false)};
    }

    int binary(vector<int>& nums, int target, bool findFirst) {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target > nums[mid]) {
                s = mid + 1;
            } else if (target < nums[mid]) {
                e = mid - 1;
            } else {
                ans = mid;
                if (findFirst)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }
        return ans;
    }
};
