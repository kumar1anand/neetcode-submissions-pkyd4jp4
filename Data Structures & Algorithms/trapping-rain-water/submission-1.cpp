class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pref(n,0);
        vector<int>suf(n,0);
        // int pref[n];
        // int suff[n];
        int maxLeft = 0;
        int maxRight = 0;
        for(int i=0;i<n;i++){
            maxLeft = max(maxLeft,height[i]);
            pref[i] = maxLeft;
        }
        for(int i=n-1;i>=0;i--){
            maxRight = max(maxRight,height[i]);
            suf[i] = maxRight; 
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int water = min(suf[i],pref[i])-height[i];
            ans+=water;
        }
        return ans;
    }
};
