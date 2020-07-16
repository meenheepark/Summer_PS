#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 11057
문제 이름 : 오르막 수
문제 설명 :  인접한 수, 다음수가 같거나 커야하는게 오르막수임. 길이가 주어졌을때 오르막수의 갯수구하기
점화식 - dp[i][j] = dp[i-1][j]+dp[i-1][j-1] .하나작은게아니라 더작은수..
*/
#define MOD 10007;

int n;
long long dp[1001][10]; // 열은 마지막 수를 나타내기 위함.
int main()
{
	cin >> n;
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0;
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= MOD;
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}
	cout << sum % MOD;

}
/*

*/

