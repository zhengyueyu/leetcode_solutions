class Solution {
public:
	int lastRemaining(int n, int m) {
		if (m == 1) return n - 1;
		int ans = 0;

        //新一轮的开头每次都比上一轮后移m个位置
        //知道2个人参加游戏的结果后，可以按照规律反推更多人参加游戏的结果
        for(int i = 2; i <= n; i++) {
            ans = (ans + m) % i;
        }
        return ans;
	}
};