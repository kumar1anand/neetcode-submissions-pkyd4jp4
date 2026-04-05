class Solution {
public:
    int solve(vector<int>& cost, int index, int n, vector<int>&dp){
        //base condition
        if(index==n-1){
            return dp[index] = cost[index];
        }

        if(index > n-1) return 0;

        if(dp[index]!=-1) return dp[index];

        int choice1 = cost[index] + solve(cost, index +1, n, dp);
        int choice2 = cost[index] + solve(cost, index+2, n, dp);
        return dp[index] = min(choice1, choice2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //1-d dp
        int n = cost.size();
        vector<int>dp(n,-1);
        int val1 = solve(cost,0,n,dp);
        int val2 = solve(cost,1,n,dp);
        return min(val1, val2);
    }
};
