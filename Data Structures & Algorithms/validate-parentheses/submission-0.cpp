class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it: s){
            //st.push(it);
            if(!st.empty() && st.top() == '(' && it == ')'){
                st.pop();
            }else if(!st.empty() && st.top() == '{' && it == '}'){
                st.pop();
            }else if (!st.empty() && st.top() == '[' && it == ']'){
                st.pop();
            }else{
                st.push(it);
            }
        }
        return st.empty();
    }
};
