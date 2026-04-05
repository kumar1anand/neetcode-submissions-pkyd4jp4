class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,1,0,-1};

            for(int k=0;k<4;k++){
                int newX = x + dx[k];
                int newY = y + dy[k];

                if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[x][y]+1 < grid[newX][newY]){
                    grid[newX][newY] = grid[x][y]+1;
                    q.push({newX,newY});
                }
            }
        }
    }
};
