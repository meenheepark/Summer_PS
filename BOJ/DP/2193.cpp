#include <iostream>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2193
문제 이름 : 이친수
문제 설명 :  long long선언이 관건
*/
int n;
long long dp[91][2]; // 자릿수 x 마지막수가 0또는 1
//90자릿수까지라서 인트범위를 넘어가므로..
int main()
{
	cin >> n;
	dp[1][1] = 1; // 한자릿수일땐 첫번째자리가 무조건 1.
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	cout << dp[n][0] + dp[n][1] << endl;

}
/*

*/

