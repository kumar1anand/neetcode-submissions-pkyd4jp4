class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1] < b[1];
        });
        int i = 0;
        int count = 0;
        while(i<n-1){
            int val = intervals[i][1];
            int j=i+1;
            while(j<n && val > intervals[j][0]){
                count++;
                j++;
            }
            i=j;
        }
        return count;
    }
};
