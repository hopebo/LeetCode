/*
题目中对最大的点的定义为右上方区域不存在点（即横纵坐标都大于当前点坐标的点），所有如果只存在横纵坐标相等的点，该点也属于“最大的”点。
因此在对坐标进行排序时，优先将纵坐标从大到小排序，如果纵坐标相同的，优先按照横坐标从小到大排序（优先遍历横坐标小的，因为整个输出的过程是横坐标不断增大，
后面的点的纵坐标肯定是小于等于前面得点的纵坐标的，所以其相应的横坐标一定要大于等于前面的最大横坐标）。
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <stack>
#define INT_MAX 0x7fffffff
#define INT_MIN 0x80000000
using namespace std;

bool cmp(const pair<int, int> &point1, const pair<int, int> &point2) {
	return point1.second > point2.second || (point1.second == point2.second && point1.first < point2.first);
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> point;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		point.push_back(pair<int, int>(x, y));
	}
	sort(point.begin(), point.end(), cmp);
	int max_x = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (point[i].first >= max_x) {
			cout << point[i].first << " " << point[i].second << endl;
			max_x = point[i].first;
		}
	}
	return 0;
}
