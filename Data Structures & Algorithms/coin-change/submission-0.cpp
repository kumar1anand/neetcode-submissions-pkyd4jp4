class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&nums, int amount){
        //base condition
        if(amount==0) return dp[amount]= 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        //traverse
        int ans = INT_MAX;
        for(auto it: nums){
            int res = solve(nums,amount - it);
            if(res != INT_MAX){
                ans = min(ans, 1 + res);
            }
        }
        return dp[amount] = ans;
     }
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<int>(amount+1, -1);
        int ans = solve(coins,amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
