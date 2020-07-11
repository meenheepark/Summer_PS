#include <iostream>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2294
문제 이름 : 동전 2
문제 설명 :  그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.
*/
int n, k;
int coin[101];
int dp[101][10001];
int IMPOSSIBLE = 1000000000;

int check(int idx, int sum) {
	if (idx == n) {
		if (sum == 0) return 0; // 아무것도안더했다
		else return IMPOSSIBLE; // 아니면 불가능하다.
	}
	if (dp[idx][sum] != -1) return dp[idx][sum]; // 이미계산했음.
	int r = check(idx+1, sum); // 안더하고 다음코인봄.
	if (sum >= coin[idx]) { // 이조건이면 
		r = min(r, check(idx, sum-coin[idx]) + 1); // 코인을 더 더할지 말지. 작은값으로.
	}
	dp[idx][sum] = r;
	return r;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}

	int result = check(0, k);
	if (result == IMPOSSIBLE) result = -1;
	cout << result;
}
/*

*/

