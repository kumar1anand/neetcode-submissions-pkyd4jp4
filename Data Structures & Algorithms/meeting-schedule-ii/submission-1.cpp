/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int low = INT_MAX;
        int high = INT_MIN;
        for(auto it: intervals){
            low = min(low,it.start);
            high = max(high,it.end);
        }
        int ans = 0;
        for(int t = low;t<high;t++){
            int cnt = 0;
            for(auto it: intervals){
                if(it.start <= t && it.end>t){
                    cnt++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
