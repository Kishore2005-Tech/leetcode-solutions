static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 2;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> slopeMap;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(abs(dx), abs(dy));
                dx /= g; dy /= g;
                if (dx < 0) { dx = -dx; dy = -dy; }
                else if (dx == 0) dy = abs(dy);
                string key = to_string(dx) + "/" + to_string(dy);
                slopeMap[key]++;
                ans = max(ans, slopeMap[key] + 1);
            }
        }
        return ans;
    }
};
