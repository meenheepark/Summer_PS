#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
/*
백준
문제 번호 : 17070
문제 이름 : 파이프 옮기기 1
문제 설명 : 파이프의 한쪽 끝을 (N, N)로 이동시키는 방법의 개수를 구해보자.
dfs아니면 bfs임.. 끝까지 파고드느냐? ㅇㅇ 근데 평소랑 다른것은 움직이는 방법이 다르고 복잡
   */

int N;
int d[17][17];
int visited[17][17];
int result = 0;

void bfs() {
	//시작 11 12에서함.
	queue <pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(1, 2), 0)); // 0은 가로, 1은 세로, 2는 대각선.

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;

		if (x == N && y == N) {
			result++;
			//continue;
		}

		q.pop();
		int rx, ry, rz;
		if (z == 0) { //가로
			for (int i = 0; i < 2; i++) {
				if (i == 0) { // 가로됨
					rx = x; ry = y + 1; rz = 0;
				}
				else { // 대각선됨
					rx = x + 1; ry = y + 1; rz = 2;
				}

				if (rx >= 1 && rx <= N && ry >= 1 && ry <= N) {
					if (rz == 0) {
						if (d[rx][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
					else if (rz == 2) {
						if (d[rx][ry] == 0 && d[rx][ry - 1] == 0 && d[rx - 1][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
				}
			}
		}

		else if (z == 1) { // 세로

			for (int i = 0; i < 2; i++) {
				if (i == 0) { // 세로됨
					rx = x + 1; ry = y; rz = 1;
				}
				else { // 대각선됨
					rx = x + 1; ry = y + 1; rz = 2;
				}

				if (rx >= 1 && rx <= N && ry >= 1 && ry <= N) {
					if (rz == 1) {
						if (d[rx][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
					else if (rz == 2) {
						if (d[rx][ry] == 0 && d[rx][ry-1] == 0 && d[rx-1][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
				}
			}
		}

		else if (z == 2) { // 대각선

			for (int i = 0; i < 3; i++) {
				if (i == 0) { // 가로됨
					rx = x; ry = y + 1; rz = 0;
				}
				else if(i == 1){ // 대각선됨
					rx = x + 1; ry = y + 1; rz = 2;
				}
				else if (i == 2) { // 세로
					rx = x + 1; ry = y; rz = 1;
				}

				if (rx >= 1 && rx <= N && ry >= 1 && ry <= N) {
					if (rz == 1) {
						if (d[rx][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
					else if (rz == 2) {
						if (d[rx][ry] == 0 && d[rx][ry - 1] == 0 && d[rx - 1][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
					else if (rz == 0) {
						if (d[rx][ry] == 0) {
							q.push(make_pair(make_pair(rx, ry), rz));
							visited[rx][ry] = visited[x][y] + 1; // 기존것에 더해야할듯
						}
					}
				}
			}
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> d[i][j];
		}
	}
	//visited[1][1] = 1;
	visited[1][2] = 1;
	bfs();

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visited[i][j];
		}
		cout << endl;
	}*/
	cout << result << endl;
}
/*

*/

