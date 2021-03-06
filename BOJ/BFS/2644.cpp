#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

/*
백준
문제번호 : 2644
문제설명 :
*/

int n,m;
int a, b;
int d[101][101];
int check[101];
vector <int> v[101];
int result = 0;

int main()
{
    cin >> n ;
    cin >> a >> b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y; // x가 부모, y가 자식.
        d[x][y] = 1;
        d[y][x] = 1;
    }
    queue <int> q;
    q.push(a);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (d[cur][i] == 0 || check[i] != 0) continue;
            check[i] = check[cur] + 1;
            q.push(i);
        }
    }
    if (check[b] == 0) cout << -1 << endl;
    else cout << check[b] << endl;

}
