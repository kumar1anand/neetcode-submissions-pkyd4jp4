class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>s(nums.begin(),nums.end());
        int ans = INT_MIN;
        
        for(auto it: nums){
            int cnt = 0;
            if(s.find(it-1)==s.end()){
                int curr = it;
                while(s.find(curr)!=s.end()){
                cnt++;
                curr++;
            }
          
            ans = max(ans,cnt);
        }
            
        }
        return ans;
    }
};
