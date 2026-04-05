class Twitter {
public:
    Twitter() {
        
    }
    int k = 0;
    unordered_map<int,vector<pair<int,int>>>tweetMap;//{count,tweetId}
    unordered_map<int,unordered_set<int>>followMap;
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({k++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;//{count,tweetId}
        for(auto tweet:tweetMap[userId]){//add your own tween
            pq.push(tweet);
        }

        //add followee tweet
        for(auto followee : followMap[userId]){
            for(auto tweet : tweetMap[followee]){
                pq.push(tweet);
            }
        }
        int k =10;
        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followMap[followerId].insert(followeeId);//why we have used insert here
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
