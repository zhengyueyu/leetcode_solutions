#pragma once
#ifndef __HEAD_LEETCODE_H
#define __HEAD_LEETCODE_H
#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>

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

};

ListNode* CreateListNode(vector<int>&& vec);


#endif
