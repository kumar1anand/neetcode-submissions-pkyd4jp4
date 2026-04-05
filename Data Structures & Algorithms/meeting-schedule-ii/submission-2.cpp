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
        vector<pair<int,int>>v;//(meeting start or meeting end and their sign)
        for(auto it: intervals){
            v.push_back({it.start,+1});
            v.push_back({it.end,-1});
        }
        //sorting according to start time
        sort(v.begin(),v.end());
        int ans = 0;
        int meetingRoom = 0;
        for(auto it:v){
            meetingRoom+=it.second;
            ans = max(ans,meetingRoom);
        }
        return ans;
    }
};
