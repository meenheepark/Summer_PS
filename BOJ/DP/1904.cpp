#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 1904
문제 이름 : 01타일
문제 설명 :  0이 두개씩 00, 1을 한개도가능. 길이 n인모든 수열긔 갯수를 15746으로 나눈 나머지
*/
int n;
long long dp[1000001][2];
int main()
{
	cin >> n;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 2][1] + dp[i - 2][0]) % 15746;
		dp[i][1] = (dp[i - 1][1] + dp[i-1][0])%15746;
	}
	cout << (dp[n][0] + dp[n][1]) % 15746;
}
/*

*/

