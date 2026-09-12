class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        unordered_set<int> s(nums.begin(), nums.end());

        for(auto val: s){
            if(s.find(val-1)==s.end()){
                int x = val;
                int cnt = 1;

                while(s.find(x+1) != s.end()){
                    cnt++;
                    x++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};
