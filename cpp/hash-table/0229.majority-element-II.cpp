class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        if(n == 0) return ans;
        if(n == 1) return nums;
        int ele1 = -1, ele2 = -1;
        int count1 = 0 ,count2 = 0;


        for(int ele : nums){
            if(ele == ele1){
                count1++;
            }else if(ele == ele2){
                count2++;
            }else if(count1 == 0){
                ele1 = ele;
                count1++;
            }else if(count2 == 0){
                ele2 = ele;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for(int ele : nums){
            if(ele == ele1){
                count1++;
            }else if(ele == ele2){
                count2++;
            }
        }
 
        if(count1>(n/3)){
            ans.push_back(ele1);
        }
        if(count2>(n/3)){
            ans.push_back(ele2);
        }

        return ans;
    }
};
