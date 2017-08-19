/*
迷宫问题，迷宫中的位置分为6类：0-墙，无法通过；1-路，可以顺利通过；2-起始位置；3-迷宫出口；大写字母-带锁的门；小写字母-门对应的钥匙。
此题使用BFS搜索的方法进行查找，在每个位置时由于获取钥匙的情况不同，所以需要反复遍历，因此需要记录钥匙的状态。为了避免同种状态下对同一个位置重复遍历，
还需要bool类型向量记录某种状态下对该位置是否已经遍历过。携带不同钥匙的状态利用状态压缩的方法用一个整型数来表示，因为门的数量不超过10个，所以用整型数bit位上的0-1表示。
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int row, col, key;
    node(int a, int b, int c) {row = a; col = b; key = c;}
};
char maze[100][100] = {'0'};  //记录迷宫情况
bool stat[100][100][1024] = {false};  //记录每个位置不同钥匙状态下是否进行遍历，如果当前状态为false，则需要将其加入队列重新遍历
int s_row, s_col;
int e_row, e_col;

int solve(int M, int N) {
    queue<node> site;
    int curStep = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    site.push(node(s_row, s_col, 0));
    stat[s_row][s_col][0] = true;
    while (!site.empty()) {
        int len = site.size();
        for (int i = 0; i < len; i++) {
            int cur_row = site.front().row, cur_col = site.front().col, cur_key = site.front().key;
            for (int k = 0; k < 4; k++) {
                int next_row = cur_row + dir[k][0], next_col = cur_col + dir[k][1], next_key = cur_key;
                if (next_row < 0 || next_row >= M || next_col < 0 || next_col >= N || maze[next_row][next_col] == '0' || stat[next_row][next_col][cur_key])
                    continue;
                stat[next_row][next_col][cur_key] = true;
                if (next_row == e_row && next_col == e_col)
                    return curStep + 1;
                if (islower(maze[next_row][next_col]))
                    next_key = cur_key | (1 << (maze[next_row][next_col] - 'a'));
                else if (isupper(maze[next_row][next_col]))
                    if (((1 << (maze[next_row][next_col] - 'A')) & cur_key) == 0)
                        continue;
                site.push(node(next_row, next_col, next_key));
            }
            site.pop();
        }
        curStep++;
    }
    return -1;
}

int main() {
    int M, N;
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '2') {
                s_row = i;
                s_col = j;
            }
            if (maze[i][j] == '3') {
                e_row = i;
                e_col = j;
            }
        }
    }
    cout << solve(M, N) << endl;
    return 0;
}
//详情见：http://blog.csdn.net/lymingha0/article/details/43794879
