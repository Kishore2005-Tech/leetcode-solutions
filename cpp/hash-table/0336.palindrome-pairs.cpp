class Solution {
public:

    bool pallin(string& str, int st, int end){
        while(st < end){
            if(str[st] != str[end]){
                return false;
            }
            st++;
            end--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> ump;

        for(int i = 0; i < words.size(); i++){
            ump[words[i]] = i;
        }

        vector<vector<int>> res;

        for(int i = 0; i < words.size(); i++){
            int len = words[i].size();
            string temp = words[i];

            for(int j = 0; j <= len; j++){

                // Case 1: Right part is palindrome
                if(pallin(temp, j, temp.length() - 1)){
                    string left = temp.substr(0, j);
                    string revLeft(left.rbegin(), left.rend());

                    auto it = ump.find(revLeft);

                    if(it != ump.end() && it->second != i){
                        res.push_back({i, it->second});
                    }
                }

                // Case 2: Left part is palindrome
                if(j != 0 && pallin(temp, 0, j - 1)){
                    string right = temp.substr(j);
                    string revRight(right.rbegin(), right.rend());

                    auto it = ump.find(revRight);

                    if(it != ump.end() && it->second != i){
                        res.push_back({it->second, i});
                    }
                }
            }
        }

        return res;
    }
};
