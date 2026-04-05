class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(auto it:tasks){
            freq[it]++;
        }
        //priority queue for sorting task based on priority
        priority_queue<int>pq;
        for(auto it:freq){
            pq.push(it.second);
        }
        queue<pair<int,int>>q;//freq,time
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int count = pq.top();
                pq.pop();
                count--;
                if(count>0){
                    q.push({count,time+n});
                }
            }
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
