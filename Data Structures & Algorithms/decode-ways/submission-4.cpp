class Solution {
public:
    vector<int>dp;
    int solve(string s, int ind){
        //base condition
        if(ind==s.size()) return dp[ind] = 1;
        //if(ind==s.size()-1) return dp[ind] = 1;//value can we '0'
        if(s[ind]=='0') return dp[ind] = 0;

        if(dp[ind] != -1) return dp[ind];
        //go forward
        int notTake = 0;
        int take = solve(s,ind+1);
        if(ind+1 < s.size() && (s[ind] == '1' || (s[ind]=='2' && s[ind+1] <= '6'))){
            notTake = solve(s,ind+2);
        }
        return dp[ind] = take + notTake;
    }
    int numDecodings(string s) {
        dp = vector<int>(s.size()+1,-1);
        return solve(s,0);
    }
};
