#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2382
*/

struct person {
    int x;
    int y;
    int start_time;
    int end_time;
    int move_time;
    bool finish;
}; // 객체 생성...

struct stair {
    int x;
    int y;
    int s_len;
    int num;
};

int answer = 987654321;
person p[10];
stair s[2];
int p_num;
int N;
int d[11][11];
int Select[10]; // 사람마다 계단 선택하는 넘버 저장 배열

int cal(int p_idx, int s_idx) {
    int dx = abs(p[p_idx].x - s[s_idx].x);
    int dy = abs(p[p_idx].y - s[s_idx].y);
    return dx + dy + 1; // 거리 출력 1더해서.(대기시간)
}

void solution() {
    int time[2] = { 0,0 }; // 0번계단, 1번계단 숫자
    vector <int> v[2]; // 대기열. 원소는 사람 넘버
    
    for (int i = 0; i < p_num; i++) {
        int idx = Select[i];
        p[i].move_time = cal(i, idx);
        v[idx].push_back(p[i].move_time); // 계단에 들어온 사람들의소요 시간.
    }

    for (int i = 0; i < 2; i++) {
        if (v[i].size() == 0) continue;

        sort(v[i].begin(), v[i].end());
        time[i] = v[i][v[i].size() - 1]; // 가장긴시간.

        if(v[i].size() > 3) { // 세명까지만 올라가있을수있다.
            int idx = v[i].size() - 1; // 마지막원소
            time[i] = max(time[i] + s[i].s_len, v[i][idx-3] + s[i].s_len + s[i].s_len); // 마지막 원소가 그냥 간거거나, 세번째전꺼 끝날때까지 기다렸다가 간거거나
        }

        else {
            time[i] = s[i].s_len + time[i];
        }
        
    }
    int max_t = max(time[0], time[1]);
    answer = min(answer, max_t);
}

void dfs(int cnt) {
    if (cnt == p_num) {
        solution();
        return;
   }

    for (int i = 0; i < 2; i++) { // 중복을 고려하여 두가지 그룹으로 나눔 ㅁ모든경우의수
        Select[cnt] = i;
        dfs(cnt + 1);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        answer = 987654321;
        cin >> N;
        int s_idx = 0, p_idx = 0;
        memset(d, 0, sizeof(d));
        vector <pair<int, int>> r;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> d[i][j];
                //1이 사람 2부터는 계단위치
                if (d[i][j] > 1) { // 계단
                    s[s_idx].x = i;
                    s[s_idx].y = j;
                    s[s_idx].s_len = d[i][j];
                    s_idx++;
                }
                else if(d[i][j] == 1){ // 사람
                    p[p_idx].x = i;
                    p[p_idx].y = j;
                    p[p_idx].start_time = p[p_idx].move_time = p[p_idx].end_time = -1;
                    p[p_idx].finish = false;
                    p_idx++;
                }
            }
        }
        p_num = p_idx; // 사람 수
        
        dfs(0);
        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
