#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 2294
문제 이름 : 동전 2...다시ㅠㅠ
문제 설명 :  
*/

int n,k;
long long dp[101][10001]; // [idx], [몇개] 써서 넘길지
int coin[101];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = 1000000000;
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i][0] = 0; // i번째 인덱스 부터시작
		for (int j = 0; j <= k; j++) {
			dp[i + 1][j] = min(dp[i+1][j], dp[i][j]); // i번째를 더하던가 안더하던가 미니멈을.
			int r = j + coin[i]; // 지금까지 sum값에 i번째 코인을 더한다.
			if (r <= k) dp[i][j] = min(dp[i][r], dp[i][j] + 1);
		}
	}

	if (dp[n - 1][k] == 1000000000) cout << -1 << endl;
	else cout << dp[n - 1][k] << endl;
}
/*

*/

