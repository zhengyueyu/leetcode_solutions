#pragma once
#ifndef LEETCODE_H
#define LEETCODE_H
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <sstream>


using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* n) :val(x), next(n) {}
};
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* y, TreeNode* z) : val(x), left(y), right(z) {}
};

ListNode* CreateListNode(vector<int>&& vec) {
	ListNode* pre = new ListNode(vec[vec.size() - 1]);
	for (int i = vec.size() - 2; i >= 0; i--) {
		ListNode* node = new ListNode(vec[i], pre);
		pre = node;
	}
	return pre;
}

TreeNode* CreateTreeNode(string&& src) {
	if (src.size() == 0) return nullptr;

	//处理src
	vector<string> tmpRes;
	string tmp;
	for (int i = 0; i < src.size(); i++) {
		if (src[i] == 'n' && src[i + 1] == 'u' && src[i + 2] == 'l' && src[i + 3] == 'l') {
			tmpRes.push_back("null");
			i = i + 3;
			tmp.clear();
		}
		else if (!tmp.empty() && (src[i] < '0' || src[i] > '9')) {
			tmpRes.push_back(tmp);
			tmp.clear();
		}
		else if (src[i] >= '0' && src[i] <= '9'){
			tmp += src[i];
		}
	}
	if (!tmp.empty()) tmpRes.push_back(tmp);


	//反序列化
	queue<TreeNode*> qu;
	TreeNode* root = new TreeNode(atoi(tmpRes[0].data()));
	qu.push(root);
	int size = tmpRes.size();
	int son = 1;
	for (int i = 0; i < size; i++) {
		if (tmpRes[i] == "null") continue;
		TreeNode* node = qu.front();
		if (son < size && tmpRes[son] != "null") {
			node->left = new TreeNode(atoi(tmpRes[son].data()));
			qu.push(node->left);
		}
		son++;
		if (son < size && tmpRes[son] != "null") {
			node->right = new TreeNode(atoi(tmpRes[son].data()));
			qu.push(node->right);
		}
		son++;
		qu.pop();
	}
	return root;
}

#endif