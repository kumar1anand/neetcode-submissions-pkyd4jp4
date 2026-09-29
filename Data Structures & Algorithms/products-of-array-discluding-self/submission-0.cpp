class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //first I need to draw how it should look
        //when we draw the relation then we can see 
        vector<int>ans;
        int n = nums.size();
        vector<int>pref(n);
        pref[0] = 1;
        vector<int>suf(n);
        suf[0] = 1;
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]*nums[i-1];
            suf[i] = suf[i-1]* nums[n-i];
        }
        for(int i=0;i<n;i++){
            int val = pref[i] * suf[n-1-i];
            ans.push_back(val);
        }
        return ans;
    }
};
