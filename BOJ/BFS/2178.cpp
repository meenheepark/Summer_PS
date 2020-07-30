#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

/*
백준
문제번호 : 2178
문제설명 :
*/

int n,m;
int d[101][101];
int check[101][101] = {0};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
    queue <pair <int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << y << endl;
        q.pop();
        //if (x == n && y == m) break;
        for (int i = 0; i < 4; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < n && ry >= 0 && ry < m) {
                if (d[rx][ry] == 1 && check[rx][ry] == 0) {
                    check[rx][ry] = check[x][y] + 1;
                    q.push(make_pair(rx, ry));
                }
            }
        }
    }
}

int main()
{
    //memset(check, 0, sizeof(check));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &d[i][j]);
        }
    }
    queue <pair <int, int>> q;
    q.push(make_pair(0, 0));
    check[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << y << endl;
        q.pop();
        //if (x == n && y == m) break;
        for (int i = 0; i < 4; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < n && ry >= 0 && ry < m) {
                if (d[rx][ry] == 1 && check[rx][ry] == 0) {
                    check[rx][ry] = check[x][y] + 1;
                    q.push(make_pair(rx, ry));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << check[i][j];
        }
        //cout << endl;
    }
    
    cout << check[n-1][m-1] << endl;

}
