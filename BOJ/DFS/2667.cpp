#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2667
문제 이름 : 단지번호 붙이기
문제 설명 : 이 문제에서 주의할 점이 입력을 받을 때 문자열로 받아야 한다는 것이다. 
문자열로 받은 후 한글자마다 숫자로 만들어주었다.
   */

int n;
vector <int> v; 
int visited[26][26];
int d[26][26];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0,0 };

void dfs(int x, int y, int num) {
	if (visited[x][y] != 0) return;

	visited[x][y] = num;

	for (int i = 0; i < 4; i++) {
		int rx = dx[i] + x;
		int ry = dy[i] + y;
		if (rx >= 0 && rx < n && ry >= 0 && ry < n) {
			if(d[rx][ry] == 1) dfs(rx, ry, num);
		}
	}
}

int main()
{
	string line;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			d[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == 1 && !visited[i][j]) {
				result++;
				dfs(i, j, result);
			}
		}
	}
	cout << result << endl;
	for (int k = 1; k <= result; k++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == k) {
					cnt++;
				}
			}
		}
		v.push_back(cnt);
	}
	sort(v.begin(), v.end());
	for (int k = 0; k < v.size(); k++) {
		cout << v[k] <<endl;
	}
}
/*

*/

