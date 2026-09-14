class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1) {

            // Number appeared before → cycle
            if (seen.count(n))
                return false;

            seen.insert(n);

            int sum = 0;

            // Calculate sum of squared digits
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};
