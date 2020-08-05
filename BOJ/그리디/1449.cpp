#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제번호 : 4796
문제 설명: L은 L만큼만 커버가능.
*/

int N, L;
int d[1001];

int main() {
	cin >> N >> L;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	int cnt = 1; // 새로운 테이프인지아닌지.
	sort(v.begin(), v.end());
	int pre = v[0];
	for (int j = 1; j < v.size(); j++) {
		if (v[j] - pre >= L) { // 새테이프쓴다. 0.5가 남아있어야해서 같은것도해야댐
			cnt++; pre = v[j];
		}
	}
	cout << cnt << endl;
}