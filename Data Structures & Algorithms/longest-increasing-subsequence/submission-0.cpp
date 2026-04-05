class Solution {
public:
    int solve(int curr, int prev, vector<int>&nums){
        //base
        if(curr >= nums.size()) return 0;
        //traverse
        int notTake = solve(curr+1,prev,nums);

        int take = 0;
        if(prev == -1 || nums[prev] < nums[curr]){
            take = 1 + solve(curr+1,curr,nums);
        }
        return max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        return solve(0,-1,nums);
    }
};
