#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 3078
문제 이름 : 좋은친구
문제 설명 : 모든 학생은 자신과 반 등수의 차이가 K를 넘으면 친구가 아니라는거.
좋은 친구는 이름의 길이가 같아야 된다
좋은 친구가 몇 쌍이나 있는지 구하는 프로그램을 작성하시오. 좋은 친구는 등수의 차이가 K보다 작거나 같으면서 이름의 길이가 같은 친구이다.
*/

queue <int> q[21];
queue <int> aq;
long long n, k;

int main()
{
	cin >> n >> k;
	string s;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int len = s.size();
		while (!q[len].empty() && i - q[len].front() > k) { // 이전에들어온값인데 차이가 많이나면 필요없다.
			q[len].pop();
		}
		cnt += q[len].size();
		q[len].push(i);
	}
	cout << cnt;
}
/*

*/

