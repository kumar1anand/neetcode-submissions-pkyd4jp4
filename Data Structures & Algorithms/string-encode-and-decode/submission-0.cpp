class Solution {
public:

    string encode(vector<string>& strs) {
        string str="";
        for(auto it:strs){
            int len = it.size();
            str+=to_string(len)+"#"+it;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            //find #
            while(s[j]!='#'){
                j++;
            }
            //stoi==>convert string num into int num
            int len = stoi(s.substr(i,j-i));//pos,length
            //now take the string
            string str = s.substr(j+1,len);
            ans.push_back(str);

            //move i to the forward
            i = j+1+len;
        }
        return ans;
    }
};
