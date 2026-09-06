class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        vector<bool> prev(n + 1, false), curr(n + 1, false);
        prev[0] = true;

        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
        }

        for (int i = 1; i <= m; i++) {
            fill(curr.begin(), curr.end(), false);

            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};
