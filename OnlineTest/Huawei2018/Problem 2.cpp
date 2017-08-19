nclude <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include<stdlib.h>
using namespace std;

map<string, set<string>> matrix;
map<string, set<string>> beDepend;
set<string> nums;
map<string, bool> res;

void AddDependency (string ModuleId, string DependModuleId) {
    matrix[ModuleId].insert(DependModuleId);
    beDepend[DependModuleId].insert(ModuleId);
    if (!nums.count(ModuleId))
        nums.insert(ModuleId);
    if (!nums.count(DependModuleId))
        nums.insert(DependModuleId);
    return;
}

bool MouldelsCycularDependency(string ModuleId) {
    if (res.count(ModuleId))
        return res[ModuleId];
    else
        return true;
}

void clear(){
    matrix.clear();
    beDepend.clear();
    nums.clear();
    res.clear();
    return;
}
/*
string uinttostr(unsigned int num) {
    string res = "";
    char letter[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    while (num != 0) {
        int a = num % 16;
        res.push_back(letter[a]);
        num = num / 16;
    }
    if (res.size() < 8)
        res.push_back('0');
    res += "x0";
    reverse(res.begin(), res.end());
    return res;
}*/

int main() {
    char line[30];
    while (cin.getline(line, 30)) {
        string str = line;
        int index1 = str.find_first_of(',');
        string ModuleId = str.substr(1, index1 - 1);
        int index2 = str.find_first_of('}', index1);
        string DependModuleId = str.substr(index1 + 2, index2 - index1 - 2);
        AddDependency(ModuleId, DependModuleId);
        if (str.back() != ',')
            break;
    }
    
    queue<string> node;
    for (set<string>::iterator it = nums.begin(); it != nums.end(); it++) {
        if (!matrix.count(*it))
            node.push(*it);
    }
    
    while (!node.empty()) {
        int len = node.size();
        for (int i = 0; i < len; i++) {
            string num = node.front();
            node.pop();
            res[num] = false;
            for (set<string>::iterator it = beDepend[num].begin(); it != beDepend[num].end(); it++) {
                matrix[*it].erase(num);
                if (matrix[*it].empty())
                    node.push(*it);
            }
        }
    }
    
    for (set<string>::iterator it = nums.begin();;) {
        bool flag = MouldelsCycularDependency(*it) && matrix[*it].size() == beDepend[*it].size();
        string str = flag ? "true" : "false";
        cout << '{' << *it << ", " << str << '}';
        if (++it != nums.end()) {
            cout << "," << endl;
        } else {
            cout << endl;
            break;
        }
    }
    clear();
    return 0;
}

