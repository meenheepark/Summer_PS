#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

/*
문제번호 : 11000
문제 설명: 최소의 강의실을 사용해서 모든 수업을 가능하게
끝나는 시간 순으로 정렬해서. 
*/

int N;
int start, en, t;
priority_queue <int, vector<int>, greater<int>> pq; // 오름차순이 그레이터
vector <pair<int, int>> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> en;
		v.push_back(make_pair(start, en)); // 이렇게입력...
	}
	sort(v.begin(), v.end());

	pq.push(v[0].second); // 수업의 끝나는 시간 넣음

	for (int i = 1; i < v.size(); i++) {
		if (pq.top() <= v[i].first) { // 들어갈만하다.
			pq.pop();
			pq.push(v[i].second);
		}
		else pq.push(v[i].second); // 다음은 여기. 얘가 더발리끝나니까. 새로운애면큐에 마지막이므로 팝이안된다.
	}
	
	cout << pq.size() << endl;
}