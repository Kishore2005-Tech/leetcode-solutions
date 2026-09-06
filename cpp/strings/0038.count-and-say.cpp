class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string RLE = countAndSay(n - 1);

        string newRLE = "";
        int count = 1;

        for (int i = 1; i < RLE.size(); i++) {
            if (RLE[i - 1] == RLE[i]) {
                count++;
            } else {
                newRLE += to_string(count) + RLE[i - 1];
                count = 1;
            }
        }

        newRLE += to_string(count) + RLE[RLE.size() - 1];

        return newRLE;
    }
};
