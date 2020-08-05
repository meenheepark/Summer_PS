#include <iostream>

using namespace std;

/*
문제번호 : 4796
문제 설명: 
*/

int L, P, V;

int main() {
	int cnt = 1;
	while (1) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;
		int k = V; int sum = 0;
		while (k > 0) {
			if (k >= P) {
				k = k - P;
				sum += L;
			}
			else {
				if (L > k) {
					sum += k;
					k = k - P;
				}
				else if (L <= k) {
					sum += L;
					k = k - P;
				}
			}
		}
		cout << "Case " << cnt << ": " << sum << endl;
		cnt++;
	}
}