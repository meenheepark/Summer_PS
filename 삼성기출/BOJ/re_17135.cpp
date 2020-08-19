#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
문제 번호 : 17135
문제 설명 : 
궁수 세명 배치
궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적이고, 
그러한 적이 여럿일 경우에는 가장 왼쪽에 있는 적을 공격
N+1번 행)의 모든 칸에는 성, 성이 있는 칸에 궁수 배치
궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산
bfs해서 적 만나면 바로 끝내기.? 시뮬레이션.

이 게임은 궁수의 위치가 중요하다 // 궁수의 위치는 브루트포스...뒤에것은 시뮬레이션
*/

int N, M, D;
int k[16][16];
int check[16][16];
int result = -1;


int cal(int r1, int c1, int r2, int c2) {
	int a, b;
	if (r1 - r2 >= 0) {
		a = r1 - r2;
	}
	else a = r2 - r1;

	if (c1 - c2 >= 0) {
		b = c1 - c2;
	}
	else b = c2 - c1;

	return (a + b); // 거리 반환하는 함수.
}

int attack(int a[]) {
	//맵부터 체크
	
	int sum = 0;
	while (1) {
		int re = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == 1) {
					re = 1;
				}
			}
		}
		if (re == 0){
			//cout <<"sum" <<sum << endl;
			return sum; // 최대 값을 리턴해야댈듯
		}
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << check[i][j];
			}
			cout << endl;
		}
		cout << endl;*/
		int x[3] = { -1,-1,-1 };
		int y[3] = {-1,-1,-1};

		for (int j = 0; j < 3; j++) { // 궁수 세명
			int o = 0;
			for (int i = N-1; i >= 0; i--) { // 공격하기
				for (int k = 0; k < M; k++) {
					int rx = i; // 행
					int ry = k; // 열
					if (check[rx][ry] == 1) { // 범위안에 있다면.
						if (cal(rx, ry, N, a[j]) <= D) {
							//cout << "공격" << cal(rx, ry, N, a[j]) << rx << ry << endl;
							// 공격함
							x[j] = rx;
							y[j] = ry;
							o = 1;
							break; // 다음궁수로. 다른 공격할 곳이 없으면 같은 곳 공격해야함
						}
					}
				}
				if (o == 1) break;
			}
		}

		for (int i = 0; i < 3; i++) { // 동시에 공격하기 위해서
			if (x[i] != -1) {
				if (check[x[i]][y[i]] == 1) {
					check[x[i]][y[i]] = 0;
					sum++;
				}
			}
		}

		//뒤에서부터 검사해서 한칸 내려오기
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (check[i][j] == 1) {
					check[i + 1][j] = 1;
					//check[i][j] = 0;
				}
				else check[i + 1][j] = 0;
			}
		}

	}
	// 궁수 배치.
	// 한번 공격, 없애기, 적 한칸 내려오기, 맵 검사했을때 다 0이면 리턴.
	// 0이 아니라면 다시 또 거리 계산해서 가장 가깝고 가장 왼쪽에있는것 공격, 없애기 내려오기...

}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> k[i][j];
			check[i][j] = k[i][j];
		}
	}
	int a[3] = { 0 };
	for (int i = 0; i < M-2; i++) {
		for (int j = i+1; j < M-1; j++) {
			for (int r = j+1; r < M; r++) { // 궁수 세명 배치 브루트포스
				a[0] = i; a[1] = j; a[2] = r;
				result = max(result, attack(a));
				
				for (int t = 0; t < N; t++) {
					for (int p = 0; p < M; p++) {
						check[t][p] = k[t][p]; //백업
					}
				}

			}
		}
	}

	cout << result << endl;
}

/*
5 5 3
1 1 1 0 1
0 1 1 0 0
1 1 1 0 0
0 1 1 0 0
1 1 1 0 0


13
*/