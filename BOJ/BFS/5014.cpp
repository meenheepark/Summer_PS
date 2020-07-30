#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
using namespace std;

/*
백준
문제번호 : 5014
문제설명 :
*/
int F, S, G, U, D; // s에서 g로감
int check[1000001];
int cnt = 0;
void bfs() {
    queue <int> q;
    q.push(S);
    check[S] = 1;

    while (!q.empty()) {
        int x = q.front();
        if (x == G) { cnt = 1; return; }
        q.pop();
            int rx = x + U;
            if (rx >= 1 && rx <= F) {
                if (check[rx] == 0) {
                    check[rx] = check[x] + 1;
                    q.push(rx);
                }
            }
            int ry = x - D;
            if (ry >= 1 && ry <= F) {
                if (check[ry] == 0) {
                    check[ry] = check[x] + 1;
                    q.push(ry);
                }
            }
    }
    cnt = -1;
}

int main()
{
    memset(check, 0, sizeof(check));
    cin >> F >> S >> G >> U >> D;
    bfs();
    if (cnt == -1) {
        cout << "use the stairs";
    }
    else cout << check[G]-1;

}
