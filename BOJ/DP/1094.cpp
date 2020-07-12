#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 1094
문제 이름 : 막대기
문제 설명 :  long long선언이 관건
*/
int x;
long long dp[91][2]; // 자릿수 x 마지막수가 0또는 1
//90자릿수까지라서 인트범위를 넘어가므로..
int main()
{
	cin >> x;
	vector<int> v;
	v.push_back(64);
	int cnt = 1;
	int mini = 64;
	int miniidx = 0;
	while (1) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
			if (v[i] < mini) {
				mini = v[i];
				miniidx = i;
			}
		} // 합 구하기
		if (sum > x) { // 잘라야한다.
			v[miniidx] = mini / 2;
			mini /= 2;
			if (sum - mini >= x) {
				sum -= mini;
			}
			else {
				v.push_back(mini);
				cnt++;
			}
		}
		else if (sum == x) break;
	}
	cout << cnt;

}
/*

*/

