class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int minVal = 0;
        int maxVal = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                minVal = minVal+1;
                maxVal = maxVal+1;
            }else if(s[i]==')'){
                minVal = minVal -1;
                maxVal = maxVal -1;
            }else{
                minVal = minVal -1;
                maxVal = maxVal+1;
            }
            if(minVal<0){
                minVal = 0;
            }
            if(maxVal < 0){
                return false;
            }

        }
        return minVal==0;
    }
};
