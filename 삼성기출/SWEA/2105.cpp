#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2105 디저트카페
시뮬레이션, dfs?
//디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력
왓던방향으로 다시 돌아가면 안되고
*/


int answer;
int d[21][21];
int desert[101]; // 먹은 디저트 또먹지않으려고
int check[21][21]; // 갔던길 또가지않으려고
int N, s_x, s_y;
//대각선 방향으로 움직이고 사각형 모양을 그리며 출발한 카페로 돌아와야 한다.
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 }; // 대각선으로 가는 방법들

void solution(int dir, int x, int y, int cnt) {
    if (x == s_x && y == s_y && cnt > 1) {
        if (cnt > answer) answer = cnt;
        //else answer = answer;
        return;
    }
    for (int k = 0; k < 2; k++) {
        int rx = x + dx[dir+k]; // 같은방향이거나 방향꺾기.
        int ry = y + dy[dir+k];    

        if (rx >= 0 && rx < N && ry >= 0 && ry < N && check[rx][ry] == 0 && desert[d[rx][ry]] == 0) {
            check[rx][ry] = 1;
            desert[d[rx][ry]] = 1;
            solution(dir + k, rx, ry, cnt+1);
            check[rx][ry] = 0;
            desert[d[rx][ry]] = 0;
        }
        else if (rx == s_x && ry == s_y) { // 처음으로 돌아가려한다면.
            solution(dir + k, rx, ry, cnt + 1);
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
        answer = -1;
        cin >> N ;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> d[i][j];
        }
        memset(check, 0, sizeof(check)); // 초기화
        memset(desert, 0, sizeof(desert));
         // 여태 방문한 카페이름들
        for (int i = 0; i < N -1; i++) { //행
            for (int j = 1 ; j < N -1; j++) { //열
                s_x = i;
                s_y = j;
                desert[d[i][j]] = 1;
                check[i][j] = 1;
                solution(0, i, j, 0); // 시작방향, 인덱스 , 카운트
                memset(check, 0, sizeof(check)); // 초기화
                memset(desert, 0, sizeof(desert));
            } 
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
