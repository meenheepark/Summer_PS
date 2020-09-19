#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2115 벌꿀채취
완전탐색
옆으로 계속 가면서 C보다 작을때까지 한다.
가로로 연속되도록 M개의 벌통을 선택
*/


int d[11][11];
int visited[11][11];
int N, M, C, res;

void get_sum(int x, int y, int cnt, int sum_c, int sum_p) {
    if (sum_c > C) return;

    res = max(res, sum_p);
    if (cnt == M) return;

    get_sum(x, y + 1, cnt + 1, sum_c + d[x][y], sum_p + pow(d[x][y], 2)); // 더하고 넘어간다
    get_sum(x, y + 1, cnt + 1, sum_c, sum_p); // 안더하고 넘어간다
    
}

int solution(int x, int y) {
    for (int i = 0; i < M; i++) { // 1번이 간것들 다 방문했다고 한다.
        visited[x][y + i] = 1; // 방문했다고 표시
    }
    res = 0;
    get_sum(x, y, 0, 0, 0);
    int cost_a = res;
    int cost_b = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - M + 1; j++) {
            if (visited[i][j] == 0) {
                res = 0;
                get_sum(i, j, 0, 0, 0);
                cost_b = max(cost_b, res);
            }
        }
    }
    
    return (cost_a + cost_b);
}

int main()
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {   memset(visited, 0, sizeof(visited));
        cin >> N  >> M >> C;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> d[i][j];
            }
        }
        int answer = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - M + 1; j++) {
                answer = max(answer, solution(i, j));
            }
        }


        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
