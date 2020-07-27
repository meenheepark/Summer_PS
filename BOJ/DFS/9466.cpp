#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 9466
문제 이름 : 텀프로젝트
문제 설명 : 단방향 그래프에서 싸이클 찾고, 속하지않은 사람 수 세기 
   */
int N, S[100001] , cnt;
bool visited[100001], finished[100001];

void dfs(int curr) {
	visited[curr] = true;
	int next = S[curr];
	if (visited[next]) {
		if (!finished[next]) {
			for (int temp = next; temp != curr; temp = S[temp]) {
				cnt++;
			}
			cnt++;
		}
	}
	else dfs(next);
	finished[curr] = true;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			cin >> S[j];
		}

		fill(visited, visited + N+1, false);
		fill(finished, finished + N+1, false);

		cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (!visited[j]) dfs(j);
		}
		cout << N - cnt << endl;
		
	}
}
/*

*/

