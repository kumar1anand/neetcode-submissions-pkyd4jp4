class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>ans;
        for(auto it:queries){
            int val = INT_MAX;
            for(auto interval: intervals){
                int l = interval[0];
                int r = interval[1];
                if(it>=l && it<=r){
                    val = min(val,r-l+1);
                }
            }
            ans.push_back(val==INT_MAX ? -1: val);
        }
        return ans;
    }
};
