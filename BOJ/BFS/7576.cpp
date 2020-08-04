#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
using namespace std;

/*
백준
문제번호 : 7576
문제설명 :
*/
int N, M;
int d[1000][1000]; // 지도
int visited[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int check = 0;
queue <pair<int, int>> q; // 마지막은 벽 수

void bfs() {

    while (!q.empty()) {
       
        int x = q.front().first; // 행
        int y = q.front().second; // 열
        q.pop();
        
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
            
            if (rx >= 0 && rx <= N - 1 && ry >= 0 && ry <= M - 1) { // 벽은 방문할수가없다 
                if (d[rx][ry] != -1 && visited[rx][ry] == 0) { 
                    visited[rx][ry] = visited[x][y] + 1;
                    q.push(make_pair(rx, ry));
                }
           }
           
        }
    }
}

int main()
{
        cin >> M >> N;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++) {
                cin >> d[i][j];
                if (d[i][j] == 1) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                }
            }
        }
        bfs();
        int result = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (d[i][j] != -1 &&visited[i][j] == 0) {
                    check = 1;
                }
                result = max(result, visited[i][j]);
            }
        }
        

        if (check == 1) cout << -1 << endl;
        else cout << result-1 << endl;
}
