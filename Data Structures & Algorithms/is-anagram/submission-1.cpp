class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>freq;
        for(char it:s){
            freq[it]++;
        }
        for(int i=0;i<t.size();i++){
            if(freq.find(t[i])==freq.end() || freq[t[i]] == 0){
                return false;
            }else{
                freq[t[i]]--;
            }
        }
        return true;
    }
};
