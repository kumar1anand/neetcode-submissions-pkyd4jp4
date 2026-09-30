class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int>um;
        int ans = INT_MIN;
        for(auto it:nums){
            um[it]++;
        }
        for(auto it: nums){
            int cnt = 0;
            while(um.find(it)!=um.end()){
                cnt++;
                it++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
