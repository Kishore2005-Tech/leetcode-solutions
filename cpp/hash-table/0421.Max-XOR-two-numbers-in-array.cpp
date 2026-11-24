class TrieNode
{
    public:
        TrieNode *children[2];

        TrieNode()
        {
            for(int i=0;i<2;i++) this->children[i] = NULL;
        }
};

class Trie
{
    public:
        TrieNode *root;

        Trie()
        {
            root = new TrieNode();
        }

        void insert(int num)
        {
            TrieNode *curr = root;
            for(int i=30;i>=0;i--)
            {
                int bit = (num>>i)&1;
                if(curr->children[bit]==NULL) curr->children[bit] = new TrieNode();

                curr = curr->children[bit];
            }
        }

        int getMaxXOR(int num)
        {
            int ans = 0;
            TrieNode *curr = root;

            for(int i=30;i>=0;i--)
            {
                int bit = (num>>i)&1;
                int opp = 1-bit;
                if(curr->children[opp]!=NULL)
                {
                    ans   = ans |  (1<<i);
                    curr = curr->children[opp];
                }
                else curr=curr->children[bit];
            }

            return ans;
        }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie();

        for(auto num : nums)
        {
            t->insert(num);
        }

        int ans = 0;
        for(auto num : nums)
        {
            ans = max(ans,t->getMaxXOR(num));
        }

        return ans;
    }
};
