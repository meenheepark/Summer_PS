#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

/*
문제번호 : 2212
문제 설명:플러그를 빼는 횟수를 최소화
*/

int N, K;
vector <int> v;
int bet[10001];

int main() {
	cin >> N;
	cin >> K;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	
	int sum = 0;
	for (int j = 0; j < v.size()-1; j++) {
		bet[j] = v[j + 1] - v[j];
	}
	sort(bet, bet + N - 1, greater<int>()); // 내림차순 정렬
	
	for (int i = 0; i < K-1; i++) {
		bet[i] = 0;
	}

	for (int j = 0; j < v.size() - 1; j++) {
		sum+=bet[j];
	}
	
	cout << sum << endl;
}