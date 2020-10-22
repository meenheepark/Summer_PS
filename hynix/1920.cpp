#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[100001];

void solution(int k) {
	int start = 0;
	int end = N - 1;
	int mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (a[mid] == k) {
			cout << 1 << "\n";
			return;
		}
		else if (a[mid] > k) {
			end = mid - 1;
		}
		else if (a[mid] < k) {
			start = mid + 1;
		}
	}
	cout << 0 << "\n";
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		a[i] = k;
	}
	sort(a, a+N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int k;
		cin >> k;
		solution(k);
	}
	
}
