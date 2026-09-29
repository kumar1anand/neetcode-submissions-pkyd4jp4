class Solution {
public:
    string sortString(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>>m;
        for(auto it: strs){
            string value = it;
            string key = sortString(it);
            m[key].push_back(value);
        }
        for(auto it:m){// Here, it is string
            ans.push_back(it.second);
        }
        return ans;
    }
};
