class Solution {
public:
    int solve(vector<int>& nums, int n, int index, vector<int>&dp){
        //base condition
        if(index==n-1) return dp[index] = nums[index];
        if(index > n-1) return 0;

        if(dp[index] != -1) return dp[index];
        //choice
        int rob = nums[index] + solve(nums, n, index+2, dp);
        int notRob = solve(nums, n, index+1, dp);

        return dp[index] = max(rob, notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(nums,n,0, dp);
    }
};
