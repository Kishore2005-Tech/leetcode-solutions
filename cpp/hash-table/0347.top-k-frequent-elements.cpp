class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> dict;

        for(int num : nums)
            dict[num]++;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for(auto& [num, frequency] : dict) {

            pair<int, int> newPair = {
                frequency,
                num
            };

            if(pq.size() < k)
                pq.push(newPair);
            else {
                pq.push(newPair);
                pq.pop();
            }
        }

        vector<int> result;

        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
