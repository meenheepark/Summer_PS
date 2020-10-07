#include <iostream>
#include <string.h>
using namespace std;

/*
문제 : 4014 활주로 건설
dfs라고 생각했는데 완전탐색이었음
경사로의 길이 x만큼을 놓았을 때 범위를 넘어가지 않는지 확인.
경사로를 놓아줄 x만큼의 칸의 높이가 같은지 확인.
경사로를 놓을 자리에 이미 경사로가 놓여있지 않은지 확인.
*/

int T;
int N, X;
int d[21][21]; 
bool check1[21][21];
bool check2[21][21];


int col() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true; // 해당 행이 되는 행인지검사
		for (int j = 0; j < N -1 ; j++) { // 모든 열 검사
			if (d[i][j] == d[i][j + 1]) continue;

			int tmp = abs(d[i][j] - d[i][j + 1]);
			if (tmp >= 2) {
				flag = false;
				break;
			}

			if (d[i][j] > d[i][j + 1]) { // 뒤로 경사로 둔다.
				if (j + X >= N) {
					flag = false;
					break;
				}

				for (int r = j + 1; r < j + X ; r++) { // X만큼
					if (d[i][r] != d[i][r+1]) { // 이미 경사로가 있으면/
						flag = false;
						break;
					}
				}

				for (int r = j + 1; r < j + X + 1; r++) { // X만큼
					if (check1[i][r]) { // 이미 경사로가 있으면/
						flag = false;
						break;
					}
				}

				if (flag) {
					for (int k = j + 1; k < j + X + 1; k++) {
						check1[i][k] = true;
					}
				}
			}
			else { // 뒤가 더 크면
				if (j + 1 - X < 0) {
					flag = false;
					break;
				}

				for (int k = j; k > j + 1 - X; k--) {
					if (d[i][k] != d[i][k-1]) {
						flag = false;
						break;
					}
				}

				for (int k = j; k > j - X; k--) {
					if (check1[i][k]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					for (int k = j; k > j - X - 1; k--) {
						check1[i][k] = true;
					}
				}

			}
			if (!flag) break;
		}
		if (flag) cnt++;
	}
	return cnt;
}

int row() {
	int cnt = 0;
	for (int j = 0; j < N; j++) {
		bool flag = true; // 해당 행이 되는 행인지검사
		for (int i = 0; i < N - 1; i++) { // 모든 열 검사
			if (d[i][j] == d[i+1][j]) continue;

			int tmp = abs(d[i][j] - d[i+1][j]);
			if (tmp >= 2) {
				flag = false;
				break;
			}

			if (d[i][j] > d[i + 1][j]) { // 뒤로 경사로 둔다.
				if (i + X >= N) {
					flag = false;
					break;
				}

				for (int r = i + 1; r < i + X; r++) { // X만큼
					if (d[r][j] != d[r+1][j]) { // 이미 경사로가 있으면/
						flag = false;
						break;
					}
				}

				for (int r = i + 1; r < i + X + 1; r++) { // X만큼
					if (check2[r][j]) { // 이미 경사로가 있으면/
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int k = i + 1; k < i + X + 1; k++) {
						check2[k][j] = true;
					}
				}
			}
			else { // 뒤가 더 크면
				if (i + 1 - X < 0) {
					flag = false;
					break;
				}

				for (int k = i; k > i + 1 - X; k--) {
					if (d[k][j] != d[k-1][j]) {
						flag = false;
						break;
					}
				}

				for (int k = i; k > i - X; k--) {
					if (check2[k][j]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					for (int k = i; k > i - X - 1; k--) {
						check2[k][j] = true;
					}
				}

			}
			if (!flag) break;
		}
		if (flag) cnt++;
	}
	return cnt;
}

int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case ++ ) {
		cin >> N >> X;
		memset(d, 0, sizeof(d));
		memset(check1, false, sizeof(check1));
		memset(check2, false, sizeof(check2));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> d[i][j];
			}
		}
		int ans = 0;
		ans = col() + row();

		cout << "#" << test_case << " " << ans << endl;
	}

}
