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
문제번호 : 16397
문제설명 :
*/
int N, T, G;
int visited[100001];
int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,2,1,-2,-1 };
int check = 0;

int start_x, start_y, last_x, last_y;

void bfs() {
    queue <int> q; // 마지막은 벽 수
    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
       
        int x = q.front(); // 새로운 N
        q.pop();
        if (x == G && visited[x] <= T) {
            check = 1;
            return;
        }
        if (visited[x] > T) return;

        for (int i = 0; i < 2; i++) { 
            int rx;
            if (i == 0) rx = x + 1; // 버튼 1
            else if (i == 1) {
                rx = x * 2;
                if (rx > 99999) continue;
                int t = rx;
                int k = 1;
                while (t != 0) {
                    t = t / 10;
                    k = k * 10;
                } // 0이아닌 맨 윗자릿수 나옴
                
                k /= 10;
                rx -= k;

               
            }
            
            if (rx >= 0 && rx < 100000) {  //cout << rx << endl;// 벽은 방문할수가없다 
                if (visited[rx] == 0) { 
                    visited[rx] = visited[x] + 1;
                    q.push(rx);
                }
           }
           
        }
    }
}

int main()
{
    cin >> N >> T >> G; // 시작, t회, g와같게
    memset(visited, 0, sizeof(visited));
    bfs();
    if (check == 0) cout << "ANG" << endl;
    else   cout << visited[G] << endl;
}
