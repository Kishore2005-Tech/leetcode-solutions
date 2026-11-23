class Solution {
public:
    char findTheDifference(string s, string t) {
        long long sum = 0, diff = 0;

        for (char c : t) {
            sum += c - 'a';
        }

        for (char c : s) {
            diff += c - 'a';
        }

        return char(sum - diff + 'a');
    }
};
