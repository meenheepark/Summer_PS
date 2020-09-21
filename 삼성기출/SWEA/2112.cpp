#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2112 보호 필름
최소로 바꾼 값.
1번씩 행 다바꿔보고 
2번씩 행 다바꿔보고 3번씩 행 다바꿔보고.
13C1~~13C13까지 더하기
완전탐색

*/

int answer = 15;
int D, W, K;
int d[14][21];
int c[14][21]; // copy용

bool check() {
    int b_cnt;

    for (int i = 0; i < W; i++) {
            b_cnt = 1;
            for (int j = 0; j < D-1; j++) {
                if (b_cnt >= K) break;
                if ( c[j][i] == c[j + 1][i]) {
                    b_cnt++;
                }
                else {
                    b_cnt = 1;
                }
            }
            if (b_cnt < K) {
                return false;
            }
    }
    return true;
}


void solution(int x, int k) {
    if (check() == true) {
        // 합격 기준에 맞다면.
        answer = min(answer, k);
        return;
    }
    
    if (x == D || k == K) {
        return;
    }

    //그 줄을 전부 0으로 바꿨더니 됐다 or
    // 전부 1로 바꿨더니 왰다.
    //안바꾼다.

    solution(x + 1, k); // 선택하지않거나
    
    for (int i = 0; i < W; i++) {
        c[x][i] = 0; // 백업
    }
    solution(x + 1, k + 1); // 1로 바꾸고 선택하거나
    
    for (int i = 0; i < W; i++) {
        c[x][i] = 1; // 백업
    }
    solution(x + 1, k + 1); // 1로 바꾸고 선택하거나
    
    for (int i = 0; i < W; i++) {
        c[x][i] = d[x][i]; // 백업
    }
    //return;
}

int main()
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {   
        answer = 15;
        memset(d, 0, sizeof(d));
        memset(c, 0, sizeof(c));

        cin >> D  >> W >> K;
        for (int i = 0; i < D ; i++) {
            for (int j = 0; j < W ; j++) {
                cin >> d[i][j];
            }
        }

            for (int i = 0; i < D; i++) {
                for (int j = 0; j < W; j++) {
                    c[i][j] = d[i][j];
                }
            }

            // 조합 구현하는 법..
            solution(0,0); // 0행, k개 뽑기.
         
           
            
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
