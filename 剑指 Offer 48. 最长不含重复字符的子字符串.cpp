class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1) return s.size();
        vector<int> dp(s.size() + 1, 0);
        vector<int> hash(128, -1);
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++) {
            dp[i + 1] = hash[s[i]] < i - dp[i] ?
                    dp[i] + 1 :
                    i - hash[s[i]];
            hash[s[i]] = i;
            maxlen = max(maxlen, dp[i + 1]);
        }
        return maxlen;
    }
};