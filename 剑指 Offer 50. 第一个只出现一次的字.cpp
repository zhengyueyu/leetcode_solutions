class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> hash(256, 0);
        for(const char& c : s) {
            hash[c]++;
        }
        for(const char& c : s) {
            if(hash[c] == 1) 
                return c;
        }
        return ' ';
    }
};