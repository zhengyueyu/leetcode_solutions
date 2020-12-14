class Solution {
public:
	bool isNumber(string s) {

		//去掉所有前置后置空格
		int k = 0;
		for (; k < s.size(); k++) {
			if (s[k] != ' ') break;
		}
		s = s.substr(k, s.size() - k);
		for (k = s.size() - 1; k >= 0; k--) {
			if (s[k] != ' ') break;
		}
		s = s.substr(0, k + 1);




		if (s.empty()) return false;
		int positive = 0;
		bool eflag = false;
		bool point = false;
		bool for_blank = false;
		int i = 0;
		if (s[0] == '-')
			positive = -1;
		else if (s[0] == '.' && s.size() - 1 != 0) {
			point = true;
			positive = 1;
		}
		else if (s[0] == '+' || isdigit(s[0]))
			positive = 1;
		else
			return false;

		i++;
		for (; i < s.size(); i++) {
			if (s[i] == 'e' || s[i] == 'E') {
				//E   1、之前没出现过  2、不是第一个  3、不是最后一个  4、后面必须是-或数字  5、前面必须是数字
				if (
					eflag || i == s.size() - 1 ||
					(!isdigit(s[i + 1]) && s[i + 1] != '-') ||
					i == 0 ||
					(i != 0 && !isdigit(s[i - 1]))
					)
					return false;
				eflag = true;
			}
			else if (s[i] == '.') {
				if (point == true) return false;
                if (!isdigit(s[i - 1]) && !isdigit(s[i + 1])) return false;
				point = true;
			}
			else if (isdigit(s[i])) {}
			else if (s[i] == '-') {
				if (s[i - 1] != 'e' && s[i - 1] != 'E')
					return false;
                if(i == s.size() - 1) return false;
			}
			else
				return false;
		}
		return true;
	}

private:
	bool isdigit(char c) {
		return c >= '0' && c <= '9';
	}
};