class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        //2nd approach
        // string str="";
        // for(char &it:s){
        //     it = tolower(it);
        // }
        //string str1 = tolower(str);
        int i=0;
        int j=n-1;
        while(i<j){
            while(i< j && ! isalnum(s[i])){
                i++;
            }

            while(i<j && ! isalnum(s[j])){
                j--;
            }

            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
