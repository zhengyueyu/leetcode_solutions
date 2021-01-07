class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int i = 0;
        string temp;
        while(i < s.size()){
            if(s[i] == ' ' && temp != ""){
                st.push(temp);
                temp = "";
                i++;
                continue;
            }
            else if(s[i] == ' '){
                i++;
                continue;
            }
            temp += s[i];
            i++;
            if (i == s.size())
                st.push(temp);
        }
        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
            if(!st.empty())
                result += " ";
        }
        return result;
    }
};