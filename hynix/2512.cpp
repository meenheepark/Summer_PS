#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, ans = 0;
int d[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int e = 0; // 초;데
	int s = 0; // 최소
	for (int i = 0; i < N; i++) {
		cin >> d[i];
		e = max(e, d[i]);
	}
	cin >> M;
	int cnt = 0;
	while (e - s >= 0) {
		int mid = (e + s) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (d[i] >= mid) sum += mid;
			else sum += d[i];
		}
		if (sum > M) {
			e = mid-1;
		}
		else if (sum <= M) {
			ans =mid;
			s = mid+1;
		}
	}

	cout << ans << endl;
}
