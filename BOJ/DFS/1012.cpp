#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

/*
백준
문제번호 : 1012
문제설명 :dfs해서 그래프 몇갠지, 이미 방문했으면 0으로 돌려라
*/
int t, m,n, k;

int a[51][51];
vector <int> v[51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
    //cout << x << y << endl;
    if (a[y][x] == 0) return;
    a[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        if(rx >= 0 && rx < m && ry >= 0 && ry < n) dfs(rx, ry);
    }
    return;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> k;
        int x, y, cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 0;
            }
        }

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j][i] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;

    }

}
