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
int d[1000][1000]; // 지도
int visited[1000][1000][2];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int check = 0;
queue < pair<pair<int, int>, int>> q; // 마지막은 벽 수

int bfs() {
    q.push(make_pair(make_pair(0, 0), 0));

    visited[0][0][0] = 1; // 0 은 안부심

    while (!q.empty()) {
       
        int x = q.front().first.first; // 행
        int y = q.front().first.second; // 열
        int block = q.front().second;

        q.pop();
        
        if (x == N-1 && y == M-1) {
            return visited[N-1][M-1][block];
        }
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
            
            if (rx >= 0 && rx <= N - 1 && ry >= 0 && ry <= M - 1) { // 벽은 방문할수가없다 
                if (d[rx][ry] == 1 && block == 0) { // 벽이있고 아직 안뚫었으면 뚫는다
                    visited[rx][ry][block + 1] = visited[x][y][block] + 1;
                    q.push(make_pair(make_pair(rx, ry), block+1));
                }
            
             else if (d[rx][ry] == 0 && visited[rx][ry][block] == 0) { // 벽없고 방문안함
                    visited[rx][ry][block] = visited[x][y][block] + 1; // 안뚫고나간다
                    q.push(make_pair(make_pair(rx, ry), block));
              }
           }
           
        }
    }
    return -1;
}

int main()
{
        cin >> N >> M;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++){
            string temp;
            cin >> temp;
            for (int j = 0; j < M; j++)
                d[i][j] = temp[j] - '0';
        }

        
      
        
        cout << bfs() << endl;
}
