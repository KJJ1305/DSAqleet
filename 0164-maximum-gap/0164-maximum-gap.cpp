class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<2)
            return 0;
        int maxdiff=INT_MIN;
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            maxdiff=max(maxdiff,diff);
        }
        return maxdiff;
    }
};