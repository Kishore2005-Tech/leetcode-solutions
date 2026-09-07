class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> ans;
        string ss = s;

        auto solve = [&](auto&& self, int i) -> void {
            if (i == n) {
                ans.push_back(ss);
                return;
            }

            if (!isdigit(ss[i])) {
                ss[i] = toupper(ss[i]);
                self(self, i + 1);

                ss[i] = tolower(ss[i]);
                self(self, i + 1);
            } else {
                self(self, i + 1);
            }
        };

        solve(solve, 0);
        return ans;
    }
};
