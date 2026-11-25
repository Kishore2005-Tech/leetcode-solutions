class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& b) {
        unordered_set<string> bank(b.begin(),b.end());
        queue<pair<string,int>> q;
        q.push({startGene,0});
        bank.erase(startGene);
        vector<char> x={'A','C','G','T'};

        while(!q.empty()){
            auto [gene,moves]=q.front();
            q.pop();

            if(gene==endGene) return moves;
            for(int i=0;i<8;i++){
                char og=gene[i];
                for(auto& ch:x){
                    gene[i]=ch;
                    if(bank.count(gene)){
                        q.push({gene,moves+1});
                        bank.erase(gene);
                    }
                }
                gene[i]=og;
            }
        }
        return -1;
    }
};
