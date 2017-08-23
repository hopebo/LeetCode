#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include<stdlib.h>
using namespace std;

int binarySearch(vector<int> &nums, int target) {
	int low = 0, high = int(nums.size()) - 1;
	while (low < high) {
		int mid = ceil((low + high) / 2.0);
		if (target >= nums[mid])
			low = mid;
		else
			high = mid - 1;
	}
	return low + 1;
}

int main() {
	int n;
	cin >> n;
	vector<int> id(n, 1);
	for (int i = 1; i < n; i++) {
		cin >> id[i];
		id[i] += id[i - 1];
	}
	cin >> n;
	int m, num;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << binarySearch(id, num) << endl;
	}
    return 0;
}

