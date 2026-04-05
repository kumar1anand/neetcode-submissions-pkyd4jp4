class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        //come before the current interval
        for(int i=0;i<n;i++){
            //new interval come before the current interval
            if(newInterval[1]<intervals[i][0]){
                ans.push_back(newInterval);

                for(int j =i;j<n;j++){
                    ans.push_back(intervals[j]);
                }
                return ans;
            }//new Interval come after the current interval
            else if(intervals[i][1]<  newInterval[0]){
                ans.push_back(intervals[i]);
            }else{
                newInterval[0] = min(intervals[i][0],newInterval[0]);
                newInterval[1] = max(intervals[i][1],newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
