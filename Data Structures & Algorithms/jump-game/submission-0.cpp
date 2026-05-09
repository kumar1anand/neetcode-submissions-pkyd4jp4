class Solution {
public:
    bool solve(int ind,int n,vector<int>& nums){
        if(ind==n-1) return true;
        for(int i=ind+1;i<=ind+nums[ind];i++){
            if(nums[ind]!=0){
                if(solve(i,n,nums)) return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n,nums);
    }
};
