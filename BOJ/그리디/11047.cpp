#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제번호 : 11047
문제 설명: L은 L만큼만 커버가능.
*/

int N, K;

int main() {
	cin >> N >> K;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		int r;
		cin >> r;
		v.push_back(r);
	}
	int sum = 0;
	int cnt = 0;
	int idx = N - 1;
	//for (int i = 0; i < v.size(); i++) cout << v[i] << endl;
	while (1) {
		if (sum == K) break;
		if (v[idx] > K) {
			idx--;
			continue;
		}
		else if (v[idx] > K - sum) {
			idx--;
			continue;
		}
		else {
			//cout << v[idx] << endl;
			sum += v[idx];
			cnt++;
		}
	}
	cout << cnt << endl;
}