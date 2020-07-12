#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 9465
문제 이름 : 스티커..다시
문제 설명 :  
*/

int t, n;
long long dp[100001][3]; // 이전에서 하나도 안뗏거나 0, 위에떼거나 1, 아래떼거나 2
long long sti[2][100001];

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < 2; j++) {
			for (int r = 1; r <= n; r++)
				cin >> sti[j][r];
		}
		dp[1][0] = 0;
		dp[1][1] = sti[0][1];
		dp[1][2] = sti[1][1];
		for (int k = 2; k <= n; k++) {
			dp[k][1] = max(dp[k - 1][2] + sti[0][k], dp[k - 1][0] + sti[0][k]); // 이전에서 아래떼고 이번에 위뗌.
			dp[k][2] = max(dp[k - 1][1] + sti[1][k], dp[k - 1][0] + sti[1][k]); // 이전에서 위를 뗌 이번에 아래뗌
			dp[k][0] = max({dp[k - 1][1], dp[k - 1][2], dp[k - 1][0]});
		}

		cout << max({ dp[n][0], dp[n][1], dp[n][2] } )<< endl;
	}
}
/*

*/

