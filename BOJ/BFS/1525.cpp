#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

/*
백준
문제번호 : 1525
문제설명 : 명령어를 어떻게 적어가야댈지 모르겠다.. 문자열 만든게 똑똑하다
*/
int check = 0;
int start_x, start_y;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int target = 123456789;


/*int bfs() { // 0이 2,2 에 가고, 정렬도 되어있으면 리턴.
    queue <pair<int[3][3], int>> q; // 마지막은 벽 수
    q.push(make_pair(d, 0));

    while (!q.empty()) {
        int x[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                x[i][j] = q.front().first[i][j];
            }
        }

        if (x == 2 && y == 2) {
            int k = 1;
            int result = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (d[i][j] != k) result = 1;
                    k++;
                }
            }
            if (result == 0) return cnt;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < 3 && ry >= 0 && ry < 3) {
                int tmp_x = d[rx][ry]
            }
        }
           
    }
}*/


int main()
{
    ios_base::sync_with_stdio(0);

    cin.tie(0);


    map<int, int> visited;
    int start = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            cin >> num;
            if (num == 0) num = 9;
            start = start * 10 + num;
        }
    }

    queue <int> q;
    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        string s = to_string(cur);
        q.pop();

        if (cur == target) break; // 찾음.
        
        int z = s.find('9'); // 9의 위치/
        int x = z / 3; // 행
        int y = z % 3; // 열
        for (int i = 0; i < 4; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx >= 0 && rx < 3 && ry >= 0 && ry < 3) {
                string tmp = s;
                swap(tmp[rx * 3 + ry], tmp[x * 3 + y]);
                
                int next = stoi(tmp); // 바꿔본 맵

                if (!visited[next]) {
                    q.push(next);
                    visited[next] = visited[cur] + 1;
                }
            }
        }

    }


    if (visited.count(target) == 0) cout << -1 << endl; // 여기 유의
    else cout << visited[target] << endl;
}
