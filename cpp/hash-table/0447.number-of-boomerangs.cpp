class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // create an unordered map to store the distances between points
    unordered_map<int, int> distances;
    // initialize the number of boomerangs to 0
    int num_boomerangs = 0;
    
    // loop through each point
    for (int i = 0; i < points.size(); i++) {
        // loop through the remaining points
        for (int j = 0; j < points.size(); j++) {
            // calculate the distance between points i and j
            int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
            // if distance is not already in the unordered map, add it as a key and set its value to 1
            if (distances.find(distance) == distances.end()) {
                distances[distance] = 1;
            }
            // if distance is already in the unordered map, increment its value by 1
            else {
                distances[distance]++;
            }
        }
        // loop through the values in the distances unordered map
        for (auto val : distances) {
            // add the number of boomerangs to the total count using the value of the distance
            num_boomerangs += val.second * (val.second - 1);
        }
        // clear the distances unordered map for the next iteration
        distances.clear();
    }
    
    // return the total number of boomerangs
    return num_boomerangs;
    }
};
