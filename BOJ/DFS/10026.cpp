#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

/*
백준
문제번호 : 10026
문제설명 :
*/
int m, n, k;
char a[101][101];
int visited[101][101];
vector <int> v;
int result = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, char color) {
    if (visited[x][y] == 1) return;

    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if (rx >= 0 && rx < n && ry >= 0 && ry < n) {
            if (visited[rx][ry] == 0) {
                if (color == a[rx][ry]) {
                    dfs(rx, ry, color);
                }
            }
        }
    }
}

void dfs2(int x, int y, char color) {
    if (visited[x][y] == 1) return;

    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if (rx >= 0 && rx < n && ry >= 0 && ry < n) {
            if (visited[rx][ry] == 0) {
                if (color == a[rx][ry] ||( color == 'R' && a[rx][ry] == 'G' )||( color == 'G' && a[rx][ry] == 'R')) {
                    dfs2(rx, ry, a[rx][ry]);
                }
                /*else if (color == 'R' && a[rx][ry] == 'G') {
                    dfs2(rx, ry, color);
                }
                else if(color == 'G' && a[rx][ry] == 'R') dfs2(rx, ry, color);*/
            }
        }
    }
}

int main()
{
    cin >> n;

    memset(a, NULL, sizeof(a));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int result = 0;
    for (int j = 0; j < n; j++) {
        for (int r = 0; r < n; r++) {
            if (!visited[j][r]) { 
                result++;
                dfs(j, r, a[j][r]);
            }
        }
    }
    cout << result << " ";
    result = 0;
    memset(visited, 0, sizeof(visited));
    for (int j = 0; j < n; j++) {
        for (int r = 0; r < n; r++) {
            if (!visited[j][r]) {
                result++;
                dfs2(j, r, a[j][r]);
                cout << j << r << endl;
            }
        }
    }
    cout << result << endl;

}
