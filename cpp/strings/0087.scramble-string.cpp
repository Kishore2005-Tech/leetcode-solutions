class Solution {
public:
   int dp[50][50][50];
   bool dfs(string& s1, string& s2 , int i ,int j,int len){
       if(len == 1){
        return s1[i] == s2[j];
       }
       if(dp[i][j][len] != -1)return dp[i][j][len];
       for(int k = 1; k < len; k++){
           bool swap , noswap;
           swap = dfs(s1,s2,i+k,j+k,len-k)&& dfs(s1,s2,i,j,k);
           noswap = dfs(s1,s2,i,j+len-k,k)&& dfs(s1,s2,i+k,j,len-k);

           if(swap || noswap)return dp[i][j][len] = 1;
       }
       return dp[i][j][len] = 0;
   }
    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        int n = s1.size();
        return dfs(s1,s2,0,0,n);
    }
};
