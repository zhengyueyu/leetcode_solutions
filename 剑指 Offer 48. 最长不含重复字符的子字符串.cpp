class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;
        vector<int> dp(128, -1);
        int i = 0;
        int j = 0;
        int maxlen = 0;
        for(int k = 0; k < s.size(); k++) {
            char ch = s[k];

            //不仅ch要出现过，还要出现的位置在当前i~j的范围内
            if(dp[ch] != -1 && dp[ch] >= i) {
                i = dp[ch] + 1;
            }
            dp[ch] = k;
            j = k;
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};