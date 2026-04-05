class Solution {
public:
    unordered_set<string>os;
    vector<int>dp;
    bool solve(string s, int ind){
        if(ind == s.size()) return dp[ind]=true;
        if(dp[ind]!=-1) return dp[ind];
        //traverse
        for(int i =ind;i<s.size();i++){
            string str = s.substr(ind,i-ind+1);
            if(os.count(str) && solve(s,i+1)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size()+1,-1);
        os = unordered_set<string>(wordDict.begin(),wordDict.end());
        return solve(s,0);
    }
};
