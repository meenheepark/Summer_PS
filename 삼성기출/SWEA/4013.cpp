#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

//시뮬레이션

int T, K;
int d[5][8];


void change(int num, int dir) {
	int tmp[8];
	for (int i = 0; i < 8; i++) {
		tmp[i] = d[num][i];
	}
	if (dir == 1) { // 시계방향
		for (int i = 1; i < 8; i++) {
			d[num][i] = tmp[i - 1];
		}
		d[num][0] = tmp[7];
	}
	else { // 반시계방향
		for (int i = 0; i < 7; i++) {
			d[num][i] = tmp[i + 1];
		}
		d[num][7] = tmp[0];
	}
}

void turn(int num, int dir) {
	int t[5];
	for (int i = 1; i <= 4; i++) t[i] = 0;
	int n_dir;
	t[num] = dir;
	n_dir = dir;

	for (int i = num; i < 4; i++) {
		if (n_dir != 0 && d[i][2] != d[i + 1][6]) {
			if (n_dir == 1) n_dir = -1;
			else n_dir = 1;
			t[i + 1] = n_dir;
		}
		else if (d[i][2] == d[i + 1][6]) {
			n_dir = 0;
			t[i+1] = 0;
		}
	}

	n_dir = dir;

	for (int i = num; i >= 2; i--) {
		if (n_dir != 0 && d[i][6] != d[i - 1][2]) {
			if (n_dir == 1) n_dir = -1;
			else n_dir = 1;
			t[i - 1] = n_dir;
		}
		else if (d[i][6] == d[i - 1][2]) {
			n_dir = 0;
			t[i - 1] = 0;
		}
	}
	
	for (int i = 1; i <= 4; i++) {
		if (t[i] != 0) {
			change(i, t[i]);
			//cout << i << t[i] << endl;
		}
	}
}


int check() {
	int cnt = 0;
	 if (d[1][0] == 1) {
		cnt += 1;
	}
	 if (d[2][0] == 1) {
		 cnt += 2;
	 }
	 if (d[3][0] == 1) {
		 cnt += 4;
	 }
	 if (d[4][0] == 1) {
		 cnt += 8;
	 }
	return cnt;
}

int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> K;
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> d[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b; // 회전시킬 것 번호, 방향
			turn(a, b);
		}

		int ans = check();
		cout << "#" << test << " " << ans << endl;
	}
}
