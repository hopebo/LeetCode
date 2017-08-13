//
//  main.cpp
//  test
//
//  Created by hope on 2017/7/7.
//  Copyright © 2017年 hope. All rights reserved.
//

#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

#define INT_MIN    (-0x7fffffffffffffff - 1)
#define INT_MAX    0x7fffffffffffffff
int main() {
    int n, num;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    long long pos_1 = INT_MIN, pos_2 = INT_MIN, pos_3 = INT_MIN;
    long long neg_1 = INT_MAX, neg_2 = INT_MAX, neg_3 = INT_MAX;
    for (int num : nums) {
        if (num >= pos_1) {
            pos_3 = pos_2;
            pos_2 = pos_1;
            pos_1 = num;
        } else if (num >= pos_2) {
            pos_3 = pos_2;
            pos_2 = num;
        } else if (num >= pos_3) {
            pos_3 = num;
        }
        if (num <= neg_1) {
            neg_3 = neg_2;
            neg_2 = neg_1;
            neg_1 = num;
        } else if (num <= neg_2) {
            neg_3 = neg_2;
            neg_2 = num;
        } else if (num <= neg_3) {
            neg_3 = num;
        }
    }
    long long res = INT_MIN;
    res = max(res, max(pos_1 * pos_2 * pos_3, pos_1 * neg_1 * neg_2));
    cout << res << endl;
    return 0;
}
