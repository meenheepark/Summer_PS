#include<iostream>
#include<queue>
#include<string.h>

using namespace std;
//dfs, 완탐..?

int N, W, H, ans;
int d[16][13];
int min_num = 987654321;

int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };


int check(int c[16][13]) {
    int num = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] > 0) {
                num++;
            }
        }
    }
    //cout << min_num;
    return num;
}

void move(int c[16][13]) {
    for (int i = 0; i < W; i++) {
        vector <int> v;
        for (int j = H - 1; j >= 0; j--) {
            if (c[j][i] != 0) {
                v.push_back(c[j][i]);
            }
        }
        for (int j = H - 1; j >= 0; j--) {
            c[j][i] = 0;
        }
        for (int j = 0; j < v.size(); j++) {
            c[H-1-j][i] = v[j];
        }
    }
}

int find_idx(int col, int c[16][13]) {
    int num = -1;
    
    for (int i = 0; i < H; i++) {
        if (c[i][col] > 0) {
            num = i;
            break;
        }
    }
    return num;
}

void dfs(int idx, int cnt, int c[16][13]) {
    int num = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] > 0) num++;
        }
    }
    if (num == 0 ) {
        min_num = 0;
        return;
    }
    if (cnt == N) {
        int num = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (c[i][j] > 0) num++;
            }
        }
        min_num = min(min_num, num);
        return;
    }
    
    int tmp[16][13];
    bool visited[16][13];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            tmp[i][j] = c[i][j];
        }
    }
    // 복사해서 써야하는 이유???

    int k = find_idx(idx, tmp); // 맨 위 벽돌 찾기

    if (k >= 0) { // 깰게 있다면
        if (tmp[k][idx] == 1) {
            tmp[k][idx] = 0; // 하나만 깨면 됨.
        }
        else { // 범위가 1 이상.
            //bfs로 깬다.
            queue <pair<int, int>> q;
            q.push({ k, idx });
            visited[k][idx] = true;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                int r = tmp[x][y];
                tmp[x][y] = 0;
                for (int i = 0; i < 4; i++) {
                    int rx = x;
                    int ry = y;
                    for (int j = 1; j <= r - 1; j++) { // r-1번 동서남북
                        rx += dx[i];
                        ry += dy[i];
                        if (rx < 0 || ry < 0 || rx >= H || ry >= W)continue;
                        if (tmp[rx][ry] > 1 && !visited[rx][ry]) {
                            visited[rx][ry] = true;
                            q.push({ rx, ry });
                        }
                        else if (tmp[rx][ry] == 1 && !visited[rx][ry]) {
                            visited[rx][ry] = true;
                            tmp[rx][ry] = 0;
                        }
                    }
                }
            }

            move(tmp);
        }

        for (int i = 0; i < W; i++) {
            dfs(i, cnt + 1, tmp);
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int ans = 0;
        cin >> N >> W >> H;
        min_num = 987654321;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> d[i][j];
            }
        }

        for (int j = 0; j < W; j++) {
            dfs(j, 0, d);
        }
        //n개의 구슬을 고르는 일.
        ans = min_num;
        cout << "#" << test_case << " " << ans << endl;
    }

}
