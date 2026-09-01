const int N = 301;
array<pair<int,int>,N> pre;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int wid) {
        int n = [&]() {
            int tot = 0;
            for(int i = 0; i < words.size(); ++i) {
                int j = i, cnt = 0, spaces = 0, wds = 0;
                while(j < words.size() && cnt < wid) {
                    int curr = words[j].size() + 1;
                    if(curr + cnt <= wid) {
                        ++spaces; ++wds; cnt += curr; ++j; continue;
                    } else if(curr + cnt - 1 == wid) {
                        cnt += curr - 1; ++j; ++wds; break;
                    } else break;
                }
                spaces += (wid - cnt);
                pre[tot] = {spaces, wds};
                i = j - 1;
                tot++;
            }
            return tot;
        }();

        vector<string> ans(n);
        int prev = -1;

        for(int i = 0; i < n; ++i) {
            string s = "";
            int gaps = max(1, pre[i].second - 1);
            int sp = pre[i].first / gaps;
            int rem = pre[i].first % gaps;
            int j;

            if(i == n - 1) { // Last Line
                int sps = pre[i].first;
                for(j = prev + 1; j < prev + pre[i].second; ++j) {
                    s += words[j]; s.push_back(' '); --sps;
                }
                if(j < words.size()) s += words[j];
                s += string(sps, ' ');
                ans[i] = s; break;
            }

            if(pre[i].second == 1) { // Single-word Line
                j = prev + 1;
                s += words[j] + string(pre[i].first, ' ');
                ans[i] = s; prev = j; continue;
            }

            for(j = prev + 1; j < prev + pre[i].second; ++j) { // Normal Line
                s += words[j];
                if(s.size() == wid) continue;
                string sps = string(sp + (rem > 0), ' ');
                s += sps;
                rem -= (rem > 0);
            }
            if(j < words.size()) s += words[j];
            prev = j; ans[i] = s;
        }
        return ans;
    }
};
