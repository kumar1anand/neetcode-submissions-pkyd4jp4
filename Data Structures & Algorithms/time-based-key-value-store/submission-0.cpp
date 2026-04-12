class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>m;//{key:int<<<---->>timestamp,value}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()) return "";//means did not find any key value
        auto &temp = m[key];
        int n = temp.size();
        int low = 0;
        int high = n-1;
        string ans = "";
        while(low<=high){
            int mid = low + (high-low)/2;
            if(temp[mid].first <= timestamp){
                ans = temp[mid].second;
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
};
