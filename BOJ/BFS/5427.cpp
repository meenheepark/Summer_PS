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
문제번호 : 5427
문제설명 :
*/
int t, w, h;
char d[1001][1001]; // 지도
int fire[1001][1001]; // 불 번지는시간구하기
int visited[1001][1001]; //상근이가지나가는 시간 구하기
int start_x, start_y;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int check = 0;
int last_x, last_y;

void bfs2(int x2, int y2) { // 불을 위한 함수
    queue < pair<int, int>> q;
    q.push(make_pair(x2, y2));
    fire[x2][y2] = 1; // 0인걸로 체크하는거랑 비교가 안대서 1로 설정하고 나중에 빼준다

    while (!q.empty()) {
        int x = q.front().first; // 행
        int y = q.front().second; // 열
        q.pop();
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < h && ry >= 0 && ry < w) {
                if (fire[rx][ry] == 0 && d[rx][ry] != '#') { // 벽이아니면 나간다.
                    fire[rx][ry] = fire[x][y] + 1;
                    q.push(make_pair(rx, ry));
                }
            }
        }
    }
}

void bbfs() {
    queue <pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = 1; // 0인걸로 체크하는거랑 비교가 안대서 1로 설정하고 나중에 빼준다

    while (!q.empty()) {
        
        int x = q.front().first; // 행
        int y = q.front().second; // 열
;
        q.pop();
        for (int i = 0; i < 4; i++) { // 동서남북
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= h || ry >= w || ry <0  || rx < 0) { // 밖으로 나갔다.
               
                check = 1;
                last_x = x;
                last_y = y;
                return;
            }
            if (rx >= 0 && rx < h && ry >= 0 && ry < w) { 
                if (visited[rx][ry] == 0 && d[rx][ry] != '#') { // 벽이아니면 나간다.
                    if (fire[rx][ry] > visited[x][y] + 1 || fire[rx][ry] == 0) { // 불보다 빨리간다.
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
    cin >> t;
    for (int i = 0; i < t; i++) {
        check = 0;
        memset(fire, 0, sizeof(fire));
        memset(visited, 0, sizeof(visited));

        cin >> w >> h;
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                cin >> d[j][k];
                if (d[j][k] == '@') {
                    start_x = j;
                    start_y = k;
                } // boundary 넘어가면 탈출임
            }
        }
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (d[j][k] == '*') bfs2(j, k);
            }
        }

        bbfs();

        /*for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                cout << fire[j][k];
            }
            cout << endl;
        }

        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                cout << visited[j][k];
            }
            cout << endl;
        }
        */


        //cout << "result" << result << endl;
        if (check == 1) cout << visited[last_x][last_y] << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

}
