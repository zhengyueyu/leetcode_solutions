class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		int sum = 3;
		int i = 1;
		int j = 2;
		int range = target / 2;
		vector<vector<int>> res;
		vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		while (i <= range && i < j) {
			if (sum < target) {
				j++;
				sum += j;
				vec.push_back(j);
			}
			else if (sum > target) {
				sum -= i;
				i++;
				vec.erase(vec.begin());
			}
			else {
				res.push_back(vec);
				sum -= i;
				i++;
				vec.erase(vec.begin());
			}
		}
		return res;
	}
};