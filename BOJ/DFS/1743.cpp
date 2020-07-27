#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 1743
문제 이름 : 음식물 피하기
문제 설명 : 따라서 선생님은 떨어진 음식물 중에 제일 큰 음식물만은 피해 가려고 한다. 
   */

int n, m, k;
vector <int> v[1001]; 
int visited[101][101];
int d[101][101];
int cnt = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0,0 };

void dfs(int x, int y) {
	if (visited[x][y] == 1) return;

	visited[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int rx = dx[i] + x;
		int ry = dy[i] + y;
		if (rx >= 1 && rx <= n && ry >= 1 && ry <= m) {
			if(d[rx][ry] == 1) dfs(rx, ry);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && d[i][j]==1) {
				cnt = 0;
				dfs(i, j);
				result = max(result, cnt);
			}
			
		}
	}
	cout << result << endl;
}
/*

*/

