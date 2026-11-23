class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        const long long shift = 1e6;
        unordered_map<long long , int> map;
        map.reserve(rectangles.size() * 4);
        map.max_load_factor(0.7f);
        for(int i = 0, n = rectangles.size(); i < n; ++i){
            int x = rectangles[i][0], y = rectangles[i][1];
            int a = rectangles[i][2], b = rectangles[i][3];
            ++map[x * shift + y];
            --map[x * shift + b];
            --map[a * shift + y];
            ++map[a * shift + b];
        }
        int ends = 0;
        for(auto& [_ , mark] : map){
            if(mark){
                if(mark != 1 && mark != -1) return false;
                ++ends;
            }
        }
        return ends == 4;
    }
};
