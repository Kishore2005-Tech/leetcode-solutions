class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {// TC : O(N)+O(N) = O(N) & SC : O(N)

        //N = s.size();
        
        vector<string>ans;// SC : O((N-9)/2) = O(N) , Not include this space complexity because cosine has asked to return it.
        unordered_map<string,int>m;// SC : O(N-9)*10 = O(N)

        for(int i=0;i+10<=s.size();i++){// TC : O(N-9) = O(N)
            string DNA = s.substr(i,10);// TC : O(10) = O(1)
            m[DNA]++;
        }

        for(auto it : m){// TC : O(N-9) = O(N)
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
