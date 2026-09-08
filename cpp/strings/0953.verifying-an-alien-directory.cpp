    class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char, int> rank;

        // Store the rank of each character.
        for (int i = 0; i < order.size(); i++) {
            rank[order[i]] = i;
        }

        // Compare every adjacent pair of words.
        for (int i = 0; i < words.size() - 1; i++) {

            string w1 = words[i];
            string w2 = words[i + 1];

            int j = 0;

            while (j < w1.size() && j < w2.size()) {

                if (w1[j] != w2[j]) {

                    if (rank[w1[j]] > rank[w2[j]]) {
                        return false;
                    }

                    break;
                }

                j++;
            }

            // Same prefix, but first word is longer.
            if (j == w2.size() && w1.size() > w2.size()) {
                return false;
            }
        }

        return true;
    }
};

/*
📝 Example Dry Run

Input:
words = ["hello", "leetcode"]
order = "hlabcdefgijkmnopqrstuvwxyz"

Step 1️⃣ Build Character Rank
h -> 0
l -> 1
a -> 2
...

Step 2️⃣ Compare Adjacent Words

w1 = "hello"
w2 = "leetcode"

j = 0

'h' vs 'l'

rank['h'] = 0
rank['l'] = 1

✅ 0 < 1

The first different characters are in the correct order.
No need to compare the remaining characters.

🎉 All adjacent pairs are valid.

Return true.
*/
