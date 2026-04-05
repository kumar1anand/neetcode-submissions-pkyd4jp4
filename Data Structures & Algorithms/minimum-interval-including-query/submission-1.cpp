class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //vector<pair<int,int>>v(queries.size(),-1);  //{queries, index}
        int size = queries.size();
        vector<pair<int,int>>v;
        vector<int>ans(size,-1);
        int n = intervals.size();
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        for(int i=0;i<queries.size();i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        sort(intervals.begin(),intervals.end());
        int i = 0;
        for(auto[query,ind] : v){
            //add element in priority queue
            while(i<n && intervals[i][0] <= query){
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r-l+1,r});
                i++;
            }
            //remove an element
            while(!pq.empty() && pq.top().second < query){
                pq.pop();
            }
            //now storing ans
            if(!pq.empty()){
                //ans.push_back(pq.top().first);
                ans[ind] = pq.top().first;
            }
        }
        return ans;
    }
};
