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
int a[101][101];
int visited[101][101];
vector <int> v;
int result = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
    if (visited[y][x] == 1) return;
    result++;

    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if (rx >= 0 && rx < n && ry >= 0 && ry < m) {
            if (a[ry][rx] == 0 && visited[ry][rx] == 0) dfs(rx, ry);
        }
    }
}

int main()
{
    cin >> m >> n >> k;

    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++) {
            for (int r = y1; r < y2; r++) {
                a[r][j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int j = 0; j < m; j++) {
        for (int r = 0; r < n; r++) {
            if (a[j][r] == 0 && !visited[j][r]) {
                cnt++;
                result = 0;
                dfs(r,j);
                v.push_back(result);
                //cout << j<< r << result<<endl;
            }
        }
    }


    sort(v.begin(), v.end());
    cout << cnt << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
