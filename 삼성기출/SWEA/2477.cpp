#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2477

접수 창구의 우선순위는 아래와 같다.

   ① 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로 우선 접수한다.
   ② 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로 간다.


정비 창구의 우선순위는 아래와 같다.

   ① 먼저 기다리는 고객이 우선한다.
   ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
   ③ 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.

*/

struct person {
    int a_num;
    int b_num;
    int time;
}; // 객체 생성...


int answer = -1;
person p[1001];
//접수
int n1[11]; // 접수처 이용가능 시간
int nm[11]; // 접수처 이용고객
int nt[11]; // 접수처별 시간
//정비
int m1[11];
int mm[11];
int mt[11];

int N, M, K, A, B;

queue <int> q1;
queue <int> q2;


void solution() {
    int t = 0; // 시작시간

    int out = 0;
    memset(n1, -1, sizeof(n1));
    memset(m1, -1, sizeof(m1));

    while (true) {
        for (int i = 1; i <= K; i++) {
            if (p[i].time == t) q1.push(i);
        }

        for (int i = 1; i <= N; i++) {
            if (n1[i] == t) {
                n1[i] = -1;
                q2.push(nm[i]); // 정비로 보낸다.
            }
        }

        for (int i = 1; i <= N; i++) {
            if (q1.empty()) break;
            if (n1[i] == -1) { // 비었다.
                n1[i] = t + nt[i];
                nm[i] = q1.front();
                p[q1.front()].a_num = i;
                q1.pop();
            }
        }

        for (int i = 1; i <= M; i++) {
            if (m1[i] == t) {
                m1[i] = -1;
                out++; // 내보내기
            }
        }

        for (int i = 1; i <= M; i++) {
            if (q2.empty()) break;
            if (m1[i] == -1) { // 비었다.
                m1[i] = t + mt[i];
                mm[i] = q2.front();
                p[q2.front()].b_num = i;
                q2.pop();
            }
        }

        if (out == K) break;
        t++; // 시간증가

    }
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> K >> A >> B;
        for (int i = 1; i <= N; i++) {
            cin >> nt[i];
        }
        for (int i = 1; i <= M; i++) {
            cin >> mt[i];
        }
        for (int i = 1; i <= K; i++) {
            cin >> p[i].time;
        }

        solution();

        int ans = 0;
        for (int i = 1; i <= K; i++) {
            if (p[i].a_num == A && p[i].b_num == B) {
                ans += i;
            }
        }
        if (ans == 0) answer = -1;
        else answer = ans;

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
