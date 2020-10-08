#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

//dfs혹은 완탐.

int T, N;
int ans; // 최대 억이어서
int cal[4];
int num[13];
long long max_num = -987654321;
long long min_num = 987654321;

void dfs(int idx, int cal[4], long long result) {
	if (idx == N) {
		//cout << "dd" << endl;
		max_num = max(max_num, result);
		min_num = min(min_num, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cal[i] != 0) {
			cal[i] -= 1;
			if (i == 0) { // +
				dfs(idx + 1, cal, result + num[idx]);
			}
			else if (i == 1) { // -
				dfs(idx + 1, cal, result - num[idx]);
			}
			else if (i == 2) { // *
				dfs(idx + 1, cal, result * num[idx]);
			}
			else { // /
				dfs(idx + 1, cal, result / num[idx]);
			}
			cal[i] += 1;
		}
	}
}

int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		ans = 0;
		max_num = -987654321;
		min_num = 987654321;
		
		for (int i = 0; i < 4; i++) {
			cin >> cal[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		dfs(1, cal, num[0]);
		ans = max_num - min_num;
		cout << "#" << test << " " << ans << endl;
	}
}
