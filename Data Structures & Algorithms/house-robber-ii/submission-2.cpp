class Solution {
public:
    int solve(vector<int>&nums, int start, int n, int index, vector<int>&dp){
        if(start == 0 && index >= n-1) return 0;
        if(index > n-1) return 0;
        if(index == n-1) return dp[index] = nums[index];

        if(dp[index] != -1) return dp[index];
        //choice 
        int rob = nums[index] + solve(nums, start, n, index + 2, dp);
        int notRob = solve(nums, start, n, index + 1, dp);

        return dp[index] = max(rob, notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);
        int val1 = solve(nums,0,n,0, dp1);
        int val2 = solve(nums,1,n,1, dp2);
        return max(val1, val2);
    }
};
