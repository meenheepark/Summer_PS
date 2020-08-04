#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#define _CRT_SECURE_NO_WARNINGS
#include <utility>
using namespace std;

/*
백준
문제번호 : 9019
문제설명 : 명령어를 어떻게 적어가야댈지 모르겠다.. 문자열 만든게 똑똑하다
*/
int A, B, T;
int check = 0;
int visited[10000]; // 여기에 명령어 번호를 적어둔다
int pre[10000]; // 이전에서 넘어온 숫자 번호
char d[10000];

string bfs() {
    queue <pair<int, string>> q; // 마지막은 벽 수
    q.push(make_pair(A, ""));
    visited[A] = 1;

    while (!q.empty()) {
       
        int x = q.front().first; // 새로운 N
        string ch = q.front().second;
        q.pop();

        if (x == B) return ch;
        
        int cur = (2 * x) % 10000;
        if (visited[cur] == 0) {
            visited[cur] = 1;
            q.push(make_pair(cur, ch + "D"));
        }

        cur = x - 1;
        if (x == 0) cur = 9999;
        if (visited[cur] == 0) {
            visited[cur] = 1;
            q.push(make_pair(cur, ch + "S"));
        }

        cur = (x % 1000) * 10 + x / 1000;
        if (visited[cur] == 0) {
            visited[cur] = 1;
            q.push(make_pair(cur, ch + "L"));
        }

        cur = (x % 10) * 1000 + x / 10;
        if (visited[cur] == 0) {
            visited[cur] = 1;
            q.push(make_pair(cur, ch + "R"));
        }
           
    }
}


int main()
{
    cin >> T; // 시작, t회, g와같게
    while (T--) {
        cin >> A >> B;
        memset(visited, 0, sizeof(visited));
        memset(pre, 0, sizeof(pre));
        cout << bfs() << endl;
        // B에서부터 A로 다시 되돌아가면서, 해당하는 명령어 역순으로 뽑기.
   
    }
}
