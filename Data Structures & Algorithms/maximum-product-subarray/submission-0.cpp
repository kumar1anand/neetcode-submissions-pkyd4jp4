class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1;
        int suf = 1;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(pref == 0) pref =1;
            if(suf==0) suf =1;
            pref = pref*nums[i];
            suf = suf*nums[n-1-i];
            ans = max({pref,suf,ans});
        }
        return ans;
    }
};
