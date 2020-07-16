#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 11051
문제 이름 : 이항계수 2
문제 설명 :  n! / (n-k)! * k!
점화식 - dp[n][r] = dp[n-1][r-1]+dp[n-1][r] 

*/
#define MOD 10007;

int n, k;
long long dp[1001][1001]; // 팩토리얼 값 저장.

int check(int n, int r) {
	if (r == 1) {
		dp[n][r] = n;
		return dp[n][r];
	}
	if (n == r) {
		dp[n][r] = 1;
		return 1;
	}
	if (dp[n][r] != -1) return dp[n][r];
	dp[n][r] = (check(n - 1, r - 1) + check(n - 1, r)) % MOD;
	return dp[n][r];
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}
	cout << check(n,k);

}
/*

*/

