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
문제번호 : 3055
문제설명 :
*/
int R, C;
char d[1001][1001]; // 지도
int water[1001][1001]; // 불 번지는시간구하기
int visited[1001][1001]; //상근이가지나가는 시간 구하기
int start_x, start_y;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int check = 0;
int last_x, last_y;
queue < pair<int, int>> q;
queue < pair<int, int>> water_q;

void bfs2() { // 물을 위한 함수

    while (!water_q.empty()) {
        int x = water_q.front().first; // 행
        int y = water_q.front().second; // 열
        water_q.pop();
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < R && ry >= 0 && ry < C) {
                if (water[rx][ry] == 0 && d[rx][ry] != 'X' && d[rx][ry] != 'D') { // 벽이아니면 나간다.
                    water[rx][ry] = water[x][y] + 1;
                    water_q.push(make_pair(rx, ry));
                }
            }
        }
    }
}

void bbfs() {
    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = 1; // 0인걸로 체크하는거랑 비교가 안대서 1로 설정하고 나중에 빼준다

    while (!q.empty()) {
        
        int x = q.front().first; // 행
        int y = q.front().second; // 열
        if (x == last_x && y == last_y) {
            check = 1;
            return;
        }
        
        q.pop();
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
          
            if (rx >= 0 && rx < R && ry >= 0 && ry < C) { 
                if (visited[rx][ry] == 0) { // 벽이아니면 나간다.
                    if (d[rx][ry] != 'X' && (water[rx][ry] > visited[x][y] + 1 || water[rx][ry] == 0 )) { // 불보다 빨리간다.
                        visited[rx][ry] = visited[x][y] + 1;
                        q.push(make_pair(rx, ry));
                    }
                }
            }
           
        }
    }
}

int main()
{
    cin >> R >> C;
        check = 0;
        memset(water, 0, sizeof(water));
        memset(visited, 0, sizeof(visited));

        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> d[j][k];
                if (d[j][k] == 'D') {
                    last_x = j;
                    last_y = k;
                } // boundary 넘어가면 탈출임
                if (d[j][k] == 'S') {
                    start_x = j;
                    start_y = k;
                }
                if (d[j][k] == '*') {
                    water_q.push(make_pair(j, k));
                    water[j][k] = 1;

                }
            }
        }
        bfs2();
        bbfs();
        /*
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cout << water[j][k];
            }
            cout << endl;
        }

        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cout << visited[j][k];
            }
            cout << endl;
        }*/
        


        //cout << "result" << result << endl;
        if (check == 1) cout << visited[last_x][last_y]-1 << endl;
        else cout << "KAKTUS" << endl;

}
