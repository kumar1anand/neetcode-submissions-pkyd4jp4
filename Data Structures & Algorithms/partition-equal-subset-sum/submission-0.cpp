class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& nums, int ind, int sum){
        //base condition
        if(sum==0) return true;
        if(ind==nums.size()) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];

        //take
        bool take = false;
        if(nums[ind] <= sum){
            take = solve(nums,ind+1,sum-nums[ind]);
        }
        bool notTake = solve(nums,ind+1,sum);

        return dp[ind][sum] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it: nums){
            sum += it;
        }
        dp.resize(n+1,vector<int>(sum+1, -1));
        if(sum%2 != 0) return false;
        return solve(nums,0,sum/2);
    }
};
