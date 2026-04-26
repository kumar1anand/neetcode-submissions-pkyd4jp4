class Solution {
public:
    void solve(int indx, vector<int>&temp,vector<vector<int>>&ans,vector<int>& nums){
        if(indx==nums.size()){
            ans.push_back(temp);
            return;
        }
        //include
        temp.push_back(nums[indx]);
        solve(indx+1,temp,ans,nums);
        //exclude
        temp.pop_back();//backtrack
        solve(indx+1,temp,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,temp,ans,nums);
        return ans;
    }
};
