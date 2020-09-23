#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2117 홈 방범 서비스
손해를 보지 않으면서 홈방범 서비스를 가장 많은 집들에 제공하는 서비스 영역을 찾고,

그 때의 홈방범 서비스를 제공 받는 집들의 수를 출력하는 프로그램을 작성하라.


*/

int answer = 0;
int N, M;
vector <pair <int, int>> h;
int d[21][21];
int visited[21][21];

int check(int cnt, int k) {
    int ans = k * k + (k - 1)*(k - 1);
    ans = M * cnt-ans;
    return ans;
}


void solution(int x, int y) { //x,y가 중심이고 거기서 k를 늘려가면서 이익 구하기.
    for (int k = 1; k < N + 2; k++) {
        //n+1까지 해야함 왜냐면 k=n일때 n-1거리 내의 모든점임

        int cnt = 0;
        for (int i = 0; i < N; i++) { // 거리내 모든점구하기
            for (int j = 0; j < N; j++) {
                int rx = abs(x - i);
                int ry = abs(y - j);

                if (rx + ry < k && d[i][j] == 1) cnt++;
            }
        }

        int ans = check(cnt, k);
        if (ans >= 0) {
            answer = max(answer, cnt);
        }
    }
}

int main()
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {   
        answer = 0;
        memset(d, 0, sizeof(d));

        cin >> N >> M;
        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < N ; j++) {
                cin >> d[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) { // 중심이 i, j에 있다고 생각하고 한다.
                solution(i, j);
            }
        }
         
           
            
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
