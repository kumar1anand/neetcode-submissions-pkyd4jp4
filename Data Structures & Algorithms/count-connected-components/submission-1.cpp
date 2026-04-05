class Solution {
public:
    void dfs(vector<int>adj[], vector<bool>&vis,int node){
        vis[node] = true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        //create adjancency list
        vector<int>adj[n];
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};
