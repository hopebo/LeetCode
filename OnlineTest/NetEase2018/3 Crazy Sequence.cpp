/*
将n个学生进行重新排列，使相邻两个学生的身高差（绝对值）之和最大，输出这个最大值
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int solve(vector<int>& height, int n) {
    int i = 1, j = n - 1;
    int res = 0;
    while (i < j) {
        res += abs(height[i] - height[j]);
        if (i + 1 < j - 2)
            res += abs(height[i] - height[j - 2]);
        i += 2;
        j -= 2;
    }
    i = 2;
    j = n - 2;
    while (i < j) {
        res += abs(height[i] - height[j]);
        if (i + 1 < j - 2)
            res += abs(height[i] - height[j - 2]);
        i += 2;
        j -= 2;
    }
    if (0 < n - 1)
        res += abs(height[0] - height[n - 1]);
    if (0 < n - 2)
        res += abs(height[0] - height[n - 2]);
    return res;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++)
        cin >> height[i];
    sort(height.begin(), height.end());
    int res = 0;
    res = max(res, solve(height, n));
    reverse(height.begin(), height.end());
    res = max(res, solve(height, n));
    cout << res << endl;
    return 0;
}
