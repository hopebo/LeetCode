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

vector<int> solve(vector<int>& num1, vector<int>& num2) {
    int len1 = num1.size(), len2 = num2.size();
    vector<int> res(len1 + len2 - 1, 0);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            res[i + j] += num1[i] * num2[j];
        }
    }
    int cf = 0;
    for (int i = 0; i < len1 + len2 - 1; i++) {
        int sum = res[i] + cf;
        res[i] = sum % 10;
        cf = sum / 10;
    }
    while (cf != 0) {
        res.push_back(cf % 10);
        cf = cf / 10;
    }
    return res;
}

string strip(string str) {
    int len = str.size(), i = 0;
    while (i < len && str[i] == '0')
        i++;
    return i < len ? str.substr(i) : "0";
}

int main() {
    string str1, str2, str_res = "";
    cin >> str1 >> str2;
    if (str1.empty() || str2.empty()) {
        cout << str_res << endl;
        return 0;
    }
    str1 = strip(str1), str2 = strip(str2);
    vector<int> num1, num2;
    for (int i = static_cast<int>(str1.size()) - 1; i >= 0; i--)
        num1.push_back(str1[i] - '0');
    for (int i = static_cast<int>(str2.size()) - 1; i >= 0; i--)
        num2.push_back(str2[i] - '0');
    vector<int> res(solve(num1, num2));
    for (int i = static_cast<int>(res.size()) - 1; i >= 0; i--)
        str_res.push_back(res[i] + '0');
    cout << strip(str_res) << endl;
    return 0;
}
