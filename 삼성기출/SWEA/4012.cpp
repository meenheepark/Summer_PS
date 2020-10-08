#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

//완전 탐색, 조합..N/2로 함 그 무슨 팀 그거같음.

int T, N;
int s[17][17];
int ans = 987654321;
int check[17];

void cal(vector <int> v) {
	memset(check, 0, sizeof(check));
	int sum1 = 0;
	int sum2 = 0;
	int a, b;
	//cout << v.size() << endl;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			a = v[i];
			 b = v[j];
			sum1 += s[a][b] + s[b][a];
			check[a] = 1;
			check[b] = 1;
		}
	}

	vector <int> v2;
	for (int i = 0; i < N; i++) {
		if (check[i] == 0) v2.push_back(i);
	}

	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			a = v2[i];
			b = v2[j];
			sum2 += s[a][b] + s[b][a];
		}
	}
	int cnt = abs(sum1 - sum2);
	ans = min(ans, cnt);

	//cout << "ddd" << endl;
	return;

}

void dfs(int idx, vector <int> v) {
	if (v.size() == N / 2) {
		cal(v);
		return;
	}
	if (idx == N) return;

	dfs(idx + 1, v); // 그냥보냄
	v.push_back(idx);
	dfs(idx + 1, v);
}

int main() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		ans = 987654321;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> s[i][j];
			}
		}
		vector <int> v;
		dfs(0, v);

		cout << "#" << test << " " << ans << endl;
	}
}
