#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
long long M;
int A[10000];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int ans = 0;
	int l = 0, h = 0;
	int sum = 0;
	while (1) {
		if (sum >= M) sum -= A[l++];
		else if (h == N) break;
		else sum += A[h++];

		if (sum == M) ans++;
	}

	cout << ans << endl;
}
