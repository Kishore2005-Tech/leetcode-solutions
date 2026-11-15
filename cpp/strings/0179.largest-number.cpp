class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> store;
        for (auto it : nums) {
            store.push_back(to_string(it));
        }

        sort(store.begin(), store.end(), [](string a , string b){
            return a+b > b+a ;
        });

        // 🔹 handle all zeros case
        if (store[0] == "0") return "0";

        string ans = "";
        for (auto &s : store) {
            ans += s;
        }

        return ans;
    }
};
