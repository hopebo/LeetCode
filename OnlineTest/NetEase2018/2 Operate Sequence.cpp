/*
将输入序列中的元素依次加入到空序列的尾部，并且进行一次反转。要求输出将全部元素执行上述操作后得到的序列情况，以' '分隔，最后一个元素后不需要打印空格
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;

    
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int i = n - 1;
    for (; i >= 0; i = i - 2)
        cout << nums[i] << ' ';
    if (n % 2)
        i = 1;
    else
        i = 0;
    for (; i < n; i = i + 2) {
        cout << nums[i];
        if (i + 2 < n)
            cout << ' ';
    }
    return 0;
}
