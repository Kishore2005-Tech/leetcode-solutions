class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};
        vector<int> scount(26, 0);
        vector<int> pcount(26, 0);
        vector<int> v;
        for (int i = 0; i < p.size(); i++) 
        {
            pcount[p[i] - 'a']++;
        }
        int start = 0, end = 0;
        while (end < s.size()) 
        {
            scount[s[end] - 'a']++;
            if (end - start + 1 == p.size()) 
            {
                if (scount == pcount) 
                {
                    v.push_back(start);
                }
                scount[s[start] - 'a']--;
                start++;
            }
            end++;
        }
        return v;
    }
};
