class Solution {
public:
    unordered_map<string,multiset<string>>m;
    void dfs(string source, vector<string>&res){
        while(!m[source].empty()){
            string val = *m[source].begin();
            m[source].erase(m[source].begin());
            dfs(val,res);
        }
        res.push_back(source);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto it:tickets){
            string u = it[0];
            string v = it[1];
            m[u].insert(v);
        }
        vector<string>res;
        dfs("JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }
};
