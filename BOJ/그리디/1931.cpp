#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

/*
문제번호 : 1931
문제 설명: 이른시간순으로 정렬, 짧은순으로 정렬, 
아니다... 끝나는시간이 가장 빠른것부터 하면 됨.
*/

int N;
int start, en, t;
vector <pair<int, int>> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> en;
		v.push_back(make_pair(en, start)); // 이렇게입력...
	}
	sort(v.begin(), v.end());

	int cnt = 1;
	int pre = v[0].first;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second >= pre) {
			cnt++;
			pre = v[i].first;
		}
	}
	
	cout << cnt << endl;
}