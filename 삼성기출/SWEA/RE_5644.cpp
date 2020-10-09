#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[] = { 0, 0, 1, 0, -1 };
int dx[] = { 0, -1, 0, 1, 0 };

struct Battery {
    int y, x;
    int r, p;
};
vector<Battery> battery(10);
int ay = 1, ax = 1, by = 10, bx = 10;
int M, A;

void init() {
    ay = 1, ax = 1, by = 10, bx = 10;
}

int maxPower(vector<int> bat) {
    int now = 0;
    for (int i = 0; i < bat.size(); i++) {
        now = max(now, battery[bat[i]].p);
    }
    return now;
}

int solve(vector<int> a, vector<int> b) {
    if (a.size() == 0 && b.size() == 0) return 0;
    if (a.size() == 0) return maxPower(b);
    if (b.size() == 0) return maxPower(a);
    int now = 0;
    for (int i = 0; i < a.size(); ++i) {
        int Pa = battery[a[i]].p;
        for (int j = 0; j < b.size(); ++j) {
            int Pb = battery[b[j]].p;
            if (b[j] == a[i]) now = max(now, (Pa + Pb) / 2);
            else now = max(now, (Pa + Pb));
        }
    }
    return now;
}

int main(int argc, char** argv) {
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> M >> A;
        vector<int> pathA(M + 1);
        vector<int> pathB(M + 1);
        for (int i = 1; i <= M; i++) cin >> pathA[i];
        for (int i = 1; i <= M; i++) cin >> pathB[i];
        init();
        for (int i = 0; i < A; i++) {
            cin >> battery[i].y >> battery[i].x >> battery[i].r >> battery[i].p;
        }
        int ans = 0;
        for (int i = 0; i <= M; i++) {
            ay += dy[pathA[i]];
            ax += dx[pathA[i]];
            by += dy[pathB[i]];
            bx += dx[pathB[i]];
            vector<int> a, b;
            for (int cnt = 0; cnt < A; ++cnt) {
                if (abs(ay - battery[cnt].y) + abs(ax - battery[cnt].x) <= battery[cnt].r) a.push_back(cnt);
                if (abs(by - battery[cnt].y) + abs(bx - battery[cnt].x) <= battery[cnt].r) b.push_back(cnt);
            }
            int now = solve(a, b);
            ans += now; // 초마다 얼마인지 더함
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;
}
