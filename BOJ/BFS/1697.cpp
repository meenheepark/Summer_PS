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
문제번호 : 1697
문제설명 :
*/
int n,k;
int visited[100001];
int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,2,1,-2,-1 };
int check = 0;

int start_x, start_y, last_x, last_y;

void bfs() {
    queue <int> q; // 마지막은 벽 수
    q.push(n);
    visited[n] = 0;

    while (!q.empty()) {
       
        int x = q.front(); // 행
        q.pop();
        if (x == k) return;

        for (int i = 0; i < 3; i++) { // 동서남북
            int rx;
            if (i == 0) rx = x + 1;
            else if (i == 1) rx = x - 1;
            else rx = x * 2;
            
            if (rx >= 0 && rx <= 100000) { // 벽은 방문할수가없다 
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
    cin >> n >> k;
    memset(visited, 0, sizeof(visited));
    bfs();
    cout << visited[k] << endl;
}
