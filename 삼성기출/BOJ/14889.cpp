#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

/*
백준
문제번호 : 14889
문제설명 : 축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소
순열, 조합.
선수를 뽑아서 이분의 엔이 되면계산시작.
*/
int N;
int d[21][21];
int check[21]; // 스타트팀과 링크팀 나누기.

int result = 987654321; // 최소를 구하기 위해서

void dfs(int idx, int cnt) {

    if (cnt == N / 2) { // 사람 수 찼으면 계산하기.
        vector <int> start, link;
        for (int i = 0; i < N; i++) {
            if (check[i] == 0) { // 스타트팀
                start.push_back(i);
            }
            else link.push_back(i);
        }
        int s_sum = 0;
        int l_sum = 0;
    
        for (int i = 0; i < N / 2; i++) {
            for (int j = i + 1; j < N / 2; j++) {
                int start_i = start[i];
                int start_j = start[j];
                int link_i = link[i];
                int link_j = link[j];
                s_sum += d[start_i][start_j] + d[start_j][start_i];
                l_sum += d[link_i][link_j] + d[link_j][link_i];
            }
        }
        result = min(result, abs(s_sum - l_sum));
        return;
    }



    for (int i = idx + 1; i < N; i++) {
        if (check[i] == 0) {
            check[i] = 1;
            dfs(i, cnt + 1);
            check[i] = 0; // 백트래킹..선택을 하고 안하고 하고 안하고 반복
        }

    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> d[i][j]; //Sij
        }
    }

    dfs(0, 0);
    cout << result << endl;
 // N/2명
}
