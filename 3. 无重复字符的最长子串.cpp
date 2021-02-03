class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        int size = s.size();
        vector<int> dp(128, -1);
        int len = 0;
        int maxlen = 0;
        for(int i = 0; i < size; i++) {
            char ch = s[i];
            if(dp[ch] >= i - len) {
                len = i - dp[ch];
            }
            else {
                len++;
            }
            maxlen = maxlen > len ? maxlen : len;
            dp[ch] = i;
        }
        return len > maxlen ? len : maxlen;
    }
};