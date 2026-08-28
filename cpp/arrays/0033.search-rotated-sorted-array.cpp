class Solution {
public:
    int n;
    int findK(vector<int>& x) {
        if (n==1) return 0;
        if (n==2) return (x[0]<x[1])?1:0;
        int l=0, r=n, m;
        while(l<r){
            m=(r+l)/2;
            if (m==n-1 || x[m]>x[m+1]) return m;
            if (x[m]>x[l]) l=m;
            else r=m;    
        }
        return m;
    }
    int search(vector<int>& nums, int target) {
        n=nums.size();
        int k=findK(nums);
        auto it=nums.begin();
        if (target>=nums[0] || k==n-1){
            int i=lower_bound(it,it+k+1,target)-it;
            if (i==k+1 || nums[i]!=target) return -1;
            return i;
        }     
        else{
            int i=lower_bound(it+k+1,it+n,target)-it;
            if (i==n || nums[i]!=target) return -1;
            return i;
        }
    }
};
