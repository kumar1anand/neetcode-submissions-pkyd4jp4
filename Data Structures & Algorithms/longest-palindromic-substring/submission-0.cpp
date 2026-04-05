class Solution {
public:
    string longestPalindrome(string s) {
        //palindrome is what it reads sane forward and backward
        int n = s.size();
        string ans = "";
            int len = 0;

        for(int i=0;i<n;i++){
            //odd
            int left = i;
            int right = i;
            while(left >=0 && right < n && s[left]==s[right]){
                if(right - left + 1 > len){
                    len = right - left + 1;
                    ans = s.substr(left,len);
                }
                left--;
                right++;
            }
            //even 
            left = i;
            right = i+1;
            while(left >= 0  && right < n && s[left]==s[right]){
                if(right - left + 1 > len){
                    len = right - left + 1;
                    ans = s.substr(left,len);
                }
                left--;
                right++;
            }

        }
        return ans;
    }
};
