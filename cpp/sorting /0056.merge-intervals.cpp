
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        if(intervals.empty()) 
            return result;
        
        // Step 1: Sort intervals
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Start with first interval
        vector<int> current = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++) {
            // If overlapping
            if(intervals[i][0] <= current[1]) {
                current[1] = max(current[1], intervals[i][1]);
            } 
            else {
                result.push_back(current);
                current = intervals[i];
            }
        }
        
        // Push last interval
        result.push_back(current);
        
        return result;
    }
};
