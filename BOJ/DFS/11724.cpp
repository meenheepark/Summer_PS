#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 11724
문제 이름 : 연결요소의 갯수
문제 설명 : 
   */

int n, m, cnt = 0;
vector <int> v[1001]; // 정점갯수
bool visited[1001];

void dfs(int curr) {
	if (visited[curr] == true) return;

	visited[curr] = true;

	for (int i = 0; i < v[curr].size(); i++) {
		dfs(v[curr][i]);
	}
}

int main()
{
	cin >> n >> m;
	int u, k;
	for (int i = 0; i < m; i++) {
		cin >> u >> k;
		v[u].push_back(k);
		v[k].push_back(u);

		fill(visited , visited + n +1, false);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) { 
			dfs(i); 
			cnt++;
			//cout << i << endl;
		}
	}
	cout << cnt;
}
/*

*/

