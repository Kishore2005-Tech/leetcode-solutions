class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> dp(m + 1, INT_MAX);

        for (int i = 0; i <= m; i++) {
            dp[i] = m - i;
        }

        int curr = 1;

        for (int i = n - 1; i >= 0; i--) {
            int prevDiag = dp[m];
            dp[m] = curr;

            for (int j = m - 1; j >= 0; j--) {
                int temp = dp[j];

                if (word1[i] != word2[j]) {
                    dp[j] = min({
                        1 + temp,      // delete
                        1 + dp[j + 1], // insert
                        1 + prevDiag   // replace
                    });
                }
                else {
                    dp[j] = prevDiag;
                }

                prevDiag = temp;
            }

            curr++;
        }

        return dp[0];
    }
};
