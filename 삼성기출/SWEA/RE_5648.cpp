#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
/*
그리고 원자들이 홀수만큼 떨어져 있다면, 격자 중간에서 충돌할 수도 있게 된다. 이는 배열상에서 표현하기 어려우므로 
아예 시공간을 2배로 늘려줘서 모든 충돌이 격자상에서 발생할 수 있도록 해준다.
*/
int N, M, K, ans;
int map[4001][4001];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct cell {
    bool live;
    int x, y;
    int dir;
    int k;
};

vector <cell> v;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        ans = 0;
        cin >> N; // a의 갯수는 8이하
        
        v.clear();
        //memset(map, 0, sizeof(map));

        for (int i = 0; i < N; i++) {
            int x, y, dir, k;
            cin >> x >> y >> dir >> k;
            int nx = x + 1000;
            int ny = y + 1000;
            v.push_back( { false, 2 * nx, 2 * ny , dir, k} ); // 홀수 처리를 위해 2배함.
        }
        while (1) {
            //다 죽었는지 검사
            bool finish = true;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].live == false) { // 살아있는지? 0 삶, 1 죽음
                    finish = false;
                    break;
                }
            }
            if (finish) break;

            for (int i = 0; i < v.size(); i++) {
                int rx = v[i].x + dx[v[i].dir];
                int ry = v[i].y + dy[v[i].dir];
                if (ry < 0 || rx < 0 || rx > 4000 || ry > 4000) {
                    //범위를 넘어간다면.
                    v[i].live = true;
                }
                else if (v[i].live == false) {
                    v[i].x = rx;
                    v[i].y = ry;
                    map[ry][rx] += 1;
                }
            }
            //충돌 검사.
            for (int i = 0; i < v.size(); i++) {
                if (map[v[i].y][v[i].x] > 1) {
                    for (int j = 0; j < v.size(); j++) {
                        if (v[j].live == false && v[j].y == v[i].y && v[j].x == v[i].x) {
                            v[j].live = true;
                            ans += v[j].k;
                        }
                    }
                }
                map[v[i].y][v[i].x] = 0;
            }

        }

        cout << "#" << test_case << " " << ans << endl;
    }

}
