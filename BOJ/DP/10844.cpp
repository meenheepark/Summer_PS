#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
/*
백준
문제 번호 : 10844
문제 이름 : 쉬운 계단 수
문제 설명 :  점화식 dp[l][i] = dp[l-1][i-1]+dp[l-1][i+1]
*/

int n,k;
long long dp[101][10]; // 열은 마지막 수를 나타내기 위함.
int main()
{
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = 0;
			if (j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			if (j + 1 <= 9) {
				dp[i][j] += dp[i - 1][j + 1]; // 한자릿수씩 늘려나가기
			}
			dp[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i <= 9; i++) {
		sum+=dp[n][i];
	}
	cout << sum % 1000000000;

}
/*

*/

