class Solution {
public:
    string replaceSpace(string s) {
        string res;
        if(s.empty()) return res;
        int blank = 0;
        for(const char& i : s)
            if(i == ' ') blank++;
        int index = s.size() - 1;
        s.resize(blank * 2 + s.size());  //这里是乘2不是乘3，因为是替换原字符串中的位置
        int sindex = s.size() - 1;
        while(index >= 0) {
            if(s[index] == ' ') {
                s[sindex--] = '0';
                s[sindex--] = '2';
                s[sindex--] = '%';
                index--;
            }
            else {
                s[sindex--] = s[index--];
            }
        }
        return s;
    }
};