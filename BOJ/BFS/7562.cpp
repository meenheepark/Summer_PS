#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
using namespace std;

/*
백준
문제번호 : 7562
문제설명 :
*/
int last_x, last_y, start_x, start_y;
int n;
int check[300][300];
int l;
int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,2,1,-2,-1};

void bfs() {
    queue <pair <int, int>> q;
    q.push(make_pair(start_x, start_y));
    check[start_x][start_y] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        if (x == last_x && y == last_y) return;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < l && ry >= 0 && ry < l) {
                if (check[rx][ry] == 0) {
                    check[rx][ry] = check[x][y] + 1;
                    q.push(make_pair(rx, ry));
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        memset(check, 0, sizeof(check));
        cin >> l;
        cin >> start_x >> start_y;
        cin >> last_x >> last_y;
        bfs();
        cout << check[last_x][last_y] << endl;
    }
}
