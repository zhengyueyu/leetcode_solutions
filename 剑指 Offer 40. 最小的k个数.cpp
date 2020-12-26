class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (arr.size() == 0) return{};
		vector<int> res;
		//Step 1:建立初始堆，从最后的父节点开始
		for (int n = arr.size() / 2 - 1; n >= 0; n--) {
			sift(arr, n, arr.size() - 1);
		}
		//Step 2: 排序，绕开尾部已经交换过的元素
		for (int n = arr.size() - 1; n >= 0; n--) {
			if (res.size() == k) break;
			res.push_back(arr[0]);
			swap(arr[0], arr[n]);
			sift(arr, 0, n - 1);
		}
		return res;
	}

	void sift(vector<int>& arr, int start, int end) {
		int parent = start;
		int son = start * 2 + 1;
		while (son <= end) {
			//Step 1: 比较两个子节点，把大的挑出来
			//Warning：这里要注意son+1 <= end的条件
			if (son + 1 <= end && arr[son] > arr[son + 1]) son++;
			//Step 2: 如果父节点大于子节点，说明这颗父节点树已经排序完了，因为函数外层是从低到高排的
			if (arr[son] > arr[parent]) return;
			else {
				//Step 3: 继续往子节点排序
				swap(arr[son], arr[parent]);
				parent = son;
				son = 2 * parent + 1;
			}
		}
	}
};