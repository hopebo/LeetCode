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

int diffWays(int size, int allowedChanges, string str) {
	if (allowedChanges <= 0 || str.empty())
		return 1;
	int maxLen = 0, num = 0;
	int start = 0, end = 0;
	while (end < size) {
		if (str[end] == '0') {
			if (allowedChanges > 0) {
				allowedChanges--;
			} else {
				int curLen = end - start;
				if (curLen > maxLen) {
					maxLen = curLen;
					num = 1;
				} else if (curLen == maxLen) {
					num++;
				}
				while (start < size && str[start] == '1') {
					start++;
				}
				start++;
			}
		}
		end++;
	}
	if (end - start == maxLen)
		num++;
	else if (end - start > maxLen)
		num = 1;
	return num;
}

int main() {
	cout << diffWays(5, 1, "00000") << endl;
	return 0;
}

