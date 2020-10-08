#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int T, N, X;
int d[21][21];
bool check1[21][21];
bool check2[21][21];

int row() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N - 1; j++) {
			int tmp = abs(d[i][j] - d[i][j + 1]);

			if (tmp == 0) {
				continue; // 같으면 넘어감
			}

			if (tmp > 1) {
				flag = false;
				break;
			}

			if (d[i][j] < d[i][j + 1]) {
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

				for (int k = j; k > j - X ; k--) {
					if (check1[i][k]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					for (int k = j; k > j - X ; k--) {
						check1[i][k] = true;
					}
				}

			}
			else {
				if (j + X >= N) {
					flag = false;
					break;
				}

				for (int k = j + 1; k < j + X; k++) {
					if (d[i][k] != d[i][k + 1]) {
						flag = false;
						break;
					}
				}

				for (int k = j + 1; k < j + X + 1; k++) {
					if (check1[i][k]) {
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
			if (!flag) break;
		}
		if (flag) cnt++;
	}
	return cnt;
}

int col() {
	int cnt = 0;
	for (int j = 0; j < N; j++) {
		bool flag = true;
		for (int i = 0; i < N - 1; i++) {
			int tmp = abs(d[i][j] - d[i+1][j]);

			if (tmp == 0) {
				continue; // 같으면 넘어감
			}

			if (tmp > 1) {
				flag = false;
				break;
			}

			if (d[i][j] < d[i+1][j]) {
				if (i +1 - X < 0) {
					flag = false;
					break;
				}

				for (int k = i; k > i + 1 - X; k--) {
					if (d[k][j] != d[k-1][j]) {
						flag = false;
						break;
					}
				}

				for (int k = i; k > i - X ; k--) {
					if (check2[k][j]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					for (int k = i; k > i - X ; k--) {
						check2[k][j] = true;
					}
				}

			}
			else {
				if (i + X >= N) {
					flag = false;
					break;
				}

				for (int k = i + 1; k < i + X; k++) {
					if (d[k][j] != d[k+1][j]) {
						flag = false;
						break;
					}
				}

				for (int k = i + 1; k < i + X + 1; k++) {
					if (check2[k][j]) {
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
			if (!flag) break;
		}
		if (flag) cnt++;
	}
	return cnt;
}


int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N >> X;
		memset(d, 0, sizeof(d));
		memset(check1, false, sizeof(check1));
		memset(check2, false, sizeof(check2));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> d[i][j];
			}
		}

		int ans = row() + col();
		cout << "#" << test << " " << ans << endl;
	}
}
