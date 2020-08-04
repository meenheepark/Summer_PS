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
문제번호 : 2206
문제설명 :
*/
int N, M;
int d[1001][1001]; // 지도
int visited[1001][1001][2];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int check = 0;
queue < pair<int, int>> q;

void bfs() {
    q.push(make_pair(0, 0));

    visited[0][0][0] = 1; // 0 은 안부심

    while (!q.empty()) {
       
        int x = q.front().first; // 행
        int y = q.front().second; // 열

        q.pop();
        
        if (x == N-1 && y == M-1) {
            check = 1;
            return;
        }
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
            
            if (rx >= 0 && rx <= N-1 && ry >= 0 && ry <= M-1) { 
                if (visited[x][y][0] != 0 ) { // 벽을 한번도 안부심-> 다음칸을 부시거나 안부시거나.
                    if (d[rx][ry] == 1 && visited[rx][ry][1] == 0) { //부셔야함
                        visited[rx][ry][1] = visited[x][y][0] + 1;
                        q.push(make_pair(rx, ry));
                    }

                    if (d[rx][ry] == 0 && visited[rx][ry][0] == 0) { //안부시고감
                        visited[rx][ry][0] = visited[x][y][0] + 1;
                        q.push(make_pair(rx, ry));
                    }

                }

                else if (visited[x][y][1] != 0 && visited[rx][ry][1] == 0) { // 벽을 이미 한번이라도 부심
                    if (d[rx][ry] == 1) continue;
                    else if (d[rx][ry] == 0) {
                        q.push(make_pair(rx, ry));
                        visited[rx][ry][1] = visited[x][y][1] + 1;
                    }
                }
            }
           
        }
    }
}

int main()
{
    cin >> N >> M;
        check = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++){
            string temp;
            cin >> temp;
            for (int j = 0; j < M; j++)
                d[i][j] = temp[j] - '0';
        }

        bfs();
      
        
        int result = min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]);
        if (result == 0 && check == 1) cout << max(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]) << endl;
        else cout << -1 << endl;
}
