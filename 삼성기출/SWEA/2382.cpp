#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>

using namespace std;

/*
SWEA
문제번호 : 2382
bfs..왜냐면 동시간대니깐.
*/

int N, K, M;
vector <int> map[101][101]; 
int dx[] = { 0,-1,1,0,0 }; // 상하좌우
int dy[] = { 0,0,0,-1,1 };

struct Node {
    int x;
    int y;
    int num;
    int dir;
}; // 객체 생성...

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M >> K;
        
        vector <Node> v(K); // K개를 0으로 초기화
        for (int i = 0; i < K; i++) {
            cin >> v[i].x >> v[i].y >> v[i].num >> v[i].dir;
			map[v[i].x][v[i].y].push_back(i); // 군집 넘버
        }
        
        while(M--){ // M번해야되므로
            	for (int i = 0; i < K; i++) {
                    if (v[i].num == 0) continue;
                    map[v[i].x][v[i].y].clear(); // 맵초기화
                }

                // 군집 이동
                for (int i = 0; i < K; i++) {
                    if (v[i].num == 0) continue;
                    v[i].x += dx[v[i].dir];
                    v[i].y += dy[v[i].dir]; // 좌표옮김
                    map[v[i].x][v[i].y].push_back(i);
                }

                for (int i = 0; i < K; i++) {
                    if (v[i].num == 0) continue;

                    //가장자리에 닿은 경우
                    if (v[i].x == 0 || v[i].y == 0 || v[i].x == N - 1 || v[i].y == N - 1) {
                        v[i].num = v[i].num / 2; //미생물 1/2감소
                        //방향전환
                        if (v[i].dir == 1) v[i].dir = 2;
                        else if (v[i].dir == 2) v[i].dir = 1;
                        else if (v[i].dir == 3) v[i].dir = 4;
                        else v[i].dir = 3;
                    }
                    //여러 군집이 뭉친 경우
                    else if (map[v[i].x][v[i].y].size() > 1) {
                        int x = v[i].x;
                        int y = v[i].y;
                        int max_num = 0;
                        int max_cnt = 0;
                        int max_dir = 0;
                        int sum = 0;
                        for (int i = 0; i < map[x][y].size(); i++) {
                            sum += v[map[x][y][i]].num; // 미생물 수 합
                            // 최대 미생물을 가진 군집 찾기
                            if (max_num < v[map[x][y][i]].num) {
                                max_num = v[map[x][y][i]].num;
                                max_dir = v[map[x][y][i]].dir;
                                max_cnt = map[x][y][i];
                            }
                            v[map[x][y][i]].num = 0; // 없애기
                        }
                        v[max_cnt].num = sum;
                        v[max_cnt].dir = max_dir; // 방향바꾸기
                    }
                }
        	}
        int ans = 0;
        for(int i = 0 ; i < K ; i++) ans+= v[i].num;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j].clear();
            }
        }
        cout << "#" << test_case << " "<< ans << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}